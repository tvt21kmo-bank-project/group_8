#ifndef SIIRTO_H
#define SIIRTO_H

#include <QDialog>

namespace Ui {
class siirto;
}

class siirto : public QDialog
{
    Q_OBJECT

public:
    explicit siirto(QWidget *parent = 0);
    ~siirto();

private:
    Ui::siirto *ui;
};

#endif // SIIRTO_H
