#pragma once

#include <QtWidgets/QWidget>
#include "ui_NetworkVisualization.h"

#include <iostream>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <vector>
#include <QDebug>
#include "DataDrive.h"
#include "Console.h"

using namespace std;

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif

class NetworkVisualization : public QWidget
{
    Q_OBJECT

public:
    NetworkVisualization(QWidget *parent = nullptr);
    ~NetworkVisualization();

private:
    Ui::NetworkVisualizationClass ui;
    QPushButton* pb1;
};
