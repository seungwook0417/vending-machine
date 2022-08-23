#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //Widget w2;
    w.show();
    //w2.show();
    return a.exec();
}
