#ifndef VAIHDATILI_H
#define VAIHDATILI_H

#include <QDialog>
#include <QDebug>

// TImer puuttuu

namespace Ui {
class vaihdaTili;
}

class vaihdaTili : public QDialog
{
    Q_OBJECT

public:
    explicit vaihdaTili(QWidget *parent = 0);
    ~vaihdaTili();
    bool loginValitseTili();

private slots:
    void on_btnDebit_clicked();
    void on_btnCredit_clicked();
    void on_btnTakaisin_clicked();

private:
    Ui::vaihdaTili *ui;
};

#endif // VAIHDATILI_H
