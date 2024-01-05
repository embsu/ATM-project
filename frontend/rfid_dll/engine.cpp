
#include "engine.h"

engine::engine()
{
 qDebug()<<"Nyt ollaan enginen construktorissa";
}

// Alustetaan sarjaportti //

void engine::openSerialPort()
{

    qDebug()<<"Open and initialize serial port";
    port.setPortName("/dev/tty.usbmodem11101");                       // Asetetaan oikea portin numero
    port.setBaudRate(QSerialPort::Baud9600);        // Asetetaan kirjoitusnopeus
    port.setDataBits(QSerialPort::Data8);
    port.setParity(QSerialPort::NoParity);
    port.setStopBits(QSerialPort::OneStop);
    port.setFlowControl(QSerialPort::NoFlowControl);

    if (!port.open(QIODevice::ReadWrite))           // Jos portti ei ole auki tulostetaan virheilmoitus
    {
        qDebug() << "Failed to open serial port";
    }
    else
    {
        qDebug() << "Waiting for RFID card";
        connect(&port,SIGNAL(readyRead()),  // Yhdistetään QSerialportin readyRead() signaali readyToRead slottiin
                this,SLOT(readyToRead()));  // Kun korttia käytetään lukijassa, siirrytään readyToRead slottiin ja tallennetaan kortin data.
    }


}

void engine::readyToRead()
{
    QString cardNumber = port.readAll();                // Luetaan kortin tiedot ja tallennetaan ne muuttujaan cardNumber
    cardNumber.replace("\r\n-", "");                    // Poistetaan ylimääräiset merkit kortin numerosta
    cardNumber.replace("\r\n>", "");                    // Poistetaan ylimääräiset merkit kortin numerosta
    qDebug() << "RFID card detected:" << cardNumber;    // Tulostetaan luettu korrtinumero konsoliin
                        // Välitetään korttinumero sendNumberToRFIDDLL funktiolle parametrinä
    port.close();
    sendNumberToRFIDDLL(cardNumber);// Suljetaan portti
                                      // Poistetaan kortin tiedot muuttujasta cardnumber
    qDebug()<<"Tullaank readyToread emitin jälkeen tänne?";
}

void engine::sendNumberToRFIDDLL(QString cardNumber)
{
    disconnect(&port,SIGNAL(readyRead()),  // Yhdistetään QSerialportin readyRead() signaali readyToRead slottiin
               this,SLOT(readyToRead()));

    qDebug()<<"Engine send card number: "<<cardNumber;
    emit sendCardNumber(cardNumber);

}

