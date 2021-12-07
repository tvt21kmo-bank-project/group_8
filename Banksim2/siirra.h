#ifndef SIIRRA_H
#define SIIRRA_H

#include <QDialog>

namespace Ui {
class siirra;
}

class siirra : public QDialog
{
    Q_OBJECT

public:
    explicit siirra(QWidget *parent = 0);
    ~siirra();

private slots:
    void on_btnsulje_3_clicked();

private:
    Ui::siirra *ui;
};

#endif // SIIRRA_H
