#include "menu.h"
#include "ui_menu.h"


Menu::Menu(QWidget *parent, DLLRestAPI* pdllRestApi) :
    QDialog(parent),
    ui(new Ui::Menu),
    pdllRestApi(pdllRestApi)
{
    //Napit
    ui->setupUi(this);
    connect(ui->bAsiakas, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerAsiakas()));
    connect(ui->bKortti, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerKortti()));
    connect(ui->bCredit, SIGNAL(clicked(bool)),
           this, SLOT(clickHandlerCredit()));
    connect(ui->bDebit, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerDebit()));
    connect(ui->bTapahtumat, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerTapahtumat()));
    connect(ui->bSaldo, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerSaldo()));
    connect(ui->bOtto, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerOtto()));

    //**Vastaanotetaan arvot**
    //Taulut
    connect(pdllRestApi, SIGNAL(menuResponseReady(QString)),
            this, SLOT(tables(QString)));
    //Debit Saldo
    connect(pdllRestApi, SIGNAL(saldoReady(QString)),
            this, SLOT(debitSaldo(QString)));
    //Otto
    connect(pdllRestApi, SIGNAL(ottoReady(QString)),
            this, SLOT(otto(QString)));
    //tapahtumat
    connect(pdllRestApi, SIGNAL(tapahtumatReady(QString)),
            this, SLOT(tapahtumat(QString)));

}

Menu::~Menu(){
    delete ui;
}

//Tokenin välitys mainwindowista:
void Menu::getCardNumber(QString kortinnumero) {

    kortti = kortinnumero;
}
//Taulut
void Menu::tables(QString arvot){

    ui->plainTextEdit->setPlainText(arvot);
}
void Menu::debitSaldo(QString arvot){

    ui->plainTextEdit->setPlainText(arvot);
}
void Menu::otto(QString saldo){

    ui->plainTextEdit->setPlainText("Nostetaan: "+nostetaan+" Saldo: " + saldo);
}

void Menu::tapahtumat(QString tapahtumat){
    ui->plainTextEdit->setPlainText(tapahtumat);
}

//Ui napit
void Menu::clickHandlerAsiakas(){

    pdllRestApi->menuRequest("asiakas");
}

void Menu::clickHandlerCredit(){

    tuplaArvo = "credit";
    pdllRestApi->tuplakorttiRequest(tuplaArvo);
}

void Menu::clickHandlerDebit(){

    tuplaArvo = "debit";
    pdllRestApi->tuplakorttiRequest(tuplaArvo);
}

void Menu::clickHandlerKortti(){

    pdllRestApi->menuRequest("kortti");
}

void Menu::clickHandlerSaldo(){

    pdllRestApi->saldoRequest(kortti);
}

void Menu::clickHandlerOtto(){
    nostetaan = "30";
    pdllRestApi->ottoRequest(nostetaan, kortti);
}

void Menu::clickHandlerTapahtumat(){
    pdllRestApi->tapahtumatRequest(kortti);
}


