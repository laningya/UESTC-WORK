#include "NetworkVisualization.h"

NetworkVisualization::NetworkVisualization(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->resize(QSize(800, 600));
    this->setWindowTitle("������ӻ����");


    pb1 = new QPushButton(this);
    pb1->setText("�����ļ�");
    pb1->setGeometry(290, 230, 200, 100);

    connect(pb1, &QPushButton::clicked, this, [&]() {

        vector<vector<int>> arrArrInt;
        string filePath = string((QFileDialog::getOpenFileName(this, "ѡ�񵥸��ļ�", "./")).toLocal8Bit());
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
            qDebug() << "�޷�ʶ���ļ�����" << endl;
            QMessageBox::critical(this, "Error", "�����ļ�ʧ��,�޷�ʶ���ļ�����");
        }
        });
    

    //connect(pb1, &QPushButton::clicked, this, &Console::loadFileAndShow);
}

NetworkVisualization::~NetworkVisualization()
{

}
