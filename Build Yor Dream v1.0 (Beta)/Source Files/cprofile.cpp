#include "cprofile.h"
#include "ui_cprofile.h"
///I added
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QGridLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QFrame>
#include <QSqlRecord>
#include <QFileDialog>
#include <QPixmap>
#include "mainwindow.h"
#include <QMessageBox>
#include "con_login.h"

QString cprofile:: pro_user;

cprofile::cprofile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cprofile)
{
    ui->setupUi(this);


    ui->comboBox->addItem("1");
    ui->comboBox->addItem("2");
    ui->comboBox->addItem("3");
    ui->comboBox->addItem("4");
    ui->comboBox->addItem("5");

    ui->comboBox_2->addItem("1 - Resedential Building");
    ui->comboBox_2->addItem("2 - Educational Building");
    ui->comboBox_2->addItem("3 - Commercial/Office Building");
    ui->comboBox_2->addItem("4 - Shopping Mall");

    ///Loading contents on find dev tab starts


    ///creating conn with db

        connOpen();
        //Creating Modal...
            QSqlQueryModel *modal= new QSqlQueryModel();
            QSqlQueryModel *modal1= new QSqlQueryModel();
            QSqlQueryModel *modal2= new QSqlQueryModel();    //Creating Modal...

            //Creating query and assigning database to it...
            QSqlQuery *qry= new QSqlQuery(mydb);
            QSqlQuery *qry1= new QSqlQuery(mydb);
            QSqlQuery *qry3= new QSqlQuery(mydb);

            //Creating query and assigning database to it...

            //Preparing the queries with the necessary fetched data...
            qry->prepare("select username from dinfo");
            qry1->prepare("select email from dinfo");
            qry3->prepare("select phone from dinfo");    //Preparing the queries with the necessary fetched data...

            //Executing the queries...
            qry->exec();
            qry1->exec();
            qry3->exec();//Executing the queries...

            //Assigning the queries to the previuosly created modals...
            modal->setQuery(*qry);
            modal1->setQuery(*qry1);
            modal2->setQuery(*qry3);//Assigning the queries to the previuosly created modals...

            //Creating a grid layout...
            QGridLayout *lay=new QGridLayout(this);
            //Creating an array of button...
            QPushButton *name[100];
            //running a loop to add the desired components to the scroll area...
            for(int j=0;j<=modal->rowCount()-1;j++)
            {
                //Assigning the desired information from the previously prepared modals...
            QString str=modal->record(j).value(0).toString();//(username)
            QString str1=modal1->record(j).value(0).toString();//(email)
            QString str2=modal2->record(j).value(0).toString();//phone)

            //Assigning the desired information from the previously prepared modals...

            //Assigning the strings to widgets...
            name[j]=new QPushButton(str);
            QLabel *lab=new QLabel("Email: "+str1+", Phone: "+str2+"."); //Assigning the strings to widgets...
            lab->setStyleSheet("color:white;");
            QFrame *line;

            //Creating horizontal line with desired properties...
            line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            line->setStyleSheet("background:white"); //Creating horizontal line with desired properties...

            //Setting up the pushbutton with the on-hover changes...
            name[j]->setObjectName("btnName_1");
                name[j]->setStyleSheet(
                "   QPushButton#btnName_1 {"
                "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
                " }"
                " QPushButton#btnName_1:hover {"
                "     color: yellow;font-size:25px;"
                " }");                                    //Setting up the pushbutton with the on-hover changes...


            lab->setStyleSheet("background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:white");

             //adding all the widgets to the previously cretaed grid layout...
            lay->addWidget(name[j]);
            lay->addWidget(lab);
            lay->addWidget(line);  //adding all the widgets to the previously cretaed grid layout...


            //connecting the button containg name with the onnameclicked function...
             connect(name[j],SIGNAL(clicked()),this,SLOT(onnameclicked()));
             ui->scrollContents->setLayout(lay);
            }

            //putting the layout inside the scroll area...

            connClose();

            //hiding the frame that will show the profile...
            ui->frame_2->hide();

        ///Loading contents on find dev tab stops

             QString unn=UserData::userName;
             ui->un_p_line->setText(unn);
             QString email=ui->t_pro_em_line->text();
             QString phone=ui->t_pro_phn_line->text();
             ui->phone_p_line->setText(phone);
             ui->email_p_line->setText(email);

}

cprofile::~cprofile()
{
    delete ui;
}

///Loading data on frame 2 when name is clicked Start


QString buttonText;
//assigning zero to the static int created in header...
int cprofile::x=0;
//creating an array of button, vector can be used as well...
QPushButton *pButton[100];

//this is the function that will be called if any name is clicked...
void cprofile::onnameclicked()
{
    //here we are decreasing the width of the frame containing the scroll area so that we  can show the profile...
    //ui->frame->setGeometry(300,50,521,581);

    //making the profile containing frame visible...
    ui->frame_2->show();

    //initializing the previously created button...
    pButton[x]=new QPushButton;

    //recieving the button (name) clicked and assigning it to the pButton[x]...
    pButton[x] = qobject_cast<QPushButton*>(sender());

    //we have increased the value of x by 1 each time. so if the next name is clicked the previous name will go back to the default stylesheet in the codes below...
    if(x>0)
    {

        pButton[x-1]->setObjectName("btnName_1");
        pButton[x-1]->setStyleSheet("   QPushButton#btnName_1 {"
                                    "     background:transparent; Text-align:left;font-family:century gothic;font-size:18px; color:orange;"
                                    " }"
                                    " QPushButton#btnName_1:hover {"
                                    "     color: yellow;font-size:25px;"
                                    " }");
    }


    //style sheet for the clicked button...
    pButton[x]->setStyleSheet("color: yellow;font-size:25px;Text-align:left;font-family:century gothic");

    //assigning the text of the button to the string "buttonText"..
    buttonText = pButton[x]->text();

    // recognize buttonText here
    ui->label_3->setText(buttonText);
    ui->label_3->setStyleSheet("font-family:century gothic;background:transparent;font-size:20px;color:yellow;Text-align:center");

    //fetching the necessary informations from the database and assigning them to the desired labels...
    connOpen();
        QSqlQuery qry;
        qry.prepare("select * from dinfo where username='"+buttonText+"'");
        if(qry.exec())
        while(qry.next()){
            QPixmap pro_pic;
            QString location=qry.value(7).toString();
            pro_pic.load(location);
            ui->label->setPixmap(pro_pic);
            ui->label->setScaledContents(true);
            ui->label_4->setText(""+qry.value(4).toString()+"");
            ui->label_phn->setText(""+qry.value(3).toString()+"");
            ui->label_ad->setText(""+qry.value(6).toString()+"");
            ui->label_em->setText(""+qry.value(2).toString()+"");


        }

        //increment of the value x by 1;
        x++;
    connClose();

///Loading data on frame 2 when name is clicked Stops
}



void cprofile::on_load_pb_clicked()
{
    connOpen();
    QSqlQuery qry;
    QString username=UserData::userName;
     qry.prepare("select * from cinfo where username = '"+username+"'");
     if(qry.exec())
     {
         int count=0;
         while(qry.next())
         {
             ++count;
         }
         if(count==1)
         {
             qDebug()<<"in 1";
             QString u,p,e,ph,a,d,f,pic,r;
             QSqlQuery q("select * from cinfo where username = '"+username+"'");
             while(q.next()) u=q.value(0).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) p=q.value(1).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) e=q.value(2).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) ph=q.value(3).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) f=q.value(4).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) d=q.value(5).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) a=q.value(6).toString();

             q.exec("select * from cinfo where username = '"+username+"'");
             while(q.next()) pic=q.value(7).toString();



             ui->t_pro_un_line->setText(u);
             ui->t_pro_ad_line->setText(a);
             ui->t_pro_em_line->setText(e);
             ui->t_pro_pass_line->setText(p);
             ui->t_pro_phn_line->setText(ph);
             ui->t_pro_dob_line->setText(d);
             ui->t_pro_fn_line->setText(f);



             QPixmap pro_pic;
                         QString location=pic;
                         pro_pic.load(location);
                         ui->label_dp->setPixmap(pro_pic);
                         ui->label_dp->setScaledContents(true);

         }



    connClose();

   }

}

void cprofile::on_savechange_button_clicked()
{
    connOpen();

    if(connOpen())
    {
        QString username = ui->t_pro_un_line->text();
        QString password = ui->t_pro_pass_line->text();
        QString email = ui->t_pro_pass_line->text();
        QString phone = ui->t_pro_phn_line->text();
        QString Full_Name=ui->t_pro_fn_line->text();
        QString DOB = ui->t_pro_dob_line->text();
        QString Address =ui->t_pro_ad_line->text();
        ;

        QSqlQuery qry;
        qry.prepare("update cinfo set password = '"+password+"' , email ='"+email+"' , phone='"+phone+"' , Full_Name='"+Full_Name+"' , DOB = '"+DOB+"' , Address='"+Address+"' where username = '"+username+"'");

        if(qry.exec())
        {
            QMessageBox::information(this,"Updated!","Congratulations!! Successfully Updated.");
        }
        else
            QMessageBox::critical(this,"Not inserted","Not inserted");

    }
    else
     {
        QMessageBox::information(this,"Not Connectrd","Database isn't connected");
     }
    connClose();
}

void cprofile::on_pushButton_clicked()
{
    QMessageBox::information(this, "Sent!","Review Sent. Thanks for co-operating.");
}

void cprofile::on_pushButton_2_clicked()
{
    QMessageBox::information(this, "Sent!","Message Sent. Thanks for co-operating.");
}

void cprofile::on_logout_btn_clicked()
{
    QWidget *new_window=new MainWindow ;
    new_window->show();
    close();
}

void cprofile::on_change_dp_button_clicked()
{
    QString picpath=QFileDialog::getOpenFileName
                (
                    this,
                tr("Open File"),
                "C://",
                "All File (*.*);;JPG File (*.jpg);;PNG File (*.png)"
                    );


    connOpen();
    QSqlQuery qry;
        QString username=ui->t_pro_un_line->text();
        qry.prepare("update cinfo set Pics ='"+picpath+"'where username='"+username+"'");
        if(qry.exec()){

           QMessageBox::information(this,tr("Update Result"),tr("<font color=black>Profile Photo Update Completed"));
        connClose();
        connOpen();

        qry.prepare("select * from cinfo where username='"+username+"'");
        if(qry.exec())
            while(qry.next())
            {
                QPixmap pro_pic;
                QString location=qry.value(10).toString();
                pro_pic.load(location);
                ui->label_dp->setPixmap(pro_pic);
                ui->label_dp->setScaledContents(true);
            }
        connClose();
        }
}

void cprofile::on_post_btn_clicked()
{
    connClose();



    if(connOpen())
    {
        QString username = ui->un_p_line->text();
        QString email = ui->email_p_line->text();
        QString phone = ui->phone_p_line->text();
        QString project_code=ui->pc_p_line->text();
        QString temp = ui->comboBox_2->currentText();
        QString floors =ui->floor_p_line->text();
        QString budget =ui->budget_p_line->text();
        QString amount_for_dev=ui->devf_p_line->text();
        QString location=ui->loc_p_line->text();
        QString note=ui->des_p_line->text();

        QSqlQuery qry;
        qry.prepare("INSERT INTO Jobs (username, project_code, email, phone,temp,location,amount_for_dev,budget,note,floors)"
                    "VALUES(:username,:project_code, :email, :phone, :temp, :location, :amount_for_dev, :budget, :note, :floors)");

        qry.bindValue(":username", username);
        qry.bindValue(":project_code", project_code);
        qry.bindValue(":email", email);
        qry.bindValue(":phone", phone);
        qry.bindValue(":temp", temp);
        qry.bindValue(":location", location);
        qry.bindValue(":amount_for_dev", amount_for_dev);
        qry.bindValue(":budget",budget);
        qry.bindValue(":note",note);
        qry.bindValue(":floors",floors);



        if(qry.exec())
        {
            QMessageBox::information(this,"Posted!","Congratulations!! Successfully posted. Now wait for the response of the developers.");
        }
        else
            QMessageBox::critical(this,"Failed","The request failed. Please change the Projecr Code and try again.");

    }
    else
     {
        QMessageBox::information(this,"Not Connectrd","Database isn't connected");
     }
}

