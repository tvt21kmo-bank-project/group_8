#include "mainwindow.h"
#include "menu.h"
#include "creditvaidebit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
