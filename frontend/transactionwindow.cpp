#include "transactionwindow.h"
#include "ui_transactionwindow.h"

transactionwindow::transactionwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transactionwindow)
{
    ui->setupUi(this);

    connect(ui->btnClose, SIGNAL(clicked(bool)),
            this, SLOT(closeHandler()));

    connect(ui->btnNext, SIGNAL(clicked(bool)),
            this, SLOT(nextHandler()));

    connect(ui->btnPrevious, SIGNAL(clicked(bool)),
            this, SLOT (previousHandler()));
}

transactionwindow::~transactionwindow()
{
    delete ui;
}

void transactionwindow::previousHandler()
{
    qDebug()<<"Nyt on painettu edelliset nappia";
}

void transactionwindow::nextHandler()
{
    qDebug()<<"Nyt on painettu seuraavat nappia";
}

void transactionwindow::closeHandler()
{
    qDebug()<<"Nyt on painettu close nappia";
    close();
}

void transactionwindow::receiveTapahtumatFromExe(QString tapahtumat)
{
    qDebug()<<"Tapahtumat tuli EXELTÄ"<<tapahtumat;
    ui->textEdit->setText(tapahtumat);
}
