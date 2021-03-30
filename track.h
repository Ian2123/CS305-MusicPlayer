#ifndef TRACK_H
#define TRACK_H
#include <QMediaPlayer> //will be used to do basic media fuctions, pause/play/duration
#include <QString>
#include <iostream>
using namespace std;

class Track
{
private:
    QString tArtist, tAlbum, tTitle;
    QMediaPlayer * song = new QMediaPlayer;
public:
    QString fName;

    Track();
    void editTrack(); //edits track information: Title, Artist, Album
    void play(); //plays song
    void pause();
    QString getSongName();
    void setSong(QString); //gets song from user input path -> or from file selection if we can figure that out
};

#endif // TRACK_H
