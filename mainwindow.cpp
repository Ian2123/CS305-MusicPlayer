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

//Global Variables
QString SONGSPATH = QString(QStandardPaths::writableLocation(QStandardPaths::MusicLocation)) + "/Songs";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    Track test;
    test.getSong();
    test.play();
}

// Pause Button Function
void MainWindow::on_pauseButton_clicked()
{
    //Just pause currently playing song
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
    if(!songDir.exists(SONGSPATH))
        songDir.mkpath(SONGSPATH);

    QStringList inFilenames = QFileDialog::getOpenFileNames(this, tr("Import Tracks"), "", tr("Track (*.mp3)"));
    for(int i = 0; i < inFilenames.size(); i++){
        QFile inFile(inFilenames.at(i));
        QFileInfo inInfo(inFile);
        inFile.copy(SONGSPATH + "/" + inInfo.fileName());
    }

    //Add to playlist linked list
}

// Remove Button Function
void MainWindow::on_remButton_clicked()
{
    QDir songDir;

    // Check if Songs directory exists, if it doesn't exit
    if(!songDir.exists(SONGSPATH)){
        QMessageBox::critical(this, "Remove Tracks", "Songs folder not found, add a track first");
        return;
    }

    QStringList outFilenames = QFileDialog::getOpenFileNames(this, tr("Remove Tracks"), SONGSPATH, tr("Track (*.mp3)"));
    for(int i = 0; i < outFilenames.size(); i++){
        QFile outFile(outFilenames.at(i));
        outFile.remove();
    }

    //Remove from playlist linked list
}
