#include "playlist.h"

Playlist::Playlist()
{
    pName = "Main";
    pLength = 0;
    player->setPlaylist(p);
    tInfo = nullptr;
}

void Playlist::addSong(QString songname)
{
    pLength++;
    if (tInfo == nullptr)
    {
        tInfo = new Track[pLength];
        tInfo[pLength-1].fName = songname;
        QString songsPath = QString(QStandardPaths::writableLocation(QStandardPaths::MusicLocation)) + "/Songs";
        p->addMedia(QUrl(songsPath + "/" + tInfo[pLength-1].fName));
    }
    else
    {
        Track * temp = new Track[pLength];
        for(int i = 0; i < pLength - 1; i++)
        {
            temp[i] = tInfo[i];
        }
        delete[] tInfo;
        tInfo = temp;
        tInfo[pLength-1].fName = songname;
        QString songsPath = QString(QStandardPaths::writableLocation(QStandardPaths::MusicLocation)) + "/Songs";
        p->addMedia(QUrl(songsPath + "/" + tInfo[pLength-1].fName));
    }
}

