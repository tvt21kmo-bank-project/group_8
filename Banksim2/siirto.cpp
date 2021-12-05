#include "siirto.h"
#include "ui_siirto.h"

siirto::siirto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::siirto)
{
    ui->setupUi(this);
}

siirto::~siirto()
{
    delete ui;
}
