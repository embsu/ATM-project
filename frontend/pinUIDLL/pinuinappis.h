#ifndef PINUINAPPIS_H
#define PINUINAPPIS_H

#include <QDialog>
#include "pinUIDLL_global.h"
#include "QMovie"

namespace Ui {
class pinUInappis;
}

class PINUIDLL_EXPORT pinUInappis : public QDialog
{
    Q_OBJECT

public:
    explicit pinUInappis(QWidget *parent = nullptr);
    ~pinUInappis();

     Ui::pinUInappis *ui;

signals:
    void isThePinCorrect(QString enteredPin);       // PININ LÄHETYS-SIGNAALI

public slots:
    void receiveMessageToLabel(const QString message);     // Pinin tarkastuksen jälkeen viesti 1. labeliin
    void receiveMessageToLabel_2(const QString message);   // Pinin tarkastuksen jälkeen viesti 2. labeliin


private slots:
    void numberButtonHandler();
    void cancelButtonHandler();
    void enterButtonHandler();

private:
    void resetLineEdit();           // tekstiboksien reset
    QString enteredPin;
};

#endif // PINUINAPPIS_H
