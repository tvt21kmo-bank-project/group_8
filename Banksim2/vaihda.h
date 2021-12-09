#ifndef VAIHDA_H
#define VAIHDA_H

#include <QDialog>

namespace Ui {
class vaihda;
}

class vaihda : public QDialog
{
    Q_OBJECT

public:
    explicit vaihda(QWidget *parent = 0);
    ~vaihda();

private slots:
    void on_btnsulje_4_clicked();

private:
    Ui::vaihda *ui;
};

#endif // VAIHDA_H
