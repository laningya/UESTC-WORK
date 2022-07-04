#ifndef SHOW_H
#define SHOW_H

#include <QWidget>
#include <QUdpSocket>
#include <QHostAddress>
#include <QMessageBox>

#include "device.h"
#include "QFile"
#include "QIODevice"
#include <QTextStream>
#include "QDir"

QT_BEGIN_NAMESPACE
namespace Ui { class Show; }
QT_END_NAMESPACE

class Show : public QWidget
{
    Q_OBJECT

public:
    Show(QWidget *parent = nullptr);
    ~Show();

private:
    Ui::Show *ui;
    QUdpSocket *udpSocketSrv;
    QHostAddress hostaddress;
    quint16 port;
    void changeComboBox(QString name);
    void refreshComboBox();
signals:
    void back();
private slots:
    void on_pbBack_clicked();
    void on_comboBox_activated(const QString &arg1);
    void on_pbAdd_clicked();
    void on_pbDel_clicked();
    void on_pushButton_clicked();
};
#endif // SHOW_H
