#include "mainexewindow.h"
#include "ui_mainexewindow.h"
#include <QDebug>

mainexewindow::mainexewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainexewindow)
{

    ui->setupUi(this);



  // Mainexen nappien connectionit:
    connect(ui->btnOtto, SIGNAL(clicked(bool)),
            this, SLOT(btnOttoHandler()));

    connect(ui->btnSaldo, SIGNAL(clicked(bool)),
            this, SLOT(btnSaldoHandler()));

    connect(ui->btnTapahtumat, SIGNAL(clicked(bool)),
            this, SLOT(btnTapahtumatHandler()));

    connect(ui->btnTilisiirto, SIGNAL(clicked(bool)),
            this, SLOT(btnTilisiirtoHandler()));

    connect(ui->btnKirjauduulos, SIGNAL(clicked(bool)),
            this, SLOT(btnKirjauduulosHandler()));

    connect(ui->btnsulje, SIGNAL(clicked(bool)),
            this, SLOT(btnsuljeHandler()));

}

mainexewindow::~mainexewindow()
{
    delete ui;
}

void mainexewindow::btnOttoHandler()
{
  qDebug()<<"Painoit otto nappia";
  cardType="";
  event="Otto";
  emit sendEventToMainwindow(event);

}

void mainexewindow::btnSaldoHandler()
{
    qDebug()<<"Painoit saldo nappia";
    event="Saldo";
    emit sendEventToMainwindow(event);
}

void mainexewindow::btnTapahtumatHandler()
{
    qDebug()<<"Painoit tapahtumat nappia";
    event="Tapahtumat";
    emit sendEventToMainwindow(event);
}

void mainexewindow::btnTilisiirtoHandler()
{
    qDebug()<<"Painoit tilisiirto nappia";
    event="Tilisiirto";
    emit sendEventToMainwindow(event);
}

void mainexewindow::btnKirjauduulosHandler()
{
       qDebug()<<"Painoit kirjaudu ulos nappia";
       event="Kirjaudu ulos";
       emit sendEventToMainwindow(event);

}

void mainexewindow::btnsuljeHandler()
{
    qDebug()<<"Painoit sulje nappia";
    event="sulje";
    emit sendEventToMainwindow(event);


}




