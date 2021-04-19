#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "infowindow.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void updateListWidget(bool);

    void on_actionAdd_triggered();

    void on_actionRemove_triggered();

    void on_actionOpen_Folder_triggered();

    void on_actionExit_triggered();

    void on_actionInfo_triggered();

    void on_tracklistWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actionUpdate_Track_List_triggered();

private:
    Ui::MainWindow *ui;
    InfoWindow *mainIW; //allows access to the main info window (mainIW) on heap, independent of main window.
};
#endif // MAINWINDOW_H
