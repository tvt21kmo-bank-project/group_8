#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);
}

nosto::~nosto()
{
    delete ui;
}

void nosto::on_btnsulje_1_clicked()
{
    this->close();
}
