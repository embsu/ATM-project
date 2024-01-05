#ifndef RECEIPTWINDOW_H
#define RECEIPTWINDOW_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class receiptwindow;
}

class receiptwindow : public QDialog
{
    Q_OBJECT

public:
    explicit receiptwindow(QWidget *parent = nullptr);
    ~receiptwindow();

private:
    Ui::receiptwindow *ui;


private slots:

void receiveUpdatedSaldoFromMainWindow(QString, QString);

void receiveErrorMessageFromExe();
};

#endif // RECEIPTWINDOW_H
