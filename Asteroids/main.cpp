#include <QtGui/QApplication>
#include "mainwindow.h"
#include "keypress.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyPress *keyPress=new KeyPress();
   // keyPress->show();
    MainWindow w;
    w.show();
    
    return a.exec();
}
