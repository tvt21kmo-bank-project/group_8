#include "talleta.h"
#include "ui_talleta.h"

talleta::talleta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::talleta)
{
    ui->setupUi(this);
}

talleta::~talleta()
{
    delete ui;
}

void talleta::on_btnsulje_2_clicked()
{
    this->close();
}
