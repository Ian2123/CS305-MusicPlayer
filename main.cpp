#include "mainwindow.h"
#include <QSound> //it's not angry when I put this library in, cool
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Music Player");
    w.setMinimumSize(900, 400);
    w.setWindowIcon(QIcon(":/resources/img/mainWindowIcon.png"));
    w.show();
    return a.exec();
}
