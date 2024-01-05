#ifndef TAKEMONEY_H
#define TAKEMONEY_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class TakeMoney;
}

class TakeMoney : public QDialog
{
    Q_OBJECT

public:
    explicit TakeMoney(QWidget *parent = nullptr);
    ~TakeMoney();

private:
    Ui::TakeMoney *ui;


private slots:




};

#endif // TAKEMONEY_H
