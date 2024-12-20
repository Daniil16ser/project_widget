#include "english.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    English w;
    w.show();
    return a.exec();
}
