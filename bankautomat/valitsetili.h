#ifndef VALITSETILI_H
#define VALITSETILI_H

#include <QDialog>
#include <QDebug>
#include <QTimer>

namespace Ui {
class valitseTili;
}

class valitseTili : public QDialog
{
    Q_OBJECT

public:
    explicit valitseTili(QWidget *parent, bool);
    ~valitseTili();
    bool loginValitseTili();

private slots:
    void on_btnDebit_clicked();
    void on_btnCredit_clicked();
    void on_btnTakaisin_clicked();

private:
    Ui::valitseTili *ui;
    bool creditValittu;
    QTimer *objTimer;
};

#endif // VALITSETILI_H
