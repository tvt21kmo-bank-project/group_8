#include "saldo.h"
#include "ui_saldo.h"
#include "mainwindow.h"
#include "menu.h"

saldo::saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
}

saldo::~saldo()
{
    delete ui;
    ui = nullptr;

}

void saldo::on_btnpois_clicked()
{
    this->close();
}
