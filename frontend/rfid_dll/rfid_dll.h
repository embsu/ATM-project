#ifndef RFID_DLL_H
#define RFID_DLL_H

#include <QObject>
#include "engine.h"



class Rfid_dll : public QObject
{
    Q_OBJECT
public:
    Rfid_dll(QObject * parent);
private:
    engine * pEngine;
signals:
    void sendCardNumber(QString cardNumber);
    void requestCardNumberFromEngine();
public slots:
    void requestCardNumberSlot();
private slots:
    void cardNumberReceived(QString cardNumber);
};

#endif // RFID_DLL_H
