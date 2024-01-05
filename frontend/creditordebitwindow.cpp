#include "creditordebitwindow.h"
#include "ui_creditordebitwindow.h"

creditordebitwindow::creditordebitwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditordebitwindow)
{
    ui->setupUi(this);

    //Nappien connectionit

    connect(ui->btnCredit, SIGNAL(clicked(bool)),
            this, SLOT(creditBtnHandler()));

    connect(ui->btnDebit, SIGNAL(clicked(bool)),
            this, SLOT(debitBtnHandler()));

    connect(ui->btnCancel, SIGNAL(clicked(bool)),
            this, SLOT(cancelBtnHandler()));

}

creditordebitwindow::~creditordebitwindow()
{
    delete ui;
}

void creditordebitwindow::creditBtnHandler()
{
    qDebug()<<"Painoit credit nappia!";
    selection = "credit";                           //Tallennetaan valinta muuttujaan selection
    emit sendSelectionToMainwindow(selection);   // Lähetetään tieto signaalina mainexewindowille



}

void creditordebitwindow::debitBtnHandler()
{
    qDebug()<<"Painoit debit nappia!";
    selection = "debit";
    emit sendSelectionToMainwindow(selection);


}

void creditordebitwindow::cancelBtnHandler()
{
     qDebug()<<"Painoit cancel nappia!";
     selection = "cancel";
     emit sendSelectionToMainwindow(selection);


}
