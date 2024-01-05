#include "saldowindow.h"
#include "ui_saldowindow.h"

saldowindow::saldowindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldowindow)
{
    ui->setupUi(this);

    connect(ui->cancel,SIGNAL(clicked(bool)),
            this, SLOT(cancelbtnHandler()));
}

saldowindow::~saldowindow()
{
    delete ui;
}

void saldowindow::cancelbtnHandler()
{
    qDebug()<<"Nyt on painettu cancel saldo ikkunassa";
    close();
}

void saldowindow::receiveArvotFromMainwindow(QString saldo)
{
    qDebug()<<"Nyt saimme arvot exeltä";

    ui->saldonmaaraLabel->setText(saldo);


}
