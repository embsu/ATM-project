#ifndef OTHERAMOUNT_H
#define OTHERAMOUNT_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class OtherAmount;
}

class OtherAmount : public QDialog
{
    Q_OBJECT

public:
    explicit OtherAmount(QWidget *parent = nullptr);
    ~OtherAmount();

private:
    Ui::OtherAmount *ui;

    void resetLineEdit();           // tekstiboksien reset

    QString enteredAmount;

    int intOtherAmount;

    bool validCombinationFound = false;


private slots:

    void numberButtonHandler();
    void cancelButtonHandler();
    void enterButtonHandler();
    void btnTakaisinClicked();

signals:

    void signalEnteredAmount(QString enteredAmount);
};

#endif // OTHERAMOUNT_H
