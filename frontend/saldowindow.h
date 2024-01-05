#ifndef SALDOWINDOW_H
#define SALDOWINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class saldowindow;
}

class saldowindow : public QDialog
{
    Q_OBJECT

public:
    explicit saldowindow(QWidget *parent = nullptr);
    ~saldowindow();

private:
    Ui::saldowindow *ui;
private slots:

    void cancelbtnHandler();

    void receiveArvotFromMainwindow(QString);
};

#endif // SALDOWINDOW_H
