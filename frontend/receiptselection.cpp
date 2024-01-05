#include "receiptselection.h"
#include "ui_receiptselection.h"

receiptSelection::receiptSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiptSelection)
{
    ui->setupUi(this);

    connect(ui->btnNaytolle,SIGNAL(clicked(bool)),
            this, SLOT(btnNaytolleClicked()));

    connect(ui->btnSahkopostiin,SIGNAL(clicked(bool)),
            this, SLOT(btnSahkopostillaClicked()));

    connect(ui->btnEikiitos,SIGNAL(clicked(bool)),
            this, SLOT(btnEikiitosClicked()));

}

receiptSelection::~receiptSelection()
{
    delete ui;
}

void receiptSelection::btnNaytolleClicked()
{
    qDebug()<<"Painettu tiedot näytöllä";
    selection = "Näytöllä";
    emit sendReceiptSelectionToMainexe(selection);


}

void receiptSelection::btnSahkopostillaClicked()
{
    qDebug()<<"Painettu tiedot sähköpostiin";
    selection ="Sähkopostiin";
    emit sendReceiptSelectionToMainexe(selection);

}

void receiptSelection::btnEikiitosClicked()
{
    qDebug()<<"Painettu ei kiitos";
    selection = "ei kiitos";
    emit sendReceiptSelectionToMainexe(selection);


}


