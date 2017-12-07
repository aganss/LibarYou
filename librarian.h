#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <QMainWindow>

namespace Ui {
class Librarian;
}

class Librarian : public QMainWindow
{
    Q_OBJECT

public:
    explicit Librarian(int ID, QWidget *parent = 0);
    ~Librarian();

private:
    Ui::Librarian *ui;
};

#endif // LIBRARIAN_H
