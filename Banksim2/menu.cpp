#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include "tilitapahtumat.h"
#include "nosto.h"
#include "talleta.h"
#include "siirra.h"
#include "vaihda.h"

saldo *objsaldo;
tilitapahtumat *tapaht;
nosto *objnosto;
talleta *objtalle;
siirra *objsiirra;
vaihda *objvaihda;


menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    objsaldo = new saldo;
    tapaht = new tilitapahtumat;
    objnosto = new nosto;
    objtalle = new talleta;
    objsiirra = new siirra;
    objvaihda = new vaihda;



}

menu::~menu()
{
    delete ui;
    ui = nullptr;
    delete objsaldo;
    objsaldo = nullptr;
    delete tapaht;
    tapaht = nullptr;
    delete objnosto;
    objnosto = nullptr;
    delete objtalle;
    objtalle = nullptr;
    delete objsiirra;
    objsiirra = nullptr;
    delete objvaihda;
    objvaihda = nullptr;


}


void menu::on_btnMsaldo_clicked()
{
    objsaldo->show();
}


void menu::on_btnMtapahtumat_clicked()
{
    tapaht->show();
}

void menu::on_btnMnosta_clicked()
{
    objnosto->show();
}

void menu::on_btnMtalleta_clicked()
{
    objtalle->show();
}

void menu::on_btnMsiirra_clicked()
{
    objsiirra->show();
}

void menu::on_btnMvaihda_clicked()
{
    objvaihda->show();
}

void menu::on_btnMulos_clicked()
{

    this->close();
}
