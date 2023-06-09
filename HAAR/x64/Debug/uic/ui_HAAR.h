/********************************************************************************
** Form generated from reading UI file 'HAAR.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAAR_H
#define UI_HAAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HAARClass
{
public:
    QWidget *centralWidget;
    QPushButton *cntButton;
    QGraphicsView *DISPLAY;
    QLCDNumber *COUNTER;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HAARClass)
    {
        if (HAARClass->objectName().isEmpty())
            HAARClass->setObjectName(QString::fromUtf8("HAARClass"));
        HAARClass->resize(919, 714);
        HAARClass->setStyleSheet(QString::fromUtf8("background-color: black;"));
        centralWidget = new QWidget(HAARClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        cntButton = new QPushButton(centralWidget);
        cntButton->setObjectName(QString::fromUtf8("cntButton"));
        cntButton->setGeometry(QRect(10, 590, 221, 61));
        cntButton->setStyleSheet(QString::fromUtf8("background-color: white;"));
        DISPLAY = new QGraphicsView(centralWidget);
        DISPLAY->setObjectName(QString::fromUtf8("DISPLAY"));
        DISPLAY->setGeometry(QRect(10, 0, 881, 581));
        DISPLAY->setMaximumSize(QSize(1280, 720));
        DISPLAY->setStyleSheet(QString::fromUtf8("background-color: white;"));
        COUNTER = new QLCDNumber(centralWidget);
        COUNTER->setObjectName(QString::fromUtf8("COUNTER"));
        COUNTER->setGeometry(QRect(250, 590, 111, 61));
        COUNTER->setStyleSheet(QString::fromUtf8("background-color: white;"));
        HAARClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HAARClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 22));
        HAARClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HAARClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        HAARClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HAARClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        HAARClass->setStatusBar(statusBar);

        retranslateUi(HAARClass);

        QMetaObject::connectSlotsByName(HAARClass);
    } // setupUi

    void retranslateUi(QMainWindow *HAARClass)
    {
        HAARClass->setWindowTitle(QCoreApplication::translate("HAARClass", "HAAR", nullptr));
        cntButton->setText(QCoreApplication::translate("HAARClass", "COUNT ATTENDEE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HAARClass: public Ui_HAARClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAAR_H
