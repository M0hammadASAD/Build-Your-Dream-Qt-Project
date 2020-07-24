#ifndef CPROFILE_H
#define CPROFILE_H
#include"mainwindow.h"
#include <QDialog>
#include "con_login.h"
namespace Ui {
class cprofile;
}

class cprofile : public QDialog
{
    Q_OBJECT
public slots:
    void onnameclicked();

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

    static int x;
    static QString pro_user;
    explicit cprofile(QWidget *parent = nullptr);
    ~cprofile();

private slots:
    void on_pushButton_clicked();

    void on_load_pb_clicked();

    void on_savechange_button_clicked();

    void on_pushButton_2_clicked();

    void on_logout_btn_clicked();

    void on_change_dp_button_clicked();

    void on_post_btn_clicked();

    void on_comboBox_2_activated(const QString &arg1);

private:
    Ui::cprofile *ui;
};

#endif // CPROFILE_H
