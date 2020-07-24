#include "temp3.h"
#include "ui_temp3.h"
#include "mainwindow.h"
#include "temp4.h"
temp3::temp3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp3)
{
    ui->setupUi(this);
}

temp3::~temp3()
{
    delete ui;
}

void temp3::on_pushButton_nxt_2_clicked()
{
    QWidget *new_window=new MainWindow ;
        new_window->show();
        hide ();
}

void temp3::on_pushButton_nxt_clicked()
{
    temp4 con_login;
    con_login.setModal(true);
    con_login.exec();
}
