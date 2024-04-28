/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableWidget *tableWidget;
    QPushButton *pushButton_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 28, 32);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(590, 74, 161, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(480, 190, 100, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);border-radius: (20px);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(480, 230, 100, 32));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);bolder-radius: (20px);"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(620, 190, 100, 32));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);bolder-radius: (20px);"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(620, 230, 100, 32));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);bolder-radius: (20px);"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(480, 270, 100, 32));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);bolder-radius: (20px);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(480, 70, 100, 32));
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(91, 57, 12);\n"
"border-radius: (20px);"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(480, 110, 100, 32));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(91, 57, 12);\n"
"border-radius: (20px);"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(50, 40, 251, 501));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 249, 499));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(10, 0, 441, 570));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);"));
        tableWidget->setMidLineWidth(400);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(1);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(620, 270, 100, 32));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 116, 99);bolder-radius: (20px);"));
        MainWindow->setCentralWidget(centralwidget);
        scrollArea->raise();
        lineEdit->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton->raise();
        pushButton_7->raise();
        tableWidget->raise();
        pushButton_8->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 32));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "multiplicate", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "addition", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "value at point", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "solution", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "derivative", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "den", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
