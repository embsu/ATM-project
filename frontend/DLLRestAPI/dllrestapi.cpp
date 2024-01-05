#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(){

    pEngine = new engine();

    //Enginestä interfaceen login tilanne. Ensimmäinen bool viittaa kirjautumistietoihin. Toinen bool serverin tilaan.
    connect(pEngine, SIGNAL(httpResponseReady(bool, bool, QString)),
            this, SLOT(statusLoginRequest(bool, bool, QString)));
    //Enginen menu taulut
    connect(pEngine, SIGNAL(sendMenuToInterface(QString)),
            this, SLOT(menuValues(QString)));
    //Enginen debitsaldo
    connect(pEngine, SIGNAL(sendSaldoToInterface(QString)),
            this, SLOT(debitSaldo(QString)));
    //Enginen otto
    connect(pEngine, SIGNAL(sendOttoToInterface(QString)),
            this, SLOT(otto(QString)));
    //Tapahtumat
    connect(pEngine, SIGNAL(sendTapahtumatToInterface(QString)),
            this, SLOT(tapahtumat(QString)));
    //Tilisiirto
}
//Login request tähän exestä
void DLLRestAPI::loginRequest(QString kortinnumero, QString pinnumero){

    pEngine->loginAccess(kortinnumero, pinnumero);
}
//Menu taulut request tähän exestä
void DLLRestAPI::menuRequest(QString valinta){

    pEngine->menu(valinta);
}
//Menu saldo (Debit tai Credit) request tähän exestä
void DLLRestAPI::saldoRequest(QString kortinnumero){
    pEngine->saldo(kortinnumero);
}
//Menu otto request tähän exestä
void DLLRestAPI::ottoRequest(QString maara, QString kortinnumero){
    pEngine->otto(maara, kortinnumero);
}
void DLLRestAPI::tapahtumatRequest(QString kortti){
    qDebug()<<"Vastaanotetaanko pyyntö tapahtumista exeltä?";
    pEngine->tapahtumat(kortti);
}

void DLLRestAPI::tuplakorttiRequest(QString tilityyppi){
    pEngine->tuplakorttiAlustus(tilityyppi);
}
//EXELLE
//Token. (Menee mainiin)
void DLLRestAPI::statusLoginRequest(bool status, bool serverStatus, QString kortinTyyppi){

    emit httpResponseReady(status, serverStatus, kortinTyyppi);
}

//Menutaulujen arvot (Menee menuun)
void DLLRestAPI::menuValues(QString arvot){

    emit menuResponseReady(arvot);
}
//Debit Saldo (Menee menuun)
void DLLRestAPI::debitSaldo(QString arvo){

    emit saldoReady(arvo);
}
//Otto (Menee menuun)
void DLLRestAPI::otto(QString arvo){

    emit ottoReady(arvo);
}
//tapahtumat (Menee menuun)
void DLLRestAPI::tapahtumat(QString tapahtumat){
    qDebug()<<"Tullaako lähettämään tapahtumat?";
    emit tapahtumatReady(tapahtumat);
}


