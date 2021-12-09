#include "vaihda.h"
#include "ui_vaihda.h"

vaihda::vaihda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vaihda)
{
    ui->setupUi(this);
}

vaihda::~vaihda()
{
    delete ui;
}

void vaihda::on_btnsulje_4_clicked()
{
    this->close();
}
