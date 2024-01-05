#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//////////////PIN UI ALKAA/////////////////////////////////////////
//------------OPEN ikkunan avaus, voi poistaa myöhemmin-------
    setWindowTitle("Open");
    connect(ui->pushButtonOpen,SIGNAL(clicked(bool)),
            this,SLOT(openHandler()));

//-----------YHDISTETÄÄN DLL SIGNAALI ETTÄ SAADAAN TUOTUA PIN---------
    pPinUiNappis = new pinUInappis(this);

    connect(pPinUiNappis, &pinUInappis::isThePinCorrect,      //vastaanotetaan signaali DLL:ltä
            this,&MainWindow::exeIsThePinCorrect);            //joka lähettää PINin

//---------------Timeri-------------------------------------------
    pClosePinUiTimer = new QTimer(this);                // PIN UI sulkeutumis pointteri
    connect(pClosePinUiTimer, SIGNAL(timeout()),
            this, SLOT(closePinUi()));
    pClosePinUiTimer->setInterval(5000);    // 5 sec timer

//////////////PIN UI LOPPUU/////////////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pPinUiNappis;
    delete pClosePinUiTimer;
}

void MainWindow::openHandler()
{
    pPinUiNappis->open();
}

void MainWindow::closePinUi()
{
    close();
}

void MainWindow::exeIsThePinCorrect(QString enteredPin)
{
//------------Tarkistetaan onko pin oikein-----------
    qDebug() << "Pin vastaanotettu ja se tarkistetaan";

    if (enteredPin == correctPin)               //correctPin korvataan databasen pinillä
    {
         qDebug() << "Pin oikein, ohjetekstit DLL:lle";

         pPinUiNappis->receiveMessageToLabel("PIN CORRECT");
         pPinUiNappis->receiveMessageToLabel_2("<font color='green'>Connecting to Pirkka Pankki</font>");
     }

    else
    {
        pinAttempts--;
        qDebug() << "Pin väärin, ohjetekstit DLL:lle";
        pPinUiNappis->receiveMessageToLabel("Incorrect PIN");

        pPinUiNappis->receiveMessageToLabel_2(QString("Incorrect PIN! Attempts left: %1").arg(pinAttempts));

        if (pinAttempts == 0)            // kun arvauksia ei enää jäljellä
        {

               pClosePinUiTimer->start();        //timer ikkunan sulkeutumiseen alkaa
               pPinUiNappis->receiveMessageToLabel("CARD LOCKED");
               pPinUiNappis->receiveMessageToLabel_2("Closing the window...");

        }
    }
}

