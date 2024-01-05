#ifndef MENU_H
#define MENU_H

#include "dllrestapi.h"
#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr, DLLRestAPI* pDllRestApi = nullptr);
    ~Menu();
    void getCardNumber(QString);
signals:
    void menuToInterface(QString, QByteArray, QString);

private slots:
    void clickHandlerAsiakas();
    void clickHandlerCredit();
    void clickHandlerDebit();
    void clickHandlerKortti();
    void clickHandlerTapahtumat();
    void clickHandlerSaldo();
    void clickHandlerOtto();

    void tables(QString);
    void debitSaldo(QString);
    void otto(QString);
    void tapahtumat(QString);


private:
    Ui::Menu *ui;

    DLLRestAPI * pdllRestApi;

    QString url;
    QByteArray tauluilleToken;
    QString kortti;
    QString nostetaan;
    QString tuplaArvo;
};

#endif // MENU_H
