#ifndef LOGINDATA_H
#define LOGINDATA_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include <QString>


#include "reader.h"
#include "librarian.h"

namespace Ui {
class LoginData;
}

class LoginData : public QDialog
{
    Q_OBJECT

public:
    explicit LoginData(QWidget *parent = 0);
    ~LoginData();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::LoginData *ui;
    QSqlDatabase db;
    int userID, statusID;
    READER *readerInterfase;
    Librarian *librarianInterfase;


private:
    void OpenInterfase();


};

#endif // LOGINDATA_H
