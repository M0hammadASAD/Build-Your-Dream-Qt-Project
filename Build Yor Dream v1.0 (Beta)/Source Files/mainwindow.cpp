#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dev_login.h"
#include "con_login.h"
#include "temp.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_con_clicked()
{
    con_login con_login;
    con_login.setModal(true);
    con_login.exec();
}

void MainWindow::on_dev_clicked()
{
    dev_login dev_login;
    dev_login.setModal(true);
    dev_login.exec();
}

void MainWindow::on_temp_clicked()
{
    temp temp;
    temp.setModal(true);
    temp.exec();
}
