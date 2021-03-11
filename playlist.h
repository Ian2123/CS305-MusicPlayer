#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "track.h"



class Playlist
{
public:
    QString pName;
    int pLength;
    struct Node{
        Track track;
        struct Node * next;
        struct Node * prev;
    };

    Playlist();
    void addSong();// adds song to playlist
    void deleteSong();// deletes song from playlist
    void playSort();// sorts playlist
};

#endif // PLAYLIST_H
