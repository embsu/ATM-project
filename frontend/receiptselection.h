#ifndef RECEIPTSELECTION_H
#define RECEIPTSELECTION_H

#include <QDialog>

#include <QDebug>
namespace Ui {
class receiptSelection;
}

class receiptSelection : public QDialog
{
    Q_OBJECT

public:
    explicit receiptSelection(QWidget *parent = nullptr);
    ~receiptSelection();

private:
    Ui::receiptSelection *ui;


    QString selection;

private slots:

    void btnNaytolleClicked();
    void btnSahkopostillaClicked();
    void btnEikiitosClicked();

signals:

    void sendReceiptSelectionToMainexe(QString);


};

#endif // RECEIPTSELECTION_H
