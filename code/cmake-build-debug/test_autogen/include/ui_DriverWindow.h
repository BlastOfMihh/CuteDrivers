/********************************************************************************
** Form generated from reading UI file 'DriverWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVERWINDOW_H
#define UI_DRIVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriverWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *scoreLabel;
    QLabel *locationLabel;
    QListWidget *listReports;
    QPushButton *validateReportButton;
    QListWidget *chatList;
    QLineEdit *chatLine;
    QPushButton *chatButton;
    QLabel *label_2;
    QLineEdit *reportDescriptionLine;
    QLabel *label_3;
    QLineEdit *reportLineX;
    QLineEdit *reportLineY;
    QPushButton *fileReportB;
    QPushButton *showMapButton;

    void setupUi(QWidget *DriverWindow)
    {
        if (DriverWindow->objectName().isEmpty())
            DriverWindow->setObjectName("DriverWindow");
        DriverWindow->resize(525, 419);
        verticalLayout = new QVBoxLayout(DriverWindow);
        verticalLayout->setObjectName("verticalLayout");
        scoreLabel = new QLabel(DriverWindow);
        scoreLabel->setObjectName("scoreLabel");

        verticalLayout->addWidget(scoreLabel);

        locationLabel = new QLabel(DriverWindow);
        locationLabel->setObjectName("locationLabel");

        verticalLayout->addWidget(locationLabel);

        listReports = new QListWidget(DriverWindow);
        listReports->setObjectName("listReports");

        verticalLayout->addWidget(listReports);

        validateReportButton = new QPushButton(DriverWindow);
        validateReportButton->setObjectName("validateReportButton");

        verticalLayout->addWidget(validateReportButton);

        chatList = new QListWidget(DriverWindow);
        chatList->setObjectName("chatList");

        verticalLayout->addWidget(chatList);

        chatLine = new QLineEdit(DriverWindow);
        chatLine->setObjectName("chatLine");

        verticalLayout->addWidget(chatLine);

        chatButton = new QPushButton(DriverWindow);
        chatButton->setObjectName("chatButton");

        verticalLayout->addWidget(chatButton);

        label_2 = new QLabel(DriverWindow);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        reportDescriptionLine = new QLineEdit(DriverWindow);
        reportDescriptionLine->setObjectName("reportDescriptionLine");

        verticalLayout->addWidget(reportDescriptionLine);

        label_3 = new QLabel(DriverWindow);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        reportLineX = new QLineEdit(DriverWindow);
        reportLineX->setObjectName("reportLineX");

        verticalLayout->addWidget(reportLineX);

        reportLineY = new QLineEdit(DriverWindow);
        reportLineY->setObjectName("reportLineY");

        verticalLayout->addWidget(reportLineY);

        fileReportB = new QPushButton(DriverWindow);
        fileReportB->setObjectName("fileReportB");

        verticalLayout->addWidget(fileReportB);

        showMapButton = new QPushButton(DriverWindow);
        showMapButton->setObjectName("showMapButton");

        verticalLayout->addWidget(showMapButton);


        retranslateUi(DriverWindow);

        QMetaObject::connectSlotsByName(DriverWindow);
    } // setupUi

    void retranslateUi(QWidget *DriverWindow)
    {
        DriverWindow->setWindowTitle(QCoreApplication::translate("DriverWindow", "DriverWindow", nullptr));
        scoreLabel->setText(QCoreApplication::translate("DriverWindow", "TextLabel", nullptr));
        locationLabel->setText(QCoreApplication::translate("DriverWindow", "TextLabel", nullptr));
        validateReportButton->setText(QCoreApplication::translate("DriverWindow", "Validate Report", nullptr));
        chatLine->setText(QCoreApplication::translate("DriverWindow", "asdfasdf", nullptr));
        chatLine->setPlaceholderText(QCoreApplication::translate("DriverWindow", "asdf", nullptr));
        chatButton->setText(QCoreApplication::translate("DriverWindow", "SEND", nullptr));
        label_2->setText(QCoreApplication::translate("DriverWindow", "report description", nullptr));
        label_3->setText(QCoreApplication::translate("DriverWindow", "report Location", nullptr));
        fileReportB->setText(QCoreApplication::translate("DriverWindow", "File Report", nullptr));
        showMapButton->setText(QCoreApplication::translate("DriverWindow", "show map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DriverWindow: public Ui_DriverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVERWINDOW_H
