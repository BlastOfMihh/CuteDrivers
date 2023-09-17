/********************************************************************************
** Form generated from reading UI file 'reportmap.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTMAP_H
#define UI_REPORTMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reportmap
{
public:

    void setupUi(QWidget *reportmap)
    {
        if (reportmap->objectName().isEmpty())
            reportmap->setObjectName("reportmap");
        reportmap->resize(400, 300);

        retranslateUi(reportmap);

        QMetaObject::connectSlotsByName(reportmap);
    } // setupUi

    void retranslateUi(QWidget *reportmap)
    {
        reportmap->setWindowTitle(QCoreApplication::translate("reportmap", "reportmap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reportmap: public Ui_reportmap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTMAP_H
