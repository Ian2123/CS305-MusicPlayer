#include "playlist.h"

Playlist::Playlist()
{
    pName = "Main";
    pLength = 0;
    First = NULL;
    Last = NULL;
}

void Playlist::addSong(QString fName)
{
    struct Node * newTrack =(struct Node*) malloc(sizeof(struct Node));;
    newTrack->track.getSong(fName);
    if (First == NULL)
    {
        First = newTrack;
        Last = newTrack;
    }
    else
    {
        newTrack->next = First;
        First->prev = newTrack;
        newTrack->prev = NULL;
        First = newTrack;
    }

}

