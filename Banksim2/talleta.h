#ifndef TALLETA_H
#define TALLETA_H

#include <QDialog>

namespace Ui {
class talleta;
}

class talleta : public QDialog
{
    Q_OBJECT

public:
    explicit talleta(QWidget *parent = 0);
    ~talleta();

private slots:
    void on_btnsulje_2_clicked();

private:
    Ui::talleta *ui;
};

#endif // TALLETA_H
