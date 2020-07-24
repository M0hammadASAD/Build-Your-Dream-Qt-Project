#ifndef DPROFILE_H
#define DPROFILE_H
#include"mainwindow.h"
#include <QDialog>

namespace Ui {
class dprofile;
}

class dprofile : public QDialog
{
    Q_OBJECT

public:
    static int x;
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
    explicit dprofile(QWidget *parent = nullptr);
    ~dprofile();

private slots:
    void onnameclicked();
    void on_load_pb_clicked();

    void on_savechange_button_clicked();

    void on_change_dp_button_clicked();

    void on_pushButton_2_clicked();

    void on_logout_btn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::dprofile *ui;
};

#endif // DPROFILE_H
