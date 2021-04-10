#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playlist.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QBrush>
#include <QDesktopServices>

//Global Variables
QString SONGS_PATH = QString(QStandardPaths::writableLocation(QStandardPaths::MusicLocation)) + "/Songs";
Track CURRENT_SONG;
Playlist MAIN_PLAYLIST;
QListWidgetItem * CURRENT_ITEM = nullptr;
bool IS_PLAYING = false;

//Set up main window ui and fill list widget with songs currently in Songs folder
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateListWidget(true);
    CURRENT_SONG.setSong("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Play Button Function
void MainWindow::on_playButton_clicked()
{
    QListWidgetItem * newItem = ui->tracklistWidget->currentItem();
    if (newItem == nullptr) return;
    QString songName = newItem->text();

    if(CURRENT_ITEM != nullptr)
        CURRENT_ITEM->setBackground(QBrush(Qt::white, Qt::SolidPattern));

    //If new song is selected play that new song
    if(songName.compare(CURRENT_SONG.getSongName()) != 0){
        CURRENT_SONG.setSong(songName);
        newItem->setBackground(QBrush(Qt::green, Qt::SolidPattern));
        CURRENT_SONG.play();
    }
    else{
        //Resume currently playing song
        newItem->setBackground(QBrush(Qt::green, Qt::SolidPattern));
        CURRENT_SONG.play();
    }
    CURRENT_ITEM = newItem;
    IS_PLAYING = true;
}

// Pause Button Function
void MainWindow::on_pauseButton_clicked()
{
    if(CURRENT_ITEM == nullptr) return;
    CURRENT_ITEM->setBackground(QBrush(Qt::yellow, Qt::SolidPattern));
    CURRENT_SONG.pause();
    IS_PLAYING = false;
}

//Double click play/pause functionality
void MainWindow::on_tracklistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(item == CURRENT_ITEM)
        on_pauseButton_clicked();
    else
        on_playButton_clicked();
}

// Shuffle Button Function
void MainWindow::on_shuffleButton_clicked()
{

}

// Add Track toolbar action
void MainWindow::on_actionAdd_triggered()
{
    QDir songDir;

    // Check if Songs directory exists, if not create it
    if(!songDir.exists(SONGS_PATH))
        songDir.mkpath(SONGS_PATH);

    //Retrieve files, copy to songs dir, add to list.
    QStringList inFilenames = QFileDialog::getOpenFileNames(this, tr("Import Tracks"), "", tr("Track (*.wav *.mp3 *.m4a)"));
    if(inFilenames.size() == 0) return; //If no files selected
    for(int i = 0; i < inFilenames.size(); i++){
        QFile inFile(inFilenames.at(i));
        QFileInfo inInfo(inFile);
        inFile.copy(SONGS_PATH + "/" + inInfo.fileName());
    }
    updateListWidget(false);
}

// Remove Track toolbar action
void MainWindow::on_actionRemove_triggered()
{
    QDir songDir;

    // Check if Songs directory exists, if it doesn't exit
    if(!songDir.exists(SONGS_PATH)){
        QMessageBox::critical(this, "Remove Tracks", "Songs folder not found, try adding a track first");
        return;
    }

    //Retrieve files and remove
    QStringList outFilenames = QFileDialog::getOpenFileNames(this, tr("Remove Tracks"), SONGS_PATH, tr("Track (*.wav *.mp3 *.m4a)"));
    if(outFilenames.size() == 0) return; //if no files selected
    for(int i = 0; i < outFilenames.size(); i++){
        QFile outFile(outFilenames.at(i));
        QFileInfo outInfo(outFile);

        //If song is currently playing don't remove
        if(CURRENT_SONG.getSongName().compare(outInfo.fileName()) == 0){
            QMessageBox::critical(this, "Remove Tracks", "Song " + CURRENT_SONG.getSongName() + " is currently playing.");
            continue;
        }
        outFile.remove();
    }
    updateListWidget(false);
}

// Open Folder toolbar action
void MainWindow::on_actionOpen_Folder_triggered()
{
    QDesktopServices::openUrl(SONGS_PATH);
}

// Info tool bar action
void MainWindow::on_actionInfo_triggered()
{
    //Modal-less approach, place info window on heap to access simultaneously with main window.
    mainIW = new InfoWindow(0);
    mainIW->setWindowTitle("Music Player Information");
    mainIW->setWindowIcon(QIcon(":/resources/img/mainWindowIcon.png"));
    mainIW->setWindowFlags(Qt::Window);
    mainIW->setFixedSize(700,400);
    mainIW->show();
}

// Exit toolbar action
void MainWindow::on_actionExit_triggered()
{
    if(IS_PLAYING) CURRENT_SONG.pause();
    QApplication::quit();
}

// Used to update track list widget to show tracks currently in Songs folder
void MainWindow::updateListWidget(bool startup){
    QDir songsFolder(SONGS_PATH);
    QStringList tracksCurrentlyInFolder = songsFolder.entryList(QStringList(), QDir::Files);

    ui->tracklistWidget->clear();
    foreach(QString filename, tracksCurrentlyInFolder){
        ui->tracklistWidget->addItem(filename);
    }

    if(!startup && CURRENT_SONG.getSongName().compare("") != 0){
        QList<QListWidgetItem *> playItem = ui->tracklistWidget->findItems(CURRENT_SONG.getSongName(), 0);
        CURRENT_ITEM = playItem[0];
        if(IS_PLAYING)
            CURRENT_ITEM->setBackground(QBrush(Qt::green, Qt::SolidPattern));
        else
            CURRENT_ITEM->setBackground(QBrush(Qt::yellow, Qt::SolidPattern));
    }
}
