/*to make:
 * track to keep info of the song
 * ->Make some kind of input window to edit song info, right now it is done with console commands
 * ->pause song button
 *
   playlist to hold all of the songs
   ->have a way to display added songs
   ->have a way to display current playlist
   ->display current song


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
