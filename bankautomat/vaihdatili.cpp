#include "vaihdatili.h"
#include "ui_vaihdatili.h"

vaihdaTili::vaihdaTili(QWidget *parent, bool credit) :
    QDialog(parent),
    ui(new Ui::vaihdaTili)
{
    ui->setupUi(this);
    creditValittu = credit;
    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(10000);
}

vaihdaTili::~vaihdaTili()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

bool vaihdaTili::loginValitseTili()
{
    objTimer->stop();       // käytetään tässä välissä 30s menuTimeriä
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
    if(creditValittu == true)
    {
        this->accept();
    }
    else
    {
        this->reject();
    }
}
