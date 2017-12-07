#include "reader.h"
#include "ui_reader.h"

READER::READER(int ID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::READER)
{
    ui->setupUi(this);
    this->ID = ID;
    qDebug()<< "\nID= " <<ID;

    QSqlQuery *query = new QSqlQuery;

    query->prepare("SELECT Name,Surname,LastName,Photo FROM Users WHERE ID = :ID");
    query->bindValue(":ID", ID);

    if(!query->exec()){
        qDebug()<< "\nReader data not load!!";
    }
    query->next();
    ui->Name->setText(query->value(0).toString());
    ui->Surname->setText(query->value(1).toString());
    ui->lastname->setText(query->value(2).toString());
    ui->readerPhoto->setScaledContents(true);
    ui->readerPhoto->setPixmap(QPixmap(query->value(3).toString()));

}

READER::~READER()
{
    delete ui;
}

void READER::on_pushButton_clicked()
{
    mod = new QSqlTableModel;
    mod->setTable("Books");
    mod->select();
    ui->tableBooks->setModel(mod);
    ui->tableBooks->show();
}
