#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QCoreApplication>
#include<QDir>
#include<QDebug>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSql>
#include<QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_con_clicked();

    void on_dev_clicked();

    void on_temp_clicked();




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
