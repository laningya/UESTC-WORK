/********************************************************************************
** Form generated from reading UI file 'NetworkVisualization.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKVISUALIZATION_H
#define UI_NETWORKVISUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkVisualizationClass
{
public:

    void setupUi(QWidget *NetworkVisualizationClass)
    {
        if (NetworkVisualizationClass->objectName().isEmpty())
            NetworkVisualizationClass->setObjectName(QString::fromUtf8("NetworkVisualizationClass"));
        NetworkVisualizationClass->resize(600, 400);

        retranslateUi(NetworkVisualizationClass);

        QMetaObject::connectSlotsByName(NetworkVisualizationClass);
    } // setupUi

    void retranslateUi(QWidget *NetworkVisualizationClass)
    {
        NetworkVisualizationClass->setWindowTitle(QApplication::translate("NetworkVisualizationClass", "NetworkVisualization", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetworkVisualizationClass: public Ui_NetworkVisualizationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKVISUALIZATION_H
