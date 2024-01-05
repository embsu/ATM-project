#include "receiptwindow.h"
#include "ui_receiptwindow.h"

receiptwindow::receiptwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiptwindow)
{
    ui->setupUi(this);
}

receiptwindow::~receiptwindow()
{
    delete ui;
}

void receiptwindow::receiveUpdatedSaldoFromMainWindow(QString maara,QString updatedsaldo)
{

    qDebug()<<"Nyt on vastaanotettu päivitetty saldo mainwindow.cpp:ltä."<<updatedsaldo;
    ui->labelSumma->setText(maara);
    ui->labelSaldo->setText(updatedsaldo);

}

void receiptwindow::receiveErrorMessageFromExe()
{
    qDebug()<<"Nyt on errorit exeltä vastaanotettu, ei oo rahhaa!";
    ui->labelError->setText("Kate ei riitä!");
    ui->labelSaldo->setText("Error");
    ui->labelSumma->setText("Error");

}
