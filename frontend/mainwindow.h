#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


#include "mainexewindow.h"
#include "rfid_dll.h"
#include "pinuinappis.h"
#include "dllrestapi.h"


#include "ottowindow.h"
#include "creditordebitwindow.h"
#include "receiptselection.h"
#include "takemoney.h"
#include "receiptwindow.h"
#include "otheramount.h"
#include "saldowindow.h"
#include "transactionwindow.h"
#include "transferwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

/////////////////////////////////////////////////
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
///////////////////////////////////////////////

private:
    Ui::MainWindow *ui;
//-------tilakone-----------------------//

    int state;
    void stateMachine();
//-------RFDI DLL--------------------//
    Rfid_dll * pRFIDReader;
    QString kortinNumero;
//-------Pin UI DLL-----------------------//
    pinUInappis * ppinuinappis;
    QString pinNumero;
//-------Timer PIN UI:lle ja Ota rahat sekä kuitti---------------//
    QTimer *pClosePinUiTimer;
    QTimer *pCloseTakeMoney;
    QTimer *pCloseTakeMoney2;
    QTimer *pCloseReceiptWindow;
    QTimer *pCloseReceiptWindow2;
//--------Rest API --------------------//

    DLLRestAPI * pDLLRestAPI;
    bool statusToStateMachine;
    bool  serverStatusToStateMachine;
    QString cardType;
    QString updatedOttoSaldo;

//------Mainwexewindow--------------
    mainexewindow * pmainexewindow;

//------Login attemps --------------

    int attemps;

//------ Debit/credit valinta----------//
    creditordebitwindow *pcreditordebit;
    QString selectionFromCreditOrDebit;

//------ Nostettava summa ----------- //

    OttoWindow *pOttoWindow;
    QString OttoSelection;

//----- valittu Mainexe Window tapahtuma -----------//

    QString eventToMainwindow;

//----- Halutaanko kuitti ------------//

  receiptSelection * preceiptSelection;
  QString selectionFromReceipt;

//---- Ota rahat näyttö ----------------

    TakeMoney *ptakeMoney;

//---- Kuitti näyttö --------------------

    receiptwindow * preceiptwindow;

// ----- Muu summa --------------------

    OtherAmount * pOtherAmount;
    QString otherAmountToExe;

// ---- Initialize ------------------

    void initialize();

 //--- Saldo ikkuna -----------------

    saldowindow *psaldowindow;

// ---- Tapahtumat ikkuna --------------
    transactionwindow *ptapahtumat;

// ----- Tilisiirto ikkuna -----------
    transferwindow *ptilisiirto;

//////////////////////////////////////////////////////
signals:

//------Rest API -------------
    void sendToExe(QString,QString);

    void sendArvotToSaldoWindow(QString);

//----- RFDI DLL ---------------------

    void requestCardNumber();
    void sendUpdatedSaldoToReceiptWindow(QString,QString);
    void sendDebitTapahtumatToTapahtumatWindow(QString);

// Tilinkate ei riitä virhe signaali

    void sendErrorToReceiptWindow();

/////////////////////////////////////////////////////////
private slots:

//----- RFDI DLL ---------------------
    void receiveCardNumber(QString cardNumber);
    void requestCardNumberSlot();


// ----PIN UI DLL---------------------

    void exeIsThePinCorrect(QString);
    void closePinUi();

//Vastaanotetaan mainexewindowilta credit/debit valinta sekä summa

    void receiveSelectionFromCreditOrDebit(QString);

// Vastaanotetaan mainexewindowilla event

    void sendEventToMainwindowSlot(QString);

//Vastaanotetaan summa otto windowilta

    void receiveSelectionFromOtto(QString);

//Vastaanotetaan vastaus receiptilta

    void receiveSelectionFromReceipt(QString);

// Sulje Ota rahat ikkunan timeria varten

    void closeReceiptWindow();

    void closeTakeMoney();

// Sulje kuitti slotti timeria varten

// Slotti tuomaan othetamount summa

    void receiveOtherAmount(QString);

// Slotti sulje kuitti ikkuna 2//////

    void CloseReceiptWindow2();
/////////////////////////////////////////////////////
public slots:

//-----Rest API DLL--------------

    void loginStatus(bool, bool, QString);
    void debitSaldo(QString);
    void otto(QString);
    void tapahtumatDebit(QString);
};
#endif // MAINWINDOW_H
