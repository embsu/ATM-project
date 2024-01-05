#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_pinuinappis.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pmainexewindow = new mainexewindow(this);

 ////////////////// MAIN WINDOW KORTTI GIF ////////////////////////////////
    QMovie* cardgif = new QMovie(":/gifs/insertcard.gif");

    // Make sure the GIF was loaded correctly
    if (!cardgif->isValid())
    {
        qDebug()<<"GIF EI TOIMI ";
    }
    else
    {
        // Play GIF

        cardgif->setScaledSize(QSize(250,250));
        ui->giflabel->setMovie(cardgif);
        cardgif->start();
    }
///////////// RFDI reader  ////////////////////////

   pRFIDReader = new Rfid_dll(this);

   connect(this,SIGNAL(requestCardNumber()),
           pRFIDReader,SLOT(requestCardNumberSlot()));

/////////////// PIN UI /////////////////////////////
    ppinuinappis = new pinUInappis(this);

    connect(ppinuinappis, &pinUInappis::isThePinCorrect,
            this,&MainWindow::exeIsThePinCorrect);

////////////// Timer PIN UI:lle /////////////////////

    pClosePinUiTimer = new QTimer(this);   // PIN UI sulkeutumis pointteri

    connect(pClosePinUiTimer, SIGNAL(timeout()),
            this, SLOT(closePinUi()));

    pClosePinUiTimer->setInterval(5000);    // 5 sec timer
    pClosePinUiTimer->stop();

//////////// Timer Ota rahat /////////////////////////

    pCloseTakeMoney = new QTimer(this);

    connect(pCloseTakeMoney, SIGNAL(timeout()),
            this, SLOT(closeTakeMoney()));

    pCloseTakeMoney->setInterval(5000);    // 5 sec timer
    pCloseTakeMoney->stop();

/////////// Timer kuitti näyttö /////////////////////////

    pCloseReceiptWindow = new QTimer(this);

    connect(pCloseReceiptWindow, SIGNAL(timeout()),
            this, SLOT(closeReceiptWindow()));

    pCloseReceiptWindow->setInterval(5000);    // 5 sec timer
    pCloseReceiptWindow->stop();

///////////// Login Request DLL ///////////////////////

    pDLLRestAPI = new DLLRestAPI();

    //Rest api lähettää tiedon exelle onko kirjautuminen onnistunut
    connect(pDLLRestAPI, SIGNAL(httpResponseReady(bool,bool,QString)),
            this, SLOT(loginStatus(bool,bool,QString)));

    // Rest api lähettää saldotiedot QStringinä
    connect(pDLLRestAPI, SIGNAL(saldoReady(QString)),
            this, SLOT(debitSaldo(QString)));

    // Rest api lähettää ottotiedot
    connect(pDLLRestAPI, SIGNAL(ottoReady(QString)),
            this, SLOT(otto(QString)));

    // Rest api lähettää tapahtuma tiedot QStringinä
    connect(pDLLRestAPI, SIGNAL(tapahtumatReady(QString)),
            this, SLOT(tapahtumatDebit(QString)));

///////// Mainexewindowin tapahtuman valinnat //////////////////////

    connect(pmainexewindow, SIGNAL(sendEventToMainwindow(QString)),
            this, SLOT(sendEventToMainwindowSlot(QString)));

//////////  nostettava summa Otolta///////////////////////////////
    pOttoWindow = new OttoWindow(this);

    connect(pOttoWindow, SIGNAL(OttoSelection(QString)),
            this, SLOT(receiveSelectionFromOtto(QString)));

//////////////// Credit/debit kysymys ///////////////////////

    pcreditordebit = new creditordebitwindow(this);

    connect(pcreditordebit, SIGNAL(sendSelectionToMainwindow(QString)),
            this, SLOT(receiveSelectionFromCreditOrDebit(QString)));

////////////// ReceiptSelection ikkuna ///////////////////////////
    preceiptSelection = new receiptSelection(this);

    connect(preceiptSelection,SIGNAL(sendReceiptSelectionToMainexe(QString)),
            this, SLOT(receiveSelectionFromReceipt(QString)));

///////////// TakeMoney ikkuna /////////////////////////////

    ptakeMoney = new TakeMoney(this);

////////////// Receiptwindow ikkuna ////////////////////////////////

    preceiptwindow = new receiptwindow(this);

//////////// OtherAMount ikkuna /////////////////////////////

    pOtherAmount = new OtherAmount(this);

    connect(pOtherAmount, SIGNAL(signalEnteredAmount(QString)),
            this, SLOT(receiveOtherAmount(QString)));

///////// Saldo ikkuna ///////////////////////////////////

    psaldowindow = new saldowindow(this);

////////// Tapahtumat ikkuna ////////////////////////////

    ptapahtumat = new transactionwindow(this);

///////// Tilisiirto ikkuna //////////////////////////

    ptilisiirto = new transferwindow(this);

//////////////// ALUSTUKSET /////////////////////////////

        state=1;
        initialize();
        stateMachine();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ppinuinappis;
    delete pRFIDReader;
    delete pDLLRestAPI;
}

void MainWindow::stateMachine()
{
    switch(state){

        case 1:
             qDebug()<<"Nyt ollaan state 1:ssa! Kutsutaan requestCardNumberSlottia ja odotellaan korttia luettavaksi";
             qDebug()<<"Tämä on kortin numero: " << kortinNumero;
            if(kortinNumero=="")
            {
                qDebug()<<"Pyydetään kortin lukua, koska kortin numero tyhjä";
                requestCardNumberSlot();
            }
                else {
                        qDebug()<<"Kortin lukeminen onnistui";
                        close();
                        state=2;
                        stateMachine();
                     }
            break;

        case 2:
          qDebug()<<"Nyt ollaan state 2:ssa! Kutsutaan seuraavaksi PIN UI:ta.";
             qDebug()<<"Tämä on Pin numero: "<<pinNumero;
             ppinuinappis->open();
             if(pinNumero=="")
             {
                 qDebug()<<"Pin koodia ei vielä syötetty";
             }
             else
             {
                 qDebug()<<"Pin koodin syöttäminen onnistui";
                 state=3;
                 stateMachine();
              }
            break;

        case 3:

            qDebug()<<"Nyt ollaan state 3:ssa! Kutsutaan login dll, joka tarkistelee onko tiedot oikein.";
            pDLLRestAPI->loginRequest(kortinNumero,pinNumero);
            break;

        case 4:

            qDebug()<<"Nyt ollaan state 4:ssa. Aukaistaan mainexewindow ikkuna.";
            pcreditordebit->close();
            pmainexewindow->open();
            if(eventToMainwindow == "Otto")
            {
                state=5;
                stateMachine();
            }
            else if(eventToMainwindow == "Saldo")
            {
                qDebug()<<"Nyt on valittu saldo!";

                if (cardType == "debit" || selectionFromCreditOrDebit == "debit")
                {
                    pDLLRestAPI->saldoRequest(kortinNumero);
                    qDebug()<<"Täällä sitten kyselleen saldodebit requestia!";
                }
                else if (cardType == "credit" || selectionFromCreditOrDebit == "credit")
                {
                    pDLLRestAPI->saldoRequest(kortinNumero);
                    qDebug()<<"Täällä sitten kyselleen saldocredit requestia!";
                }
            }
            else if(eventToMainwindow == "Tapahtumat")
            {
                qDebug()<<"Nyt on valittu Tapahtumat!";
                                ptapahtumat->open();
                                if (cardType == "debit" || selectionFromCreditOrDebit == "debit")
                                {
                                    qDebug()<<"Täällä sitten kyselleen tapahtumatdebit requestia!";

                                    pDLLRestAPI->tapahtumatRequest(kortinNumero);
                                }
                                else if (cardType == "credit" || selectionFromCreditOrDebit == "credit")
                                {
                                    qDebug()<<"Täällä sitten kyselleen tapahtumatcredit requestia!";
                                    pDLLRestAPI->tapahtumatRequest(kortinNumero);
                                }
            }

            else if(eventToMainwindow =="Tilisiirto")
            {
                qDebug()<<"Nyt on valittu Tilisiirto!";
                ptilisiirto->open();
            }

            else if(eventToMainwindow == "Kirjaudu ulos")
            {
                qDebug()<<"Nyt on valittu Kirjaudu ulos!";
                exit(1);
            }
            else if(eventToMainwindow == "sulje")
            {
                qDebug()<<"Nyt on valittu sulje";
                exit(1);
            }
        break;

        case 5:
        qDebug()<<"Nyt ollaan sitten state 5, avataan ottowindow";

        pOttoWindow->open();
        if(OttoSelection == "20" || OttoSelection=="40" || OttoSelection== "60" ||OttoSelection== "90" ||OttoSelection== "140" ||OttoSelection== "240")
        {
            if(cardType == "debit" || selectionFromCreditOrDebit == "debit")
            {
                qDebug()<<"Täällä sitten kyselleen Ottodebit requestia!";
                pDLLRestAPI->ottoRequest(OttoSelection,kortinNumero);

            }
            else if (cardType == "credit" || selectionFromCreditOrDebit == "credit")
            {
                qDebug()<<"Täällä sitten kyselleen Ottocredit requestia!";
                pDLLRestAPI->ottoRequest(OttoSelection,kortinNumero);
            }
        }
          else if (OttoSelection == "alkuun")
            {
                qDebug()<<"Nyt on painettu alkuun";
                pOttoWindow->close();
                eventToMainwindow="";
                OttoSelection="";
                state=4;
                stateMachine();

            }
            else if (OttoSelection =="muu summa")
            {
              qDebug()<<"Nyt tultiin muu summa ja aukaistaan otheramount ikkuna";
             pOtherAmount->open();
            }
       break;

        case 6:
                 preceiptSelection->close();
                 qDebug()<<"Nyt tultiin katsomaan kuitin valinta";

                 if(selectionFromReceipt == "Näytöllä")
                 {
                     qDebug()<<"Valittuna valinta näytöllä. Avataan kuitti ikkuna ja suljetaan se 5 sec jälkeen.";
                     pOttoWindow->close();

                     connect(this, SIGNAL(sendUpdatedSaldoToReceiptWindow(QString,QString)),
                             preceiptwindow, SLOT(receiveUpdatedSaldoFromMainWindow(QString,QString)));

                     emit sendUpdatedSaldoToReceiptWindow(OttoSelection, updatedOttoSaldo);

                    preceiptwindow->open();
                    pCloseReceiptWindow->start();


                 }

                     else if (selectionFromReceipt == "Sähköpostiin")
                     {
                     qDebug()<<"Avataan uusi ikkuna jossa lähtetetään tiedot sähköpostiin";
                     }
                             else if(selectionFromReceipt == "ei kiitos")
                             {
                                 qDebug()<<"Avataan ikkuna ota rahat";
                                 ptakeMoney->open();
                                 pCloseTakeMoney->start();
                             }

break;
        case 7:
                 if (cardType == "debit" || cardType == "credit")
                 {
                    qDebug()<<"Kortti oli tyyppiä debit tai credit";
                     state=4;
                     stateMachine();
                 }
                else if (cardType == "tupla")
                {
                    qDebug()<<"Kortti oli tyyppiä credit/debit, joten aukaistaan valinta ikkuna";
                    pcreditordebit->open();
                    if(selectionFromCreditOrDebit == "debit" || selectionFromCreditOrDebit == "credit")
                    {
                        state=4;
                        stateMachine();
                    }
                                else if(selectionFromCreditOrDebit == "cancel")
                                {
                                     pcreditordebit->close();
                                     exit(1);
                                }
                }
    break;

}

}
void MainWindow::initialize()
{
    kortinNumero="";
    pinNumero="";
    OttoSelection="";
    selectionFromReceipt="";
    selectionFromCreditOrDebit="";
    eventToMainwindow="";
    attemps=3;
    cardType="";
}
void MainWindow::receiveCardNumber(QString cardNumber)
{
    qDebug()<<"Nyt on kortinnumero vastaanotettu: "<<cardNumber;
    kortinNumero=cardNumber;
    disconnect(pRFIDReader, SIGNAL(sendCardNumber(QString)),
            this, SLOT(receiveCardNumber(QString)));
    stateMachine();
}
void MainWindow::requestCardNumberSlot()
{
    connect(pRFIDReader, SIGNAL(sendCardNumber(QString)),
            this, SLOT(receiveCardNumber(QString)));
    qDebug()<<"Request card number";
    emit requestCardNumber();
}
void MainWindow::exeIsThePinCorrect(QString enteredPin)
{
    pinNumero=enteredPin;
    stateMachine();
}
void MainWindow::closePinUi()
{
    ppinuinappis->close();
    exit(1);
}
void MainWindow::receiveSelectionFromCreditOrDebit(QString selection)
{
    qDebug()<<"Signaali debit/credit valinnasta mainexewindowilta saapui"<<selection;
    pDLLRestAPI->tuplakorttiRequest(selection);
    selectionFromCreditOrDebit=selection;
    stateMachine();
}
void MainWindow::sendEventToMainwindowSlot(QString event)
{
    qDebug()<<"Tapahtuman valinta vastaanotettu mainexewindowilta: "<<event;
    eventToMainwindow=event;
    stateMachine();
}

void MainWindow::receiveSelectionFromOtto(QString SelectioFromOtto)
{
    OttoSelection = SelectioFromOtto;
    qDebug()<<"Saatiin ottowindowin valinta: "<<OttoSelection;
    stateMachine();
}

void MainWindow::receiveSelectionFromReceipt(QString selection)
{
    qDebug()<<"Nyt saimme valinnan kuitti kyselyltä: "<<selection;
    selectionFromReceipt=selection;
    state=6;
    stateMachine();
}

void MainWindow::closeTakeMoney()
{
    pCloseTakeMoney2->deleteLater();
    pCloseTakeMoney->stop();
    ptakeMoney->close();
    exit(1);
}

void MainWindow::closeReceiptWindow()
{
    pCloseReceiptWindow->stop();
    preceiptwindow->close();

    pCloseTakeMoney2 = new QTimer(this);

    connect(pCloseTakeMoney2, SIGNAL(timeout()),
            this, SLOT(closeTakeMoney()));

    pCloseTakeMoney2->setInterval(5000);    // 5 sec timer
    pCloseTakeMoney2->stop();

     ptakeMoney->open();

     pCloseTakeMoney2->start();
}

void MainWindow::receiveOtherAmount(QString otherAmount)
{
    OttoSelection=otherAmount;
    qDebug()<<"Nyt vastaanotettiin otheramount: "<<OttoSelection;

    disconnect(pOtherAmount, SIGNAL(signalEnteredAmount(QString)),
            this, SLOT(receiveOtherAmount(QString)));

    pOtherAmount->close();


    if(cardType == "debit" || selectionFromCreditOrDebit == "debit")
    {
        qDebug()<<"Täältä receive otherAmountista sitten kyselleen Ottodebit requestia!";
        pDLLRestAPI->ottoRequest(OttoSelection,kortinNumero);


    }
    else if (cardType == "credit" || selectionFromCreditOrDebit == "credit")
    {
     qDebug()<<"Täällä sitten kyselleen Ottocredit requestia!";
     pDLLRestAPI->ottoRequest(OttoSelection,kortinNumero);

    }

}

void MainWindow::CloseReceiptWindow2()
{
    qDebug()<<"Nyt tultiin sulkemaan kuitti ikkuna";

    exit(1);
}

void MainWindow::loginStatus(bool status, bool serverstatus, QString cardtype)
{
    qDebug()<<"tullaanko me tänne?"<<status<<serverstatus<<cardtype;
    statusToStateMachine=status;
    serverStatusToStateMachine= serverstatus;
    cardType=cardtype; 

            if(statusToStateMachine == true && serverStatusToStateMachine==true)
            {
                qDebug()<<"Kirjautuminen onnistui!";
                ppinuinappis->receiveMessageToLabel("Kirjautuminen onnistui!");
                state=7;
                ppinuinappis->close();
                stateMachine();
            }
                    else if (statusToStateMachine == false && serverStatusToStateMachine == false )
                    {
                            qDebug()<<"Serveri ongelma";
                            ppinuinappis->receiveMessageToLabel("Serveri ongelma!");
                    }
                            else
                            {
                                    attemps --;
                                    qDebug()<<"Väärä käyttäjä tai salasana";
                                    qDebug()<<attemps<<kortinNumero<<pinNumero;
                                    ppinuinappis->receiveMessageToLabel("Väärä käyttäjä tai PIN!");
                                    ppinuinappis->receiveMessageToLabel_2(QString("Yrityksiä jäljellä: %1").arg(attemps));

                                    if(attemps==0){
                                        qDebug()<<"Kortti lukittu!!";
                                        ppinuinappis->receiveMessageToLabel("Ikkuna sulkeutuu");
                                        ppinuinappis->receiveMessageToLabel_2("Kortti lukittu!");
                                        pClosePinUiTimer->start();
                                    }
                            }
}
void MainWindow::debitSaldo(QString arvot)
{
    qDebug()<<"Nyt on debitsaldo vastaanotettu rest api dll:ltä!"<<arvot;
      connect(this, SIGNAL(sendArvotToSaldoWindow(QString)),
      psaldowindow, SLOT(receiveArvotFromMainwindow(QString)));

    emit sendArvotToSaldoWindow(arvot);

    psaldowindow->open();
}

void MainWindow::otto(QString saldo)
{
    updatedOttoSaldo=saldo;
    qDebug()<<"Nyt on Otto tapahtuman jälkeinen saldo vastaanotettu"<<saldo;
    if (updatedOttoSaldo=="Virheellinen määrä")
    {
        pCloseReceiptWindow2 = new QTimer(this);

        connect(pCloseReceiptWindow2, SIGNAL(timeout()),
                this, SLOT(CloseReceiptWindow2()));

        pCloseReceiptWindow2->setInterval(5000);

        preceiptwindow->open();
        pCloseReceiptWindow2->start();

        connect(this, SIGNAL(sendErrorToReceiptWindow()),
                preceiptwindow, SLOT(receiveErrorMessageFromExe()));

        emit sendErrorToReceiptWindow();


    }
    else
    {
        pOttoWindow->close();
        preceiptSelection->open();
        state=6;
    }

}
void MainWindow::tapahtumatDebit(QString tapahtumat)
{
    qDebug()<<"Debit tapahtumat vastaanotettu"<<tapahtumat;
    connect(this, SIGNAL(sendDebitTapahtumatToTapahtumatWindow(QString)),
            ptapahtumat, SLOT(receiveTapahtumatFromExe(QString)));

    emit sendDebitTapahtumatToTapahtumatWindow(tapahtumat);
}

