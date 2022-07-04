#include "device.h"
Device::Device(QWidget *parent)
    : QMainWindow(parent)
{
    this->parentWidget()->hide();
    //设置窗体标题
    this->setWindowTitle(tr("add new device!"));
    //设置窗口大小
    resize(400, 400);
    //创建输入框
    s1 = new QLineEdit(this);
    s2 = new QLineEdit(this);
    s3 = new QLineEdit(this);
    s4 = new QLineEdit(this);
    nameEdit = new QLineEdit(this);
    portEdit = new QLineEdit(this);
    devName = new QLabel(this);
    devPort = new QLabel(this);
    devIP = new QLabel(this);

    devName->setGeometry(90, 100, 80, 20);
    devPort->setGeometry(100, 150, 80, 20);
    devIP->setGeometry(50, 210, 80, 20);

    devName->setText("dev name:");
    devIP->setText("IP:");
    devPort->setText("port:");
    //设置输入框位置
    s1->setGeometry(100, 210, 40, 20);
    s2->setGeometry(160, 210, 40, 20);
    s3->setGeometry(220, 210, 40, 20);
    s4->setGeometry(280, 210, 40, 20);
    nameEdit->setGeometry(160,100,100,20);
    portEdit->setGeometry(160,150,100,20);

    pbOk = new QPushButton(this);
    pbBack = new QPushButton(this);

    //设置按钮位置
    pbOk->setGeometry(110, 300, 60, 50);
    pbBack->setGeometry(220, 300, 60, 50);

    //设置按钮文本
    pbOk->setText("add");
    pbBack->setText("back");

    //确定键
    connect(pbOk, &QPushButton::clicked, this, &Device::slot_pressOkBtn);
    //取消键
    connect(pbBack, &QPushButton::clicked, this, &Device::slot_pressCancelBtn);
}

QString Device::getName()
{
    return this->name;
}
QString Device::getHostaddress()
{
    return this->hostaddress->toString();
}
quint16 Device::getPort()
{
    return this->port;
}

void Device::setName(QString name)
{
    this->name = name;
}
void Device::setHostAddress(QString s1,QString s2,QString s3,QString s4)
{
    this->hostaddress = new QHostAddress(s1+"."+s2+"."+s3+"."+s4);
}
void Device::setPort(QString port)
{
    this->port = port.toUInt();
}

void Device::slot_pressOkBtn()
{
    setName(nameEdit->text());
    setPort(portEdit->text());
    setHostAddress(s1->text(),s2->text(),s3->text(),s4->text());

    QFile *file = new QFile("/home/wzh/device/" + name);
    file->open(QIODevice::WriteOnly);
    file->write(hostaddress->toString().toUtf8());
    file->write("\n");
    file->write(QString("%1").arg(port).toUtf8());
    file->close();

    this->hide();
    this->parentWidget()->show();
}

void Device::slot_pressCancelBtn()
{
    qDebug() << "dont save";
    this->parentWidget()->show();
    close();
}
