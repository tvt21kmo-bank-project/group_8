#include "vaihdatili.h"
#include "ui_vaihdatili.h"

vaihdaTili::vaihdaTili(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vaihdaTili)
{
    ui->setupUi(this);
    qDebug()<<"VaihdaTili luotu";
}

vaihdaTili::~vaihdaTili()
{
    delete ui;
    qDebug()<<"VaihdaTili tuhottu";
}

bool vaihdaTili::loginValitseTili()
{
    ui->btnTakaisin->setVisible(false);
    this->show();
    int valinta = this->exec();
    ui->btnTakaisin->setVisible(true);
    return valinta;
}

void vaihdaTili::on_btnDebit_clicked()
{
    this->reject();
}

void vaihdaTili::on_btnCredit_clicked()
{
    this->accept();
}

void vaihdaTili::on_btnTakaisin_clicked()
{
    this->close();
}
