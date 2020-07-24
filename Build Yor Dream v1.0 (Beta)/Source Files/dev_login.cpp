#include "dev_login.h"
#include "ui_dev_login.h"
#include "mainwindow.h"
///I added
#include "dprofile.h"
#include"mainwindow.h"
#include<QMessageBox>
#include<QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QFileDialog>
#include<QSqlQuery>

QString UserInfo::userName = "empty";

dev_login::dev_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dev_login)
{
    ui->setupUi(this);

}

dev_login::~dev_login()
{
    delete ui;
}

void dev_login::on_bck_btn_clicked()
{
    QWidget *new_window=new MainWindow ;
    new_window->show();
    hide ();
}

void dev_login::on_login_btn_clicked()
{
    connOpen();
    UserInfo::userName = ui-> lineEdit_username ->text();

    QString username,password;
    username = ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();


    if(!connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from dinfo where username='"+username+"' and password = '"+password+"'"))
    {
        int count=0;
        while (qry.next()) {

            count++;
        }

        if(count==1)
        {
            this->hide();
            dprofile dprofile;
            dprofile.setModal(true);
            dprofile.exec();
        }
        if(count<1)
        {
            QMessageBox::critical(this,"Login Failed","Username or Password incorrect");
        }
    }
    connClose();
}

void dev_login::on_reg_btn_clicked()
{
    connOpen();


    if(connOpen())
    {
        QString username = ui->un->text();

        QString password = ui->pass->text();
        QString email = ui->email->text();
        QString phone = ui->phn->text();
        QString Full_Name=ui->fn->text();
        QString DOB = ui->dob->text();
        QString Address =ui->add->text();
        QString Pics =ui->dob_2->text();

        QSqlQuery qry;
        qry.prepare("INSERT INTO dinfo (username, password, email, phone,Full_Name,DOB,Address,Pics)"
                    "VALUES(:username,:password, :email, :phone, :Full_Name, :DOB, :Address,:Pics)");
        qry.bindValue(":username", username);
        qry.bindValue(":password", password);
        qry.bindValue(":email", email);
        qry.bindValue(":phone", phone);
        qry.bindValue(":Full_Name", Full_Name);
        qry.bindValue(":DOB", DOB);
        qry.bindValue(":Address", Address);
        qry.bindValue(":Pics",Pics);
        if(qry.exec())
        {
            QMessageBox::information(this,"Registered!","Congratulations!! Successfully registrd. Please Login to continue");
        }
        else
            QMessageBox::critical(this,"Not inserted","Not inserted");

    }
    else
     {
        QMessageBox::information(this,"Not Connectrd","Database isn't connected");
     }
}

void dev_login::on_pb_clicked()
{
    QString picpath=QFileDialog::getOpenFileName
                    (
                        this,
                    tr("Open File"),
                    "C://",
                    "All File (*.*);;JPG File (*.jpg);;PNG File (*.png)"
                        );
    ui->dob_2->setText(picpath);
}
