#include "con_login.h"
#include "ui_con_login.h"
///i added this
#include "cprofile.h"
#include"mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QSql>
#include<QFileDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QFileInfo>
#include<QSqlQuery>

QString UserData::userName = "empty";
con_login::con_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::con_login)
{
    ui->setupUi(this);


}

con_login::~con_login()
{
    delete ui;
}
void con_login::on_bck_btn_clicked()
{
    QWidget *new_window=new MainWindow ;
    new_window->show();
    hide ();

}

void con_login::on_login_btn_clicked()
{
    connOpen();
    UserData::userName = ui-> unlog_line ->text();


        QString username = ui-> unlog_line ->text();
        QString password = ui-> passlog_line ->text();


        QSqlQuery qry;
        if(qry.exec("select * from cinfo where username='"+username+"' and password = '"+password+"'"))
        {
            int count=0;
            while (qry.next()) {

                count++;
            }

            if(count==1)
            {
                this->hide();
                cprofile cprofile;
                cprofile.setModal(true);
                cprofile.exec();
            }
            if(count<1)
            {
                QMessageBox::critical(this,"Login Failed","Username or Password incorrect");
            }
        }
        connClose();

}

void con_login::on_reg_btn_clicked()
{


    if(connOpen())
    {
        QString username = ui->un->text();
        QString password = ui->pass->text();
        QString email = ui->email->text();
        QString phone = ui->phn->text();
        QString Full_Name=ui->fn->text();
        QString DOB = ui->dob->text();
        QString Address =ui->add->text();
        QString Pics =ui->add_2->text();

        QSqlQuery qry;
        qry.prepare("INSERT INTO cinfo (username, password, email, phone,Full_Name,DOB,Address,Pics)"
                    "VALUES(:username,:password, :email, :phone, :Full_Name, :DOB, :Address, :Pics)");

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



/*void con_login::on_pushButton_clicked()
{
    QString picpath=QFileDialog::getOpenFileName
                    (
                        this,
                    tr("Open File"),
                    "C://",
                    "All File (*.*);;JPG File (*.jpg);;PNG File (*.png)"
                        );
    ui->add_2->setText(picpath);
        ////QSqlDatabase conn=QSqlDatabase::addDatabase("QSQLITE");
            conn.setDatabaseName("I:/Qt Docs/Qt_project/DB/BUILD_YOUR_Dream.sqlite");
            conn.open();
            QSqlQuery qry;
               qry.prepare("update dinfo set Pic ='"+picpath+"'where username='"+userDat+"'");
               if(qry.exec()){

                  QMessageBox::information(this,tr("Update Result"),tr("<font color=black>Profile Photo Update Completed"));
               conn.close();
               conn.open();
               QSqlQuery qry;
               qry.prepare("select * from dinfo where username='"+userDat+"'");
               if(qry.exec())
                   while(qry.next())
                   {
                       QPixmap pro_pic;
                       QString location=qry.value(10).toString();
                       pro_pic.load(location);
                       ui->label->setPixmap(pro_pic);
                       ui->label->setScaledContents(true);
                   }
               conn.close();
               }
}*/

void con_login::on_pb_clicked()
{
    QString picpath=QFileDialog::getOpenFileName
                    (
                        this,
                    tr("Open File"),
                    "C://",
                    "All File (*.*);;JPG File (*.jpg);;PNG File (*.png)"
                        );
    ui->add_2->setText(picpath);
}
