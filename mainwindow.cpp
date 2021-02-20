#include "mainwindow.h"
#include "ui_mainwindow.h"

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

// MainWindow slot for when info button is clicked.
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
