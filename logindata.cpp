#include "logindata.h"
#include "ui_logindata.h"
#include <QDebug>

LoginData::LoginData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginData)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    //std::cout<<"dfdf";

    db = QSqlDatabase::addDatabase("QODBC");
//    db.setHostName("localhost");

    db.setDatabaseName("DRIVER={Sql Server};SERVER=DESKTOP-J77983I;DATABASE=LibrarYouDB");
    //db.userName("Петро");

    QMessageBox ff;
    if(db.open()){
        //QMessageBox::information("open");
        ff.setText("open");
        ff.show();
        qDebug()<<"Database is  open";
    }
    else{
        qDebug()<<"Database is not open";
    }

}

LoginData::~LoginData()
{
    delete ui;
}


void LoginData::on_buttonBox_accepted()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    QSqlQuery query = QSqlQuery(db);

       query.prepare("SELECT ID, Status_ID FROM Users WHERE Login = :Login AND Password = :Password");
       query.bindValue(":Login",login);
       query.bindValue(":Password",password);
       if(query.exec()){
           query.next();
           userID = query.value(0).toInt();
           statusID = query.value(1).toInt();
           qDebug() << "\n\nIID"<< userID;
       }
       OpenInterfase();

}

void LoginData::OpenInterfase()
{
   /* switch (userID) {
    case 1:
        librarianInterfase = new Librarian;
        librarianInterfase ->show();
        break;
    case 2:
        readerInterfase = new READER;
        readerInterfase->show();
        break;
    default:
        break;
    }*/

    if(statusID==1){
        librarianInterfase = new Librarian(userID);
        librarianInterfase ->show();
    }
    else{
        readerInterfase = new READER(userID);
        readerInterfase->show();
    }

}
