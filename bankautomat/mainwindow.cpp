#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objTimer = new QTimer;
    //objMenu = new menu;
    objLogin = new login(this);
    ui->label_5->hide();
    ui->label_6->hide();

    connect(objLogin, SIGNAL(korttiEiNatsaa()), this, SLOT(korttiEiNatsaa()), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(korttiOk()), this, SLOT(avaaLogin()), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(loginOk(int)), this, SLOT(loginValmis(int)), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(korttiAutuaammilleAutomaateille(int)), this, SLOT(kuoletaKortti(int)), Qt::QueuedConnection);
    connect(objTimer, SIGNAL(timeout()), this, SLOT(logout()));
    connect(this, SIGNAL(nollaaLogoutTimer()), this, SLOT(logoutTimerReset()));
    //connect(objMenu, SIGNAL(kirjaaUlos()), this, SLOT(logout()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objLogin;
    objLogin = nullptr;
    delete objMenu;
    objMenu = nullptr;
    delete objTimer;
    objTimer = nullptr;
}

void MainWindow::korttiEiNatsaa()
{
    QString korttiEiNatsaa = "Virhe sisäänkirjautumisessa!\n   Tarkista syötetty kortti";
    ui->label_5->setText(korttiEiNatsaa);
    ui->label_5->show();
    ui->groupBox->hide();
    objTimer->singleShot(3500, this, SLOT(palautaNakyma()));
}

void MainWindow::palautaNakyma()
{
    ui->groupBox->show();
    ui->label_5->hide();
    ui->label_6->hide();
}

void MainWindow::on_btnLueKortti_clicked()
{
    //emit nollaaLogoutTimer();           // Tälle varmaan ois toimivinta rakentaa keypPresEvent
    if(ui->lineEditKortti->text().toInt() > 0)
    {
        int nro = ui->lineEditKortti->text().toInt();
        ui->lineEditKortti->clear();
        objLogin->tarkistaKortti(nro);
    }
}

void MainWindow::kuoletaKortti(int korttiID)
{
    QString korttiLukkoon =
    "	  VÄÄRÄ PIN-KOODI\n\nPin-koodi syötetty väärin liian monta kertaa\n        KorttiID#";
    korttiLukkoon.append(QString::number(korttiID));
    korttiLukkoon.append(" on poistettu käytöstä");
    ui->label_6->setText(korttiLukkoon);
    ui->label_6->show();
    ui->groupBox->hide();
    objTimer->singleShot(3500, this, SLOT(palautaNakyma()));
}


void MainWindow::loginValmis(int korttiID)
{
    objMenu = new menu;
    connect(objMenu, SIGNAL(kirjaaUlos()), this, SLOT(logout()));
    MainWindow::hide();
    objLogin->close();
    objMenu->show();
    objMenu->setKirjautumistiedot(korttiID);
    objTimer->stop();   // menun alla ei oo vielä signaaleja timerin resetointiin
    // väsää jonkinlainen aloita menu event
}

void MainWindow::logoutTimerReset()
{
    objTimer->start(30000);
}

void MainWindow::logoutIlmoitus()
{
    QString logoutTeksti;
    if(666 == 1)
    {
        logoutTeksti = "    AIKAPYSÄYTYS\n Sinut on nyt kirjattu ulos";
    }
    else
    {
        logoutTeksti = "         Kirjauduttu ulos";
    }
    ui->label_6->setText(logoutTeksti);
    ui->label_6->show();
    ui->groupBox->hide();
    objTimer->singleShot(3500, this, SLOT(palautaNakyma()));
}

void MainWindow::avaaLogin()
{
    ui->groupBox->hide();
    objLogin->setModal(true);
    int koodi = objLogin->exec();
    qDebug()<<"Lopetuskoodin on: "<<koodi;
    if(koodi == 0)
    {
        emit palautaNakyma();
    }
}

void MainWindow::logout()
{
    emit logoutIlmoitus();
    //objLogin->setKortti(0);
    //objLogin->logout();
    objMenu->close();
    delete objMenu;
    objMenu = nullptr;
    objTimer->stop();
    this->show();
}

