#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("INSERT INTO Books(NameBook,Author,NameEdition,YearOfPublication,NumberOfPages,Availability_ID)\
                             Values (:NameBook,:Author,:NameEdition,:YearOfPublication,:NumberOfPages,1)");
    query->bindValue(":NameBook",ui->NameBook->text());
    query->bindValue(":Author",ui->Author->text());
    query->bindValue(":NameEdition",ui->NameEdition->text());
    query->bindValue(":YearOfPublication",ui->YearOfPublication->text().toInt());
    query->bindValue(":NumberOfPages",ui->NumberOfPages->text().toInt());


    if(query->exec()){
        qDebug()<<"Book add";
    }
}
