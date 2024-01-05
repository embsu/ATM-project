#ifndef MAINEXEWINDOW_H
#define MAINEXEWINDOW_H

#include <QDialog>
#include <QDebug>
//#include "ottowindow.h"
//#include "creditordebitwindow.h"

namespace Ui {
class mainexewindow;
}

class mainexewindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainexewindow(QWidget *parent = nullptr);
    ~mainexewindow();

private:
    Ui::mainexewindow *ui;

    //OttoWindow *pOttoWindow;
    //creditordebitwindow *pcreditordebit;

    QString cardType;
    QString selectionMainexe; //tallennetaan valinta mainexen käyttöön

    QString event;


private slots:

//----- Nappi Handlerit -------------
    void btnOttoHandler();
    void btnSaldoHandler();
    void btnTapahtumatHandler();
    void btnTilisiirtoHandler();
    void btnKirjauduulosHandler();
    void btnsuljeHandler();


signals:

//-----Lähetetään debit/credit valinta sekä nostettava summa------
    void sendSelectionToMainwindow(QString);
    void sendAmountToMainwindow(int);

//----- Lähetetään valinnoista signaali tilakoneelle---

        void sendEventToMainwindow(QString);

};

#endif // MAINEXEWINDOW_H
