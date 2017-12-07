#ifndef READER_H
#define READER_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>

namespace Ui {
class READER;
}

class READER : public QMainWindow
{
    Q_OBJECT

public:
    explicit READER(int ID, QWidget *parent = 0);
    ~READER();

private slots:
    void on_pushButton_clicked();

private:
    Ui::READER *ui;
    QSqlTableModel *mod;
    int ID;
};

#endif // READER_H
