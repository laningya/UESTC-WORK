#include "show.h"
#include "ui_show.h"

Show::Show(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Show)
{
    ui->setupUi(this);
    // 搜索设备

    QDir *dir = new QDir("/home/wzh/device/");
    QStringList filters;
    //用链表保存过滤的文件名
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filters));

    //获取文件数目、文件名称
    for(int i = 0; i < fileInfo->count(); i++)
    {
        if(fileInfo->at(i).fileName().compare(".") == 0) continue;
        if(fileInfo->at(i).fileName().compare("..") == 0) continue;
        ui->comboBox->addItem(fileInfo->at(i).fileName());
    }
}

// 选择设备
void Show::on_comboBox_activated(const QString &arg1)
{
    QFile file("/home/wzh/device/" + arg1);
    qDebug() << file.fileName();
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    udpSocketSrv = new QUdpSocket(this);
    QString st = in.readLine();
    qDebug() << st;
    hostaddress = QHostAddress(st);
    QString temp = in.readLine();
    qDebug() << temp;
    port = temp.toInt();

    qDebug() << "read:" << hostaddress;
    qDebug() << "read:" << port;

    QString MyData="hello udpsocket";
    udpSocketSrv->writeDatagram(MyData.toUtf8(),hostaddress,port);
    connect(udpSocketSrv,&QUdpSocket::readyRead,this,[=]
    {
        QByteArray datagram;
        qDebug() << "receive";
        datagram.resize(udpSocketSrv->pendingDatagramSize());
        udpSocketSrv->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        QByteArray imageData = QByteArray::fromBase64(msg.toLatin1());
        QImage image;
        image.loadFromData(imageData);
        QPixmap pix =  QPixmap::fromImage(image);
        ui->label->setPixmap(pix);
    });
}

// 添加设备
void Show::on_pbAdd_clicked()
{
    Device *newdev = new Device(this);
    newdev->show();
}

// 删除设备
void Show::on_pbDel_clicked()
{
    QFile file("/home/wzh/device/" + ui->comboBox->currentText());
    qDebug() << file.fileName();
    file.remove();
    qDebug() << "close";
    this->udpSocketSrv->close();
    refreshComboBox();
}

// 返回
void Show::on_pbBack_clicked()
{
    emit this->back();
}

// 更改设备目录
void Show::changeComboBox(QString name)
{
    ui->comboBox->addItem(name);
}
void Show::refreshComboBox()
{
    QDir *dir = new QDir("/home/wzh/device/");
    QStringList filters;
    //用链表保存过滤的文件名
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filters));

    QString temp = ui->comboBox->currentText();

    int tempNum = ui->comboBox->count();
    for(;tempNum > 0;tempNum --)
    {
        ui->comboBox->removeItem(tempNum);
    }

    //获取文件数目、文件名称
    for(int i = 0; i < fileInfo->count(); i++)
    {
        if(fileInfo->at(i).fileName().compare(".") == 0) continue;
        if(fileInfo->at(i).fileName().compare("..") == 0) continue;
        ui->comboBox->addItem(fileInfo->at(i).fileName());
    }
    ui->comboBox->setCurrentText(temp);
}
// 删除
Show::~Show()
{
    delete ui;
}

void Show::on_pushButton_clicked()
{
    refreshComboBox();
}
