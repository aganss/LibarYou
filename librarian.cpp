#include "librarian.h"
#include "ui_librarian.h"

Librarian::Librarian(int ID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Librarian)
{
    ui->setupUi(this);
}

Librarian::~Librarian()
{
    delete ui;
}
