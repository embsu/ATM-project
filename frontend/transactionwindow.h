#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class transactionwindow;
}

class transactionwindow : public QDialog
{
    Q_OBJECT

public:
    explicit transactionwindow(QWidget *parent = nullptr);
    ~transactionwindow();

private:
    Ui::transactionwindow *ui;

private slots:

    void previousHandler();
    void nextHandler();
    void closeHandler();
    void receiveTapahtumatFromExe(QString);
};

#endif // TRANSACTIONWINDOW_H
