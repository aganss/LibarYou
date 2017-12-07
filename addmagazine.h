#ifndef ADDMAGAZINE_H
#define ADDMAGAZINE_H

#include <QDialog>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class AddMagazine;
}

class AddMagazine : public QDialog
{
    Q_OBJECT

public:
    explicit AddMagazine(QWidget *parent = 0);
    ~AddMagazine();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddMagazine *ui;
};

#endif // ADDMAGAZINE_H
