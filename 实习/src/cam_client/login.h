#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QMovie>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QLabel>
#include "show.h"


/*
 * 登录主界面
 */
class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private Q_SLOTS:
    //确定
    void slot_pressOkBtn();
    //取消
    void slot_pressCancelBtn();

protected:
    //virtual void accept();
    void keyPressEvent(QKeyEvent*event);

private:
    //初始化Login
    void InitLogin();
    //初始化事件
    void InitLoginEvent();

private:
    QLineEdit* m_edit;      //输入框
    QPushButton* m_ok;      //Enter
    QPushButton* m_cancel;  //Cancel
    QPushButton* m_delete;  //Delete
    QLabel*m_user;          //User
    QLabel*m_gif;           //GIFposition
    QMovie*movie;           //gif
    Show *showWidget;
};
#endif // LOGIN_H
