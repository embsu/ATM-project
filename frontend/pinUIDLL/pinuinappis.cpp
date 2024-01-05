#include "pinuinappis.h"
#include "ui_pinuinappis.h"
#include <QDebug>

using namespace std;

pinUInappis::pinUInappis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinUInappis)
{
    ui->setupUi(this);

    setWindowTitle("PIN CODE");             //pin ikkunan txt
    ui->label->setText("Syötä PIN");   //labelin txt

//----------näppiksen numerot---------------------------------
    connect(ui->B0,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B1,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B2,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B3,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B4,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B5,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B6,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B7,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B8,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
    connect(ui->B9,SIGNAL(clicked(bool)),
            this,SLOT(numberButtonHandler()));
//---------näppiksen ENTER ja CANCEL----------------------------
    connect(ui->BCancel,SIGNAL(clicked(bool)),
            this,SLOT(cancelButtonHandler()));
    connect(ui->BEnter,SIGNAL(clicked(bool)),
            this,SLOT(enterButtonHandler()));
//------------Saliksen krypti-----------------------------------
   ui->PinLineEdit->setEchoMode(QLineEdit::Password);          // voi tehdä myös ui.ssä


}

pinUInappis::~pinUInappis()
{
    delete ui;
  //  delete pClosePinUiTimer;
}

void pinUInappis::receiveMessageToLabel(const QString message)
{
    ui->label->setText(message);
}

void pinUInappis::receiveMessageToLabel_2(const QString message)
{
    ui->label_2->setText(message);
}






void pinUInappis::numberButtonHandler()
{
//----------------NÄPYTYKSET NÄKYVIIN----------------

    QPushButton *button = qobject_cast<QPushButton*> (sender());    //luodaan pointtermuuttuja button joka osoittaa qpushbutton olioon
    QString ButtonName = button->objectName();          //asettaa ButtonNameksi numeronäppäimen olion nimen (B1,B2 jne..)

    enteredPin = enteredPin+ButtonName.right(1);        // ottaa vain numeronäppäimen oikeanpuoleisen merkin esim B1 -> 1

    ui->PinLineEdit->setText(enteredPin);

//-------------Tarkistetaan että PIN on 4 numeroinen---------

    if (enteredPin.length() > 4)
    {
         // ERROR
         ui->label->setText("VIRHE");
         ui->label_2->setText("Pin numero on 4 merkkiä");
         resetLineEdit();
    }
}
//------------------------------------------------------------

void pinUInappis::cancelButtonHandler()
{
    resetLineEdit();
}

void pinUInappis::enterButtonHandler()
{   
    qDebug() << "Lähetetään PIN TestEXELLE tarkastukseen";

    QString enteredPin = ui->PinLineEdit->text();       //otetaan näpytelty pin LineEditistä
    emit isThePinCorrect(enteredPin);       //lähetys-signaali, signaalin nimi, ja mitä lähetetään eli (enteredPin)

    resetLineEdit();
}

void pinUInappis::resetLineEdit()
{
    enteredPin.clear();         // sama kuin -- enteredPin = ""; -- tyhjentää tallentuneen QStringin
    ui->PinLineEdit->clear();
}

