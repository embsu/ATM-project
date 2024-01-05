#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu.h"
#include <QMainWindow>
#include "dllrestapi.h"
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void sendToExe(QString, QString);
public slots:
    void loginStatus(bool, bool, QString);
private slots:
    void loginClicked();

private:
    Ui::MainWindow *ui;
    DLLRestAPI * pdllRestApi;
    Menu *pMenu;
    QString kortinnumero;
    QString pinnumero;

    //int attempts = 3;
};
#endif // MAINWINDOW_H
