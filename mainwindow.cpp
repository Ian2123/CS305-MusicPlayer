#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "track.h"

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
    //Add song to playlist data structure and resource file, update list widget
}

// Remove Button Function
void MainWindow::on_remButton_clicked()
{
    //Remove selected (from list widget) song from playlist data structure and resource file, update list widget
}
