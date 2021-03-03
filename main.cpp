/*to make:
 * track to keep info of the song
   playlist to hold all of the songs

   Note: QMediaPlayer does have functions to keep a lot of that info, but it does all the functions that we plan to have automatically
        Therefore, we will try to make our own playlist
*/

#include "mainwindow.h"
#include "track.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Track test;

    test.getSong();
    test.play();

    w.setWindowTitle("Music Player");
    w.setMinimumSize(900, 400);
    w.setWindowIcon(QIcon(":/resources/img/mainWindowIcon.png"));
    w.show();
    return a.exec();
}
