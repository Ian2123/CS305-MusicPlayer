#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Music Player");
    w.setMinimumSize(700, 400);
    w.setWindowIcon(QIcon(":/resources/img/mainWindowIcon.png"));
    w.show();
    return a.exec();
}
