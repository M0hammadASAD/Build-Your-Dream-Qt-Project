#ifndef CON_LOGIN_H
#define CON_LOGIN_H
/// I added
#include <QDialog>
#include <QtSql>
#include<QDebug>
#include <QFileInfo>
#include"mainwindow.h"
namespace Ui {
class con_login;
}
QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

class UserData
{
public:
    static QString userName;

} ;
class con_login : public QDialog
{
    Q_OBJECT

public:

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


    explicit con_login(QWidget *parent = nullptr);
    ~con_login();

private slots:
    void on_bck_btn_clicked();

    void on_login_btn_clicked();

    void on_reg_btn_clicked();

    void on_upload_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pb_clicked();

private:
    Ui::con_login *ui;

    QString file_path;
    QString *con_un;
};


#endif // CON_LOGIN_H
