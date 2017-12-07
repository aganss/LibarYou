#include "addreader.h"
#include "ui_addreader.h"

AddReader::AddReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReader)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->passwordAgain->setEchoMode(QLineEdit::Password);
}

AddReader::~AddReader()
{
    delete ui;
}



void AddReader::on_cansel_clicked()
{
    this->close();
}

void AddReader::on_OK_clicked()
{
    QSqlQuery *query = new QSqlQuery;

    if(ui->password->text()!=ui->passwordAgain->text()){
        QMessageBox::information(this,"Eror","Перевірте пароль!!!",3);
        return;
    }
/*
    query->prepare("INSERT INTO Users(Name,Surname,LastName,Phone,Photo,Email,Login,Password,Status_ID)\
                    VALUES(:Name,:Surname,:LastName,:Phone,:Photo,:Email,:Login,:Password,2)");
    query->bindValue(":Name", ui->Name->text());
    query->bindValue(":Surname", ui->Surname->text());
    query->bindValue(":LastName", ui->LastName->text());
    query->bindValue(":Phone",ui->phone->text());
    query->bindValue(":Photo", photo);
    query->bindValue(":Email", ui->eMail->text());
    query->bindValue(":Login",ui->login->text());
    query->bindValue(":Password", ui->password->text());
*/

}

void AddReader::on_loadImage_clicked()
{
    QString oldPhoto_str = QFileDialog::getOpenFileName(0,"Open Image", "",  tr("Image Files (*.png *.jpg *.bmp)"));
    QFileInfo fileInf(oldPhoto_str);
    photo_str = "C:\\LibrarYou\\" + fileInf.fileName();
    QFile::copy(oldPhoto_str,photo_str);
    ui->photo->setScaledContents(true);
    ui->photo->setPixmap(QPixmap(photo_str));

}
