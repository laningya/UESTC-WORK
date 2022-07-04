#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"
#include "QPainter"
#include "QPen"
#include "QFileDialog"
#include "math.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    savecont=0;
    save_en=0;
    replay_en=0;
    replaycont=0;
    save_v=1;
    replay_v=20;

    lcd_width=320;
    lcd_height=240;
    lcd_rgb_bpp=24;

    camera_video_fmt="YUYV";
    camera_video_width=320;
    camera_video_height=240;
    camera_video_bpp=24;

    curdatetime  = QDateTime::currentDateTime();
    predatetime  = curdatetime;

    re_frame=0;

    camera_buff_rgb888=(uchar*)malloc(sizeof(char)*camera_video_width*camera_video_height*camera_video_bpp/8);
    camera_buff_raw=(uchar*)malloc(sizeof(char)*camera_video_width*camera_video_height*camera_video_bpp/8);
    frame_len=0;

    image = new  QImage(camera_buff_rgb888,camera_video_width,camera_video_height,QImage::Format_RGB888);

    pix=new QPixmap(ui->label->size());
    pix->fill(Qt::white);
    ui->label->setPixmap(*pix);

    re_pix=new QPixmap(ui->label->size());
    re_pix->fill(Qt::white);

    timer=new QTimer(this);
    timer->start(1);

    avi.setSavePath(QString("/tmp/"));

    cam_name="/dev/video0";
    cam_vd=new VideoDevice(cam_name.trimmed());

    cam_vd->open_device();
    cam_vd->init_device();

    cam_vd->start_capturing();

    ui->record->setEnabled(true);
    ui->stop->setEnabled(false);
    ui->replay->setEnabled(true);

    connect(cam_vd,&VideoDevice::display_error,this,[=](QString msg)
    {
        QMessageBox::critical(this,"ERROR",QString("camera error %1").arg(msg));
        cam_vd->close_device();
        exit(1);
    });



    /////////
    udpSocketSrv = new QUdpSocket(this);
    udpSocketSrv->bind(QHostAddress::Any,8888);
    connect(udpSocketSrv,&QUdpSocket::readyRead,this,[=]
    {
        ip = QHostAddress("0.0.0.0");
        port = 0;
        char rcvbuf[2048];
        qint64  rcv_len;
        rcv_len = udpSocketSrv->readDatagram(rcvbuf,sizeof(rcvbuf),&ip,&port);
        rcvbuf[rcv_len] = '\0';
        qDebug() << rcvbuf;
    });

    connect(timer,&QTimer::timeout,this,[=]
    {
        curdatetime=QDateTime::currentDateTime();
        cam_vd->get_frame((void**)&camera_buff_raw,(size_t*)&frame_len);
        yuyv422_to_rgb888(camera_buff_raw,camera_buff_rgb888,camera_video_width,camera_video_height);
        *image=QImage(camera_buff_rgb888,camera_video_width,camera_video_height,QImage::Format_RGB888);
        cam_vd->unget_frame();


        tmp_img = pix->toImage();
        img = &(tmp_img);
        QByteArray byte;
        QBuffer buff(&byte);
        buff.open(QIODevice::WriteOnly);
        img->save(&buff,"JPEG");
        byte = byte.toBase64();
//        qDebug() << byte;
        udpSocketSrv->writeDatagram(byte,ip,port);

        this->update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    *pix=QPixmap::fromImage(*image,Qt::AutoColor);
    QPainter painter(pix);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    if(curdatetime > predatetime)
    {
        fps = 1000/predatetime.msecsTo(curdatetime);
        predatetime  = curdatetime;
    }
    painter.drawText(180,20,QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    painter.drawText(20,20,QString("fps is:%1").arg(fps));
    if(!replay_en)
    {
        ui->label->setPixmap(*pix);
        if(save_en)
            avi.write(*pix);
    }
    else
    {
        if(abs(re_frame-ui->horizontalSlider->value())>3)
            re_frame=ui->horizontalSlider->value();
        *re_pix=re_avi.read(re_frame);
        ui->label->setPixmap(*re_pix);
        re_frame+=ui->horizontalSlider_2->value()/10.0;
        ui->horizontalSlider->setSliderPosition(re_frame);
    }
}

void Widget::yuyv422_to_rgb888(unsigned char *yuyvdata, unsigned char *rgbdata, int w, int h)
{
    //码流Y0 U0 Y1 V1 Y2 U2 Y3 V3 --》YUYV像素[Y0 U0 V1] [Y1 U0 V1] [Y2 U2 V3] [Y3 U2 V3]--》RGB像素
    int r1, g1, b1;
    int r2, g2, b2;
    int i;

    for(i=0; i<w*h/2; i++)
    {
        char data[4];
        memcpy(data, yuyvdata+i*4, 4);
        unsigned char Y0=data[0];
        unsigned char U0=data[1];
        unsigned char Y1=data[2];
        unsigned char V1=data[3];

        r1 = Y0+1.4075*(V1-128);
        if(r1>255) r1=255;
        if(r1<0)   r1=0;

        g1 =Y0- 0.3455 * (U0-128) - 0.7169*(V1-128);
        if(g1>255)  g1=255;
        if(g1<0)    g1=0;

        b1 = Y0 + 1.779 * (U0-128);
        if(b1>255)  b1=255;
        if(b1<0)    b1=0;

        r2 = Y1+1.4075*(V1-128);
        if(r2>255)  r2=255;
        if(r2<0)    r2=0;

        g2 = Y1- 0.3455 * (U0-128) - 0.7169*(V1-128);
        if(g2>255)    g2=255;
        if(g2<0)      g2=0;

        b2 = Y1 + 1.779 * (U0-128);
        if(b2>255)    b2=255;
        if(b2<0)      b2=0;

        rgbdata[i*6+0]=r1;
        rgbdata[i*6+1]=g1;
        rgbdata[i*6+2]=b1;
        rgbdata[i*6+3]=r2;
        rgbdata[i*6+4]=g2;
        rgbdata[i*6+5]=b2;
    }
}

void Widget::on_record_clicked()
{
    save_en=1;

    avi.setFileName(QString(QDateTime::currentDateTime().toString("yyyy-MM-dd-hh:mm:ss")+".avi"));
    avi.setMode(320,240,25,100,"mjpg");

    ui->record->setEnabled(false);
    ui->stop->setEnabled(true);
    ui->replay->setEnabled(false);
}

void Widget::on_stop_clicked()
{
    if(save_en)
    {
        save_en=0;
        avi.stopwrite();
    }
    else
    {
        replay_en=0;
        re_avi.close();
        ui->horizontalSlider->setSliderPosition(0);
    }
    ui->record->setEnabled(true);
    ui->stop->setEnabled(false);
    ui->replay->setEnabled(true);
}

void Widget::on_replay_clicked()
{
    QString s=QFileDialog::getOpenFileName(this,tr("choose file"),"/tmp/","video file(*.avi)",0,QFileDialog::DontUseNativeDialog);
    qDebug()<<s;
    re_avi.open(s.toUtf8().data());
    ui->horizontalSlider->setRange(0,re_avi.frames-1);
    ui->horizontalSlider->setSliderPosition(0);
    re_frame=0;
    replay_en=1;
    ui->record->setEnabled(false);
    ui->stop->setEnabled(true);
    ui->replay->setEnabled(false);
}

void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_2->setText(QString("speed:x%1").arg(value/10.0));
}
