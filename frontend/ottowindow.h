#ifndef OTTOWINDOW_H
#define OTTOWINDOW_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class OttoWindow;
}

class OttoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OttoWindow(QWidget *parent = nullptr);
    ~OttoWindow();

private:
    Ui::OttoWindow *ui;



    QString selection;

private slots:

    void btn20Clicked();
    void btn40Clicked();
    void btn60Clicked();
    void btn90Clicked();
    void btn140Clicked();
    void btn240Clicked();
    void btnAlkuunClicked();
    void btnMuusummaClicked();

signals:

    void OttoSelection(QString);

};

#endif // OTTOWINDOW_H
