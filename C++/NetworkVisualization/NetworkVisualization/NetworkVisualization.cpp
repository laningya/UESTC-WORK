#include "NetworkVisualization.h"

NetworkVisualization::NetworkVisualization(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->resize(QSize(800, 600));
    this->setWindowTitle("网络可视化软件");


    pb1 = new QPushButton(this);
    pb1->setText("加载文件");
    pb1->setGeometry(290, 230, 200, 100);

    connect(pb1, &QPushButton::clicked, this, [&]() {

        vector<vector<int>> arrArrInt;
        string filePath = string((QFileDialog::getOpenFileName(this, "选择单个文件", "./")).toLocal8Bit());
        qDebug() << QString::fromStdString(filePath) << endl;
        switch (DataDrive::fileType(filePath))
        {
        case 1:
            arrArrInt = DataDrive::fileRead(filePath);
            break;
        case 2:
            arrArrInt = DataDrive::csvRead(filePath);
            break;
        default:
            qDebug() << "无法识别文件类型" << endl;
            QMessageBox::critical(this, "Error", "加载文件失败,无法识别文件类型");
        }
        });
    

    //connect(pb1, &QPushButton::clicked, this, &Console::loadFileAndShow);
}

NetworkVisualization::~NetworkVisualization()
{

}
