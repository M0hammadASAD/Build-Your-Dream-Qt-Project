#include "mainwindow.h"
#include<QSplashScreen>
#include <QApplication>
#include<QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/img/PicsArt_05-23-07.41.23.png"));
    splash->show();


    MainWindow w;

    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&w,SLOT(show()));


    return a.exec();
}
