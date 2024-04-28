#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QScrollArea>
#include <QCheckBox>
#include <Qlabel>
#include <QComboBox>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_button_clicked();
private:
    Ui::MainWindow *ui;
    QScrollArea a;
    QCheckBox *check;
    QLabel * label;
    QComboBox *combo;
    QPushButton *button;
};
#endif // MAINWINDOW_H




