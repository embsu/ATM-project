#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pdllRestApi = new DLLRestAPI();
    pMenu = new Menu(this, pdllRestApi);

    //Clickhandler
    connect(ui->nappi, SIGNAL(clicked(bool)),
            this, SLOT(loginClicked()));
    //DLL:stä tänne
    connect(pdllRestApi, SIGNAL(httpResponseReady(bool, bool, QString)),
            this, SLOT(loginStatus(bool, bool, QString)));
}

MainWindow::~MainWindow(){
    delete ui;
}
//Login painallus
void MainWindow::loginClicked(){
    kortinnumero = ui->korttinumero->text();
    pinnumero = ui->pinnumero->text();
    pdllRestApi->loginRequest(kortinnumero,pinnumero);
}

//Vastaanotetaan tokeni dll:stä ja tarkistetaan.
void MainWindow::loginStatus(bool status, bool serverStatus, QString kortinTyyppi){
    if (status == true && serverStatus == true) {
        setWindowTitle("True");
        ui->status->setText("Login OK");
        qDebug() << kortinTyyppi;
        //Kortin tiedot etiäppäin
        pMenu->getCardNumber(kortinnumero);
        pMenu->open();
    } else if (status == false && serverStatus == false) {
        ui->status->setText("Server problem");
    } else {
        setWindowTitle("False");
        ui->status->setText("Wrong username / Password");
    }

}
//Tofin tekemä!! 5/5
//Login attempts
/*
    if (status == true) {
          setWindowTitle("Login OK");
          ui->status->setText("True");
          //Web tokeni arvot etiäppäin
    } else if(attempts > 0){
          ui->status->setText("False");
          ui->pinnumero->clear();
          ui->korttinumero->clear();
            setWindowTitle("Login attempts left: " + QString::number(attempts));
    } else if(attempts==0) {
          ui->status->setText("Kortti lukittu");
          ui->pinnumero->clear();
          ui->korttinumero->clear();
          setWindowTitle("Contact Customer Service");
    }
*/
