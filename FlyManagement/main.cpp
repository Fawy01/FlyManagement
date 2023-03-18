#include <QApplication>
#include "mainwindow.h"
#include "controller.h"
#include "model.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Controller c;
    Model m;
    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
