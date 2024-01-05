#include "takemoney.h"
#include "ui_takemoney.h"
#include "QMovie"


TakeMoney::TakeMoney(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TakeMoney)
{
    ui->setupUi(this);


/////////// RAHULI GIF  ///////////////


    QMovie* rahuligif = new QMovie(":/gifs/cashrain.gif");

    // Make sure the GIF was loaded correctly
    if (!rahuligif->isValid())
    {
        qDebug()<<"GIF EI TOIMI ";
    }
    else
    {
        // Play GIF (emppu)

        rahuligif->setScaledSize(QSize(300,300));
        ui->takemoneylabl->setMovie(rahuligif);
        rahuligif->start();
    }

/////////// NYRKKI GIF ///////////////

    QMovie* rahanyrkki = new QMovie(":/gifs/nyrkisraha.gif");

    // Make sure the GIF was loaded correctly
    if (!rahanyrkki->isValid())
    {
        qDebug()<<"GIF EI TOIMI ";
    }
    else
    {
        // Play GIF

        rahanyrkki->setScaledSize(QSize(200,200));
        ui->nyrkkirahalabl->setMovie(rahanyrkki);
        rahanyrkki->start();
    }


}

TakeMoney::~TakeMoney()
{
    delete ui;
}



