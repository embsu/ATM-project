#include "transferwindow.h"
#include "ui_transferwindow.h"

transferwindow::transferwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transferwindow)
{
    ui->setupUi(this);

    connect(ui->btnCancel, SIGNAL(clicked(bool)),
            this, SLOT(btnCancelHandler()));
}

transferwindow::~transferwindow()
{
    delete ui;
}

void transferwindow::btnCancelHandler()
{
    qDebug()<<"Nappia cancel painettu";
    close();
}


