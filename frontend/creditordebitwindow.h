#ifndef CREDITORDEBITWINDOW_H
#define CREDITORDEBITWINDOW_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class creditordebitwindow;
}

class creditordebitwindow : public QDialog
{
    Q_OBJECT

public:
    explicit creditordebitwindow(QWidget *parent = nullptr);
    ~creditordebitwindow();

private:
    Ui::creditordebitwindow *ui;

    QString selection; //Tänne tallennetaan onko valittu credit vai debit




private slots:

    void creditBtnHandler();
    void debitBtnHandler();
    void cancelBtnHandler();

signals:

    void sendSelectionToMainwindow(QString);

};

#endif // CREDITORDEBITWINDOW_H
