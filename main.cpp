#include "wh.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wh w;
    w.show();
    return a.exec();
}
