#include "Console.h"

Console::Console()
{
}
void Console::loadFileAndShow()
{
    QWidget* a = new QWidget();
    vector<vector<int>> arrArrInt;
    string filePath = (QFileDialog::getOpenFileName(a, "ѡ�񵥸��ļ�", "./")).toStdString();
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
        QMessageBox::critical(a, "����", "�޷�ʶ���ļ�����");
    }
}