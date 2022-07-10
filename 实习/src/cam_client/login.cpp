#include "login.h"
#include <QMessageBox>
Login::Login(QWidget *parent)
    : QMainWindow(parent)
{
    //设置窗体标题
    this->setWindowTitle(tr("Welcome!"));
    //初始化控件
    InitLogin();
    //初始化事件
    InitLoginEvent();
}

void Login::InitLogin()
{
    //设置窗口大小
    resize(400, 400);

    //GIF
    movie=new QMovie(":/gif/login.gif");

    m_gif=new QLabel(this);
    m_gif->setGeometry(0,0,400,400);
    m_gif->setMovie(movie);
    m_gif->setScaledContents(true);

    movie->start();

    //创建输入框
    m_edit = new QLineEdit(this);
    //设置输入框位置
    m_edit->setGeometry(170, 210, 160, 20);
    //设置输入框内容
    m_edit->setPlaceholderText("Enter your password!");
    QFont font1("Microsoft YaHei", 10, 75);
    m_edit->setFont(font1);
    //设置输入框输入的密码以圆点显示
    m_edit->setEchoMode(QLineEdit::Password);
    //设置输入框限制
    m_edit->setMaxLength(7);
    //设置输入框样式
    m_edit->setStyleSheet("QLineEdit{ background-color: rgb(255,240,255); } QLineEdit:focus{background-color: rgb(255,255,255)}"); // 设置样式

    QLabel* label = new QLabel(this);
    label->setGeometry(100, 210, 80, 20);
    QFont font2("Microsoft YaHei", 10, 75);
    label->setFont(font2);
    label->setText("Password:");

    //User
    m_user=new QLabel(this);
    m_user->setGeometry(100,180,140,20);
    m_user->setFont(font2);
    m_user->setText("User:Admin");

    //创建按钮
    m_ok = new QPushButton(this);
    m_cancel = new QPushButton(this);

    //设置按钮样式
    QString style_btn = "QPushButton {"
                            "background: #4395ff; "
                            "border-radius: 5px;"
                            "margin: 5px;"
                            "font-size: 16px; "
                            "color: white;"
                            "}"
                        "QPushButton:pressed { "
                            "background: #01ddfd "
                            "}";

    QString style_btn2 = "QPushButton {"
                            "background: #3335af; "
                            "border-radius: 3px;"
                            "margin: 5px;"
                            "font-size: 20px; "
                            "color: white;"
                            "}"
                        "QPushButton:pressed { "
                            "background: #01addd "
                            "}";

    m_ok->setStyleSheet(style_btn);
    m_cancel->setStyleSheet(style_btn);

    //设置按钮位置
    m_ok->setGeometry(110, 240, 80, 50);
    m_cancel->setGeometry(220, 240, 80, 50);

    //设置按钮文本
    m_ok->setText("Enter");
    m_cancel->setText("Cancel");
}

void Login::InitLoginEvent()
{
    //确定键
    connect(m_ok, &QPushButton::clicked, this, &Login::slot_pressOkBtn);
    //取消键
    connect(m_cancel, &QPushButton::clicked, this, &Login::slot_pressCancelBtn);
}

void Login::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Return)
    {
        slot_pressOkBtn();
    }
}

void Login::slot_pressOkBtn()
{
    if(!m_edit->text().compare("5293031"))
    {
      showWidget = new Show();
      showWidget->show();
      this->hide();
      m_edit->clear();
      connect(showWidget,&Show::back,this,[=]{
         showWidget->close();
         this->show();
      });
    }
    else{
        QMessageBox::warning(this, tr("Warning!"),
                    tr("Password Error!"),
                    QMessageBox::Yes);
        m_edit->clear();
    }
}

void Login::slot_pressCancelBtn()
{
    close();
}

Login::~Login()
{

}

