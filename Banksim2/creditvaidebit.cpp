#include "creditvaidebit.h"
#include "ui_creditvaidebit.h"
#include "mainwindow.h"



creditvaidebit::creditvaidebit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creditvaidebit)
{
    ui->setupUi(this);
    objmenu = new menu;
}

creditvaidebit::~creditvaidebit()
{
    delete ui;
    ui = nullptr;

}

void creditvaidebit::on_btncredit_clicked()
{
    objmenu->show();

}

void creditvaidebit::on_btndebit_clicked()
{
    objmenu->show();
}
