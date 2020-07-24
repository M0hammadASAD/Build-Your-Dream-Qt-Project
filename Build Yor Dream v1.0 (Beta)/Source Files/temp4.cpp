#include "temp4.h"
#include "ui_temp4.h"
#include "mainwindow.h"

temp4::temp4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp4)
{
    ui->setupUi(this);
}

temp4::~temp4()
{
    delete ui;
}

void temp4::on_pushButton_nxt_2_clicked()
{
    QWidget *new_window=new MainWindow ;
        new_window->show();
        hide ();
}
