#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class transferwindow;
}

class transferwindow : public QDialog
{
    Q_OBJECT

public:
    explicit transferwindow(QWidget *parent = nullptr);
    ~transferwindow();

private:
    Ui::transferwindow *ui;

private slots:
    void btnCancelHandler();
};

#endif // TRANSFERWINDOW_H
