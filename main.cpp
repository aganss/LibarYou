#include "reader.h"
#include "logindata.h"
#include "addbook.h"
#include "addmagazine.h"
#include "addreader.h"
#include "addreader.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // READER ff;
  //  ff.show();

    LoginData jj;
    jj.show();
    AddBook addBook;
    addBook.show();

    AddMagazine hh;
    hh.show();

    AddReader rrr;
    rrr.show();


    return a.exec();
}
