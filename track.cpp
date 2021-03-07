#include "track.h"

Track::Track()
{
    tTitle = "";
    tArtist = "";
    tAlbum = "";
    fName = "";
}

void Track::editTrack()//this function is a placeholder function to change song info, maybe make it a window that does this
{
    string input = "";
    char choice = 'X';
    while(choice != 'Q' && choice != 'q')
    {
        cout << "What would you like to change?" << endl
             << "A: Title" << endl
             << "B: Artist" << endl
             << "C: Album" << endl
             << "Q: Quit song info editor" << endl;

        switch(choice)
        {
        case 'A':
        case 'a':
            cout << "Please input the song title" << endl;
            cin >> input;
            tTitle = QString::fromStdString(input);
            break;
        case 'B':
        case 'b':
            cout << "Please input the song artist" << endl;
            cin >> input;
            tArtist = QString::fromStdString(input);
            break;
        case 'C':
        case 'c':
            cout << "Please input the song's album" << endl;
            cin >> input;
            tAlbum = QString::fromStdString(input);
            break;
        case 'Q':
        case 'q':
            cout << endl;
            break;
        default:
            cout << "Please input one of the options" << endl << endl;
        }

        cout << endl;
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
