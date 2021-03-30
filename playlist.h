#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "track.h"
#include <QMediaPlaylist>
#include <QStandardPaths>

class Playlist
{
public:
    QString pName;
    int pLength;
    QMediaPlaylist * p = new QMediaPlaylist;
    QMediaPlayer * player = new QMediaPlayer;
    Track * tInfo;

    Playlist();
    void addSong(QString);// adds song to playlist
    void deleteSong();// deletes song from playlist
    void playSort();// sorts playlist
};

#endif // PLAYLIST_H
