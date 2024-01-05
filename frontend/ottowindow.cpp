#include "ottowindow.h"
#include "ui_ottowindow.h"


OttoWindow::OttoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OttoWindow)
{
    ui->setupUi(this);

    // Nappien connectionit

    connect(ui->btn20euroa, SIGNAL(clicked(bool)),
            this, SLOT(btn20Clicked()));

    connect(ui->btn40euroa, SIGNAL(clicked(bool)),
            this, SLOT(btn40Clicked()));

    connect(ui->btn60euroa, SIGNAL(clicked(bool)),
            this, SLOT(btn60Clicked()));

    connect(ui->btn90euroa, SIGNAL(clicked(bool)),
            this, SLOT(btn90Clicked()));

    connect(ui->btn140euroa, SIGNAL(clicked(bool)),
            this, SLOT(btn140Clicked()));

    connect(ui->btn240euroa, SIGNAL(clicked(bool)),
            this, SLOT(btn240Clicked()));

    connect(ui->btnalkuun, SIGNAL(clicked(bool)),
            this, SLOT(btnAlkuunClicked()));

    connect(ui->btnmuusumma, SIGNAL(clicked(bool)),
            this, SLOT(btnMuusummaClicked()));

    selection="";


}

OttoWindow::~OttoWindow()
{
    delete ui;
}

void OttoWindow::btn20Clicked()
{
    qDebug()<<"Valitsit 20 e";
    selection="20";
    emit OttoSelection(selection);


}

void OttoWindow::btn40Clicked()
{
    qDebug()<<"Valitsit 40 e";
    selection="40";
    emit OttoSelection(selection);

}

void OttoWindow::btn60Clicked()
{
    qDebug()<<"Valitsit 60 e";
    selection="60";
    emit OttoSelection(selection);

}

void OttoWindow::btn90Clicked()
{
    qDebug()<<"Valitsit 90 e";
    selection="90";
    emit OttoSelection(selection);

}

void OttoWindow::btn140Clicked()
{
    qDebug()<<"Valitsit 140 e";
    selection="140";
    emit OttoSelection(selection);

}

void OttoWindow::btn240Clicked()
{
    qDebug()<<"Valitsit 240 e";
    selection="240";
    emit OttoSelection(selection);

}

void OttoWindow::btnAlkuunClicked()
{
    qDebug()<<"Valitsit alkuun";
    selection ="alkuun";
    emit OttoSelection(selection);

}

void OttoWindow::btnMuusummaClicked()
{
    qDebug()<<"Valitsit muu summa";
    selection ="muu summa";
    emit OttoSelection(selection);

}
