#ifndef DEV_LOGIN_H
#define DEV_LOGIN_H
#include "mainwindow.h"
#include <QDialog>

#include <QtSql>
#include<QDebug>
#include"dprofile.h"
#include <QFileInfo>

namespace Ui {
class dev_login;
}
class UserInfo
{
public:
    static QString userName;
} ;
class dev_login : public QDialog
{
    Q_OBJECT

public:
    explicit dev_login(QWidget *parent = nullptr);
    ~dev_login();
    QSqlDatabase mydb;
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("BUILD_YOUR_DREAM.sqlite");
        if(!mydb.open()){
            qDebug()<<"Can not open the database";
            return false;
        }
        else
        {
            qDebug()<<"Connected";
            return true;
        }
    }

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
private slots:
    void on_bck_btn_clicked();

    void on_login_btn_clicked();

    void on_reg_btn_clicked();

    void on_pb_clicked();

private:
    Ui::dev_login *ui;

};

#endif // DEV_LOGIN_H
