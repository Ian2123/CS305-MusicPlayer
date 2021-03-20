#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "track.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QBrush>

//Global Variables
QString SONGS_PATH = QString(QStandardPaths::writableLocation(QStandardPaths::MusicLocation)) + "/Songs";
Track CURRENT_SONG;
QListWidgetItem * CURRENT_ITEM = nullptr;

//Set up main window ui and fill list widget with songs currently in Songs folder
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateListWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Info Button Function
void MainWindow::on_infoButton_clicked()
{
    //Modal-less approach, place info window on heap to access simultaneously with main window.
    mainIW = new InfoWindow(0);
    mainIW->setWindowTitle("Music Player Information");
    mainIW->setWindowIcon(QIcon(":/resources/img/mainWindowIcon.png"));
    mainIW->setWindowFlags(Qt::Window);
    mainIW->setFixedSize(700,400);
    mainIW->show();
}

// Play Button Function
void MainWindow::on_playButton_clicked()
{
    QListWidgetItem * newItem = ui->tracklistWidget->currentItem();
    QString songName = newItem->text();

    //If new song is selected play that new song
    if(songName.compare(CURRENT_SONG.getSongName()) != 0){
        CURRENT_SONG.getSong(songName);
        CURRENT_SONG.play();
        if(CURRENT_ITEM != nullptr)
            CURRENT_ITEM->setBackground(QBrush(Qt::white, Qt::SolidPattern));
        newItem->setBackground(QBrush(Qt::green, Qt::SolidPattern));
        CURRENT_ITEM = newItem;
    }
    else{
        //Resume currently playing song
        CURRENT_ITEM->setBackground(QBrush(Qt::green, Qt::SolidPattern));
        CURRENT_SONG.play();
    }
}

// Pause Button Function
void MainWindow::on_pauseButton_clicked()
{
    CURRENT_ITEM->setBackground(QBrush(Qt::yellow, Qt::SolidPattern));
    CURRENT_SONG.pause();
}

// Shuffle Button Function
void MainWindow::on_shuffleButton_clicked()
{

}

// Add Button Function
void MainWindow::on_addButton_clicked()
{
    QDir songDir;

    // Check if Songs directory exists, if not create it
    if(!songDir.exists(SONGS_PATH))
        songDir.mkpath(SONGS_PATH);

    QStringList inFilenames = QFileDialog::getOpenFileNames(this, tr("Import Tracks"), "", tr("Track (*.mp3)"));
    for(int i = 0; i < inFilenames.size(); i++){
        QFile inFile(inFilenames.at(i));
        QFileInfo inInfo(inFile);
        inFile.copy(SONGS_PATH + "/" + inInfo.fileName());
    }
    updateListWidget();
}

// Remove Button Function
void MainWindow::on_remButton_clicked()
{
    QDir songDir;

    // Check if Songs directory exists, if it doesn't exit
    if(!songDir.exists(SONGS_PATH)){
        QMessageBox::critical(this, "Remove Tracks", "Songs folder not found, try adding a track first");
        return;
    }

    QStringList outFilenames = QFileDialog::getOpenFileNames(this, tr("Remove Tracks"), SONGS_PATH, tr("Track (*.mp3)"));
    for(int i = 0; i < outFilenames.size(); i++){
        QFile outFile(outFilenames.at(i));
        outFile.remove();
    }
    updateListWidget();
}

//Used to update track list widget to show tracks currently in Songs folder
void MainWindow::updateListWidget(){
    QDir songsFolder(SONGS_PATH);
    QStringList tracksCurrentlyInFolder = songsFolder.entryList(QStringList(), QDir::Files);
    ui->tracklistWidget->clear();
    foreach(QString filename, tracksCurrentlyInFolder){
        ui->tracklistWidget->addItem(filename);
    }
}
