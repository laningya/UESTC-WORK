#include "NetworkVisualization.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkVisualization w;
    w.show();
    return a.exec();
}
