#pragma once

#include "console_global.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <QtWidgets/QFileDialog>
#include <vector>
#include "DataDrive.h"
class CONSOLE_EXPORT Console:public QWidget
{
public:
    Console();
public slots:
    static void loadFileAndShow();
};
