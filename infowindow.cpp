#include "infowindow.h"
#include "ui_infowindow.h"
#include <QMessageBox>

InfoWindow::InfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoWindow)
{
    ui->setupUi(this);
}

InfoWindow::~InfoWindow()
{
    delete ui;
}
void InfoWindow::on_qtInfoButton_clicked() //Display qt info box
{
    QMessageBox::aboutQt(this, "Qt Information");
}

void InfoWindow::on_okButton_clicked() //Close info window
{
    this->close();
}
