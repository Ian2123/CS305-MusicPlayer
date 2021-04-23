#include "track.h"
#include <QString>
#include <QStandardPaths>

Track::Track()
{
    fName = "";
}

void Track::play(int vol)
{
    song->setVolume(vol);
    song->play();
}

void Track::setSong(QString songName)
{
    fName = songName;
    QString songsPath = QString(QStandardPaths::writableLocation(QStandardPaths::MusicLocation)) + "/Songs";
    song->setMedia(QUrl(songsPath + "/" + fName));
}

void Track::pause(){
    song->pause();
}

QString Track::getSongName(){
    return fName;
}

void Track::setVolume(int vol){
    song->setVolume(vol);
}
