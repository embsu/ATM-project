#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pinuinappis.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openHandler();
    void closePinUi();

private:
    Ui::MainWindow *ui;

    pinUInappis * pPinUiNappis;

    void exeIsThePinCorrect(QString);

    QString correctPin ="1234";     //correctPin korvataan databasen pinillä
    int pinAttempts = 3;
    QTimer * pClosePinUiTimer;  // PIN UI sulkeutuminen


};
#endif // MAINWINDOW_H
