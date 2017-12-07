#include "addmagazine.h"
#include "ui_addmagazine.h"

AddMagazine::AddMagazine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMagazine)
{
    ui->setupUi(this);
}

AddMagazine::~AddMagazine()
{
    delete ui;
}

void AddMagazine::on_buttonBox_accepted()
{
    QSqlQuery *query = new QSqlQuery;
    query->prepare("INSERT INTO Magazines (NameMagazine,NameEdition,ReleaseDate,NumberOfPages,Availability_ID)\
                                    Values(:NameMagazine,:NameEdition,:ReleaseDate,:NumberOfPages,1)");

    query->bindValue(":NameMagazine",ui->NameMagazine->text());
    query->bindValue(":NameEdition", ui->NameEdition->text());
    query->bindValue(":ReleaseDate",ui->ReleaseDate->text());
    query->bindValue(":NumberOfPages",ui->NumberOfPages->text().toInt());


    if(query->exec()){
        qDebug()<<"Magazine is add";
    }
}
