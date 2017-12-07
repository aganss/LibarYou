#ifndef ADDREADER_H
#define ADDREADER_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <string>
#include <QPixmap>
#include <QFileInfo>

namespace Ui {
class AddReader;
}

class AddReader : public QDialog
{
    Q_OBJECT

private:
    QString photo_str;


public:
    explicit AddReader(QWidget *parent = 0);
    ~AddReader();

private slots:

    void on_cansel_clicked();

    void on_OK_clicked();

    void on_loadImage_clicked();


private:
    Ui::AddReader *ui;
   // std::string photo;
};

#endif // ADDREADER_H
