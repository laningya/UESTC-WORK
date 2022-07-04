#ifndef DEVICE_H
#define DEVICE_H

#include <QHostAddress>
#include "QMainWindow"
#include "QLabel"
#include "QLineEdit"
#include "QPushButton"
#include "QFile"

//#include "QLineEdit"
//#include "QMainWindow"
//#include "show.h"

class Device : public QMainWindow
{
    Q_OBJECT

public:
    Device(QWidget *parent = nullptr);

    QString getName();
    QString getHostaddress();
    quint16 getPort();

    void setName(QString name);
    void setHostAddress(QString s1,QString s2,QString s3,QString s4);
    void setPort(QString port);

private:
    QString name;
    QHostAddress *hostaddress;
    quint16 port;

    QLineEdit* s1,* s2,* s3,* s4;      //输入框
    QLineEdit* nameEdit;
    QLineEdit* portEdit;
    QPushButton* pbOk;      //Enter
    QPushButton* pbBack;  //Cancel

    QLabel *devName;
    QLabel *devPort;
    QLabel *devIP;
private slots:
    //确定
    void slot_pressOkBtn();
    //取消
    void slot_pressCancelBtn();
};
#endif // DEVICE_H
