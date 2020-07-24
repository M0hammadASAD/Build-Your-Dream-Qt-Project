#include "temp2.h"
#include "ui_temp2.h"
#include "mainwindow.h"
#include "temp3.h"

temp2::temp2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp2)
{
    ui->setupUi(this);
}

temp2::~temp2()
{
    delete ui;
}

void temp2::on_pushButton_nxt_2_clicked()
{
    QWidget *new_window=new MainWindow ;
        new_window->show();
        hide ();
}

void temp2::on_pushButton_nxt_clicked()
{
    temp3 con_login;
    con_login.setModal(true);
    con_login.exec();
}
