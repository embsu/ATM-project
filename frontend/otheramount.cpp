#include "otheramount.h"
#include "ui_otheramount.h"

OtherAmount::OtherAmount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OtherAmount)
{
    ui->setupUi(this);

    setWindowTitle("Syötä summa");
    ui->label_1->setText("Syötä haluamasi summa");

//----------näppiksen numerot---------------------------------
    connect(ui->A0,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A1,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A2,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A3,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A4,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A5,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A6,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A7,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A8,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->A9,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
//---------näppiksen ENTER ja CANCEL----------------------------
    connect(ui->BCancel_2,SIGNAL(clicked(bool)),
            this,SLOT(cancelButtonHandler()));
    connect(ui->BEnter_2,SIGNAL(clicked(bool)),
            this,SLOT(enterButtonHandler()));
    connect(ui->pushButton, SIGNAL(clicked(bool)),
            this, SLOT(btnTakaisinClicked()));


}

OtherAmount::~OtherAmount()
{
    delete ui;
}

void OtherAmount::resetLineEdit()
{
    enteredAmount.clear();         // sama kuin -- enteredPin = ""; -- tyhjentää tallentuneen QStringin
    ui->haluttusumma->clear();
}

void OtherAmount::numberButtonHandler()
{
    QPushButton *button = qobject_cast<QPushButton*> (sender());    //luodaan pointtermuuttuja button joka osoittaa qpushbutton olioon
    QString ButtonName = button->objectName();          //asettaa ButtonNameksi numeronäppäimen olion nimen (B1,B2 jne..)

    enteredAmount = enteredAmount+ButtonName.right(1);        // ottaa vain numeronäppäimen oikeanpuoleisen merkin esim B1 -> 1

    ui->haluttusumma->setText(enteredAmount);
}

void OtherAmount::cancelButtonHandler()
{
    resetLineEdit();
}

void OtherAmount::enterButtonHandler()
{
    QString enteredAmount = ui->haluttusumma->text();
    intOtherAmount=enteredAmount.toInt();

    int num20;
    int num50;
    int totalAmount;

    // tsekataan mahdollinen 20 seteleiden määrä
    for ( num20 = 0; num20 <= intOtherAmount/20; num20++)
    {
        // tsekataan mahdollinen 50 määrä
        for (num50 = 0; num50 <= intOtherAmount/50; num50++)
        {
            // lasketaan kokonaismäärä
             totalAmount = num20*20 + num50*50;
            // katotaan vastaako ne syötettyä summaa
            if (totalAmount == intOtherAmount)
            {
                // muutetaan boolean todeksi
                validCombinationFound = true;
                break;
            }
        }
        if (validCombinationFound) {
            // Kun boolea on totta lopetetaan etsintä
            break;
        }
    }

    if (validCombinationFound)
    {
        qDebug() << "Valid combination found: " << num20 << "x20 bills and " << num50 << "x50 bills";

        qDebug() << "Lähetetään Summa exelle"<<enteredAmount;
        emit signalEnteredAmount(enteredAmount);
        resetLineEdit();
        close();

    } else
        {
        qDebug() << "No valid combination found.";
        ui->label_1->setText("Syöttämäsi summa oli virheellinen!");
        ui->label_2->setText("Syötä uusi summa");           //lisäsin toiseen labeliin toisen pätkän tekstistä kun ei meinannut mahtua, emppu

        }

}

void OtherAmount::btnTakaisinClicked()
{
    close();
}
