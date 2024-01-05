
#include "rfid_dll.h"




void Rfid_dll::cardNumberReceived(QString cardNumber)   // Vastaanotetaan korttinumero enginen sendCardNumber -signaalin välittämnä
{
    //pEngine->deleteLater();
    qDebug()<<"RFID reader received card number: "<<cardNumber;
    emit sendCardNumber(cardNumber);                    // Lähetetään korttinumero exelle
}


Rfid_dll::Rfid_dll(QObject *parent)
{
    qDebug()<<"Nyt ollaan rfid konstruktorissa";
    pEngine = new engine;
    connect(this,SIGNAL(requestCardNumberFromEngine()),
            pEngine,SLOT(openSerialPort()));
}

void Rfid_dll::requestCardNumberSlot()
{
    connect(pEngine,SIGNAL(sendCardNumber(QString)),    // Yhdistetään sendCardNumber signaali cardNumberReceived slottiin
            this, SLOT(cardNumberReceived(QString)));
    qDebug()<<"open RFIDReader";
    emit requestCardNumberFromEngine();
}
