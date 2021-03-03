#include "track.h"

Track::Track()
{
    tTitle = "";
    tArtist = "";
    tAlbum = "";
    fName = "";
}

void Track::editTrack()
{
    string input = "";
    char choice = 'X';
    while(choice != 'Q')
    {

    }
}

void Track::play()
{
    song->setVolume(50);
    song->play();
}

void Track::getSong()
{
    fName = "qrc:/resources/songs/Africa.mp3";
    song->setMedia(QUrl(fName));
}
