#include "Console.h"

Console::Console()
{
}
void Console::loadFileAndShow()
{
    QWidget* a = new QWidget();
    vector<vector<int>> arrArrInt;
    string filePath = (QFileDialog::getOpenFileName(a, "选择单个文件", "./")).toStdString();
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
        QMessageBox::critical(a, "警告", "无法识别文件类型");
    }
}