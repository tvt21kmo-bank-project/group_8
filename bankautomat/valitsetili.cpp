#include "valitsetili.h"
#include "ui_valitsetili.h"

valitseTili::valitseTili(QWidget *parent, bool credit) :
    QDialog(parent),
    ui(new Ui::valitseTili)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setParent(0);

    creditValittu = credit;

    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(10000);
}

valitseTili::~valitseTili()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

bool valitseTili::loginValitseTili()             // Kun kirjaudutaan sisään debit/credit-kortilla kysytään kummalla tilillä kirjaudutaan, tällöin poistetaan käytöstä takaisin nappi ja 10s timer
{
    objTimer->stop();   // käytetään tässä 30s menuTimeriä
    ui->btnTakaisin->setVisible(false);
    this->setModal(true);
    this->open();
    int valinta = this->exec();
    ui->btnTakaisin->setVisible(true);
    return valinta;
}

void valitseTili::on_btnDebit_clicked()         // Palautetaan creditValittu arvoksi 0
{
    this->reject();
}

void valitseTili::on_btnCredit_clicked()         // Palautetaan creditValittu arvoksi 1
{
    this->accept();
}

void valitseTili::on_btnTakaisin_clicked()       // Palautetaan edellinen arvo
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
