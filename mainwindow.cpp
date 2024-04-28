#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "back.h"
#include <QMessageBox>
#include <QInputDialog>
#include<QScrollArea>
#include <QCheckBox>
#include <qpushbutton.h>
#include <QEventLoop>

int number = -1;

std::vector <int> letters;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width());

    label = new QLabel(this);
    label->setGeometry(480, 70, 240, 100);
    label->setStyleSheet("background-color: #906363;"
                         "border-radius: 10px;");

    combo = new QComboBox(label);
    combo->setGeometry(50, 20, 150, 20);
    combo->setStyleSheet("background-color: #006363;");


    button = new QPushButton(label);
    button->setGeometry(70, 50, 100, 20);
    button -> setStyleSheet("background-color: #006363; border-radius:2px;");
    button->setText("ok");
    label->hide();

    connect(button, &QPushButton::clicked, this, &MainWindow::on_button_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_clicked(){

    QString a = this->combo->currentText();
    std::string str = a.toStdString();
    number = alf.find(str[0]);
    label->hide();
}

void MainWindow::on_pushButton_clicked()
{
    std::string a = ui->lineEdit->text().toStdString();
    if(a.size() == 0){
        return;
    }
    node * n = solve(a);
    if(n == nullptr){
        return;
    }
    bubble_sort(n);

    a = cout_node(n);
    QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(a));
    ui->tableWidget->setRowCount(cnt_of_bases + 1);
    ui->tableWidget->setItem(cnt_of_bases, 0, item);
    polynomal *p = new polynomal(n);
    base* b = new base(p);
    if(!baza){
        baza = b;
    } else{
        base * elem = baza;
        while(elem->get_next()){
            elem = elem->get_next();
        }
        elem->set_next(b);
    }
    ++cnt_of_bases;

}


void MainWindow::on_pushButton_2_clicked()//multi
{
    int r, c;
    r = QInputDialog::getInt(this, "first polynom", "->");
    c = QInputDialog::getInt(this, "first polynom", "->");
    if(r <1 || c < 1|| r > cnt_of_bases || c > cnt_of_bases){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    --c;
    polynomal *first;
    polynomal*second;
    first = baza->get_n_elem(r);
    second = baza->get_n_elem(c);
    node * p = multiplicate(first->get_first(), second->get_first());
    std::string a = cout_node(p);
    node * n = solve(a);
    bubble_sort(n);
    a = cout_node(n);
    bool append;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "mm", "append " + QString::fromStdString(a) + "?))))))))))" ,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        append = 1;
    } else {
        append = 0;
    }
    if(append){

        if(n == nullptr){
            return;
        }
        a = cout_node(n);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(a));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
        polynomal *p = new polynomal(n);
        base* b = new base(p);
        if(!baza){
            baza = b;
        }else{
            base * elem = baza;
            while(elem->get_next()){
                elem = elem->get_next();
            }
            elem->set_next(b);
        }
        ++cnt_of_bases;
    }
}

void MainWindow::on_pushButton_3_clicked()//addition
{
    int r, c;
    r = QInputDialog::getInt(this, "first polynom", "->");
    c = QInputDialog::getInt(this, "first polynom", "->");
    if(r <1 || c < 1|| r > cnt_of_bases || c > cnt_of_bases){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    --c;

    polynomal *first;
    polynomal*second;
    first = baza->get_n_elem(r);
    second = baza->get_n_elem(c);
    std::string str = cout_node(first->get_first());
    node * frst = solve(str);
    str = cout_node(second->get_first());
    node*scnd = solve(str);

    node *ans = addition(frst, scnd);
    std::string aa = cout_node(ans);
    node * n = solve(aa);
    bubble_sort(n);
    std::string a = cout_node(n);
    bool append;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "mm", "append " + QString::fromStdString(a) + "?))))))))))" ,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        append = 1;
    } else {
        append = 0;
    }    if(append){
        n = solve(a);
        bubble_sort(n);
        if(n == nullptr){
            return;
        }
        a = cout_node(n);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(a));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
        polynomal *p = new polynomal(n);
        base* b = new base(p);
        if(!baza){
            baza = b;
        }else{
            base * elem = baza;
            while(elem->get_next()){
                elem = elem->get_next();
            }
            elem->set_next(b);
        }
        ++cnt_of_bases;
    }
}



void MainWindow::on_pushButton_4_clicked()//value at point
{
    int r;
    r = QInputDialog::getInt(this, "polynom", "->");
    if(r <1 || r > cnt_of_bases ){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    node * a= baza->get_n_elem(r)->get_first();


    node* elem = a;
    std::vector <int> array(26, 0);
    while (elem != nullptr) {
        std::vector <int> is(26, 0);
        is = elem->get_powers();
        for (int i = 0; i < is.size(); ++i) {
            if(is[i] != 0) {
                array[i] = 1;
            }
        }
        elem = elem->get_next();
    }
    //получаем нужные значения
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] == 1) {
            std::string ff = "";
            ff+=alf[i];
            int n;
            n = QInputDialog::getInt(this, QString::fromStdString(ff), "->");
            array[i] = n;
        }
    }
    elem = a;
    int ans = 0;
    while (elem != nullptr) {
        int val_of_mono = elem->get_multiplier();
        std::vector <int> pow = elem->get_powers();
        for (int i = 0; i < alf.size(); ++i) {
            if (pow[i] != 0) {
                int n = pow[i];
                while (n--) {
                    val_of_mono *= array[i];
                }
            }

        }
        if (!elem->get_sign()) {
            val_of_mono = -val_of_mono;
        }
        ans += val_of_mono;
        elem = elem->get_next();
    }
    QMessageBox::about(this, "answer:", QString::number(ans));
}


void MainWindow::on_pushButton_5_clicked()
{
    int r;
    r = QInputDialog::getInt(this, "polynom", "->");
    if(r <1 || r > cnt_of_bases ){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    node * a= baza->get_n_elem(r)->get_first();
    std::string sf = cout_node(a);
    polynomal j = polynomal(solve(sf));
    if(!j.is_only_variable()){
        QMessageBox::about(this, "a", "not a one param");
        return;
    }
    std::vector <int> array = search_an_solution(j);
    std::string str;
    for(int i = 0; i < array.size(); ++i){
        str+= std::to_string(array[i]);
        str+= ',';
    }
    if(str.size() == 0){
        str = "no waay ";
    }
    if(str.size() > 0){
        str.erase(str.begin() + str.size() - 1);
    }
    QMessageBox::about(this, "answer:", QString::fromStdString(str));
}


void MainWindow::on_pushButton_6_clicked()
{
    int r;
    r = QInputDialog::getInt(this, "polynom", "->");
    if(r <1 || r > cnt_of_bases ){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    node * a= baza->get_n_elem(r)->get_first();
    std::string sf = cout_node(a);
    polynomal j = polynomal(solve(sf));
    node * h = a;
    std::vector <int>array(26, 0);
    while(h){
        for(int i = 0; i < alf.size(); ++i){
            if(h->get_powers()[i] != 0){
                array[i] = 1;
            }
        }
        h = h->get_next();
    }
    letters = array;
    combo->clear();
    for(int i = 0; i < alf.size(); ++i){
        if(letters[i] != 0){
            std::string u;
            u += alf[i];
            combo->addItem(QString::fromStdString(u));
        }
    }
    label->show();
    QEventLoop loop;
    connect(button, &QPushButton::clicked, &loop, &QEventLoop::exit);
    loop.exec();
    search_derivative(j, number);
    //a = j.get_first();
    std::string aa ;
    aa = cout_node(j.get_first());
    bool append;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "mm", "append " + QString::fromStdString(aa) + "?" ,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        append = 1;
    } else {
        append = 0;
    }
    if(append) {
        node * n = solve(aa);
        bubble_sort(n);
        if(n == nullptr){
            return;
        }
        aa = cout_node(n);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(aa));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
        polynomal *p = new polynomal(n);
        base* b = new base(p);
        if (!baza){
            baza = b;
        }else {
            base * elem = baza;
            while(elem->get_next()){
                elem = elem->get_next();
            }
            elem->set_next(b);
        }
        ++cnt_of_bases;
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    int r;
    r = QInputDialog::getInt(this, "polynom", "->");
    if (r < 1 || r > cnt_of_bases){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    base* a = baza;
    for(int i = 0; i < r; ++i){
        a = a->get_next();
        if(a == nullptr){
            QMessageBox::about(this, "smth is wrong", "aaa");
            return;
        }
    }

    base* p = a->get_next();
    if(p == nullptr){
        a = nullptr;
    }
    else{
        if(cnt_of_bases == 1){
            baza = nullptr;
        }
        else{

            *a = *p;
            delete p;
        }

    }
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(cnt_of_bases - 1);
    --cnt_of_bases;
    base* elem = baza;
    for(int i = 0; i < cnt_of_bases; ++i){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(
                                           QString::fromStdString(cout_node(
                                           elem->get_polynom()->get_first()))));
        elem = elem->get_next();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    int r, c;
    r = QInputDialog::getInt(this, "first polynom", "->");
    c = QInputDialog::getInt(this, "first polynom", "->");
    if(r <1 || c < 1|| r > cnt_of_bases || c > cnt_of_bases){
        QMessageBox::about(this, "incorrect", "wrong integers");
        return;
    }
    --r;
    --c;
    polynomal *first ;
    polynomal *second;
    first = baza->get_n_elem(r);
    node * ans;
    second = baza->get_n_elem(c);
    node * f =first->get_first();
    un_bubble_sort(f);
    f = second->get_first();
    un_bubble_sort(f);
    if(r == c){
        ans = new node(1, std::vector <int> (26, 0), 1);
    }

    else {
        if(!first->is_only_variable() || !second->is_only_variable()){
            QMessageBox::about(this, "incorrect", "wrong params");

            node * l =first->get_first();
            bubble_sort(l);
            l = second->get_first();
            bubble_sort(l);
            return;
        }
        if(second->get_first()->get_multiplier() == 0 && !second->get_first()->get_next()){
            QMessageBox::about(this, "incorrect", "divizion by zero... come on, man are you serious?");
            node * l =first->get_first();
            bubble_sort(l);
            l = second->get_first();
            bubble_sort(l);
            return;
        }
        for(int i = 0; i < alf.size(); ++i){
            if((first->get_first()->get_powers()[i] == 0 && second->get_first()->get_powers()[i] != 0) ||
                (first->get_first()->get_powers()[i] != 0 && second->get_first()->get_powers()[i] == 0)){
                QMessageBox::about(this, "incorrect", "different params");
                node * l =first->get_first();
                bubble_sort(l);
                l = second->get_first();
                bubble_sort(l);
                return;
            }
        }
        if(get_pow(first->get_first())
            < get_pow(second->get_first())){
            QMessageBox::about(this, "its wrong", "first polynomal < second(((");
            return;
        }else{
        ans = den(first->get_first(), second->get_first());
            ans = un_multiplicate(ans);}
    }
    node * l =first->get_first();
    bubble_sort(l);
    l = second->get_first();
    bubble_sort(l);
    std::string a = cout_node(ans);

    bool append;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "mm", "append " + QString::fromStdString(a) + "?))))))))))" ,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        append = 1;
    } else {
        append = 0;
    }    if(append){
        node * n = solve(a);
        bubble_sort(n);
        if(n == nullptr){
            return;
        }
        a = cout_node(n);
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(a));
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, item);
        polynomal *p = new polynomal(n);
        base* b = new base(p);
        if(!baza){
            baza = b;
        }else{
            base * elem = baza;
            while(elem->get_next()){
                elem = elem->get_next();
            }
            elem->set_next(b);
        }
        ++cnt_of_bases;
    }
}
