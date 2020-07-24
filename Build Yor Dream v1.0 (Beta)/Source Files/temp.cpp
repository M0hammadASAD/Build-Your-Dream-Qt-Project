#include "temp.h"
#include "ui_temp.h"
#include "mainwindow.h"
#include "temp2.h"
temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{
    ui->setupUi(this);
}

temp::~temp()
{
    delete ui;
}

void temp::on_pushButton_go_bck_clicked()
{
    QWidget *new_window=new MainWindow ;
        new_window->show();
        close();
}

void temp::on_pushButton_nxt_clicked()
{
    temp2 con_login;
    con_login.setModal(true);
    con_login.exec();
}
