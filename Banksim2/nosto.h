#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QWidget *parent = 0);
    ~nosto();

private slots:
    void on_btnsulje_1_clicked();

private:
    Ui::nosto *ui;
};

#endif // NOSTO_H