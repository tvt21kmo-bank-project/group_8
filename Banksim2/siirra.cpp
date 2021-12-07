#include "siirra.h"
#include "ui_siirra.h"

siirra::siirra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::siirra)
{
    ui->setupUi(this);
}

siirra::~siirra()
{
    delete ui;
}

void siirra::on_btnsulje_3_clicked()
{
    this->close();
}
