#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include "engine.h"
#include <QDebug>
#include <QObject>

class DLLRESTAPI_EXPORT DLLRestAPI: public QObject
{
    Q_OBJECT
public:
    DLLRestAPI();
signals:
    //login
    void httpResponseReady(bool, bool, QString);
    void sendToEngine(QString, QString);
    //menu
    void sendMenuToEngine(QString, QString); //Token
    void menuResponseReady(QString); //menutaulut
    void saldoReady(QString); //Saldo (debit tai credit)
    void ottoReady(QString); //Otto
    void tapahtumatReady(QString);
public slots:
    //login
    void statusLoginRequest(bool, bool, QString);
    void loginRequest(QString, QString);
    //Vastaanotetaan
    void menuRequest(QString);
    void saldoRequest(QString);
    void ottoRequest(QString, QString);
    void tapahtumatRequest(QString);
    void tuplakorttiRequest(QString);
    //Lähetetään
    void menuValues(QString);
    void debitSaldo(QString);
    void otto(QString);
    void tapahtumat(QString);
private:
    engine * pEngine;
};

#endif // DLLRESTAPI_H
