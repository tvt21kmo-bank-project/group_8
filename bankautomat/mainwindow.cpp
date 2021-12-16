#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->hide();
    ui->label_6->hide();

    objLogin = new login(this);
    objTimer = new QTimer;

    connect(objLogin, SIGNAL(korttiEiNatsaa()), this, SLOT(korttiEiNatsaa()), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(korttiOk()), this, SLOT(avaaLogin()), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(loginOk(int)), this, SLOT(loginValmis(int)), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(korttiAutuaammilleAutomaateille(int)), this, SLOT(kuoletaKortti(int)), Qt::QueuedConnection);
    connect(objTimer, SIGNAL(timeout()), this, SLOT(logout()));
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

void MainWindow::on_btnLueKortti_clicked()      // Kortti luettu ja tiedot välitetään login-luokalle tarkastettavaksi
{
    if(ui->lineEditKortti->text().toInt() > 0)
    {
        int nro = ui->lineEditKortti->text().toInt();
        ui->lineEditKortti->clear();
        objLogin->tarkistaKortti(nro);
    }
}

void MainWindow::loginValmis(int korttiID)      // Kirjautumistiedot ok ja login valmis. Käynnistetään pankkiautomaattiominaisuudet
{
    objMenu = new menu;
    connect(objMenu, SIGNAL(kirjaaUlos()), this, SLOT(logout()));
    MainWindow::hide();
    objLogin->close();
    objMenu->show();
    objMenu->setKirjautumistiedot(korttiID);
}
void MainWindow::avaaLogin()                    // Syötetty kortti löytyy tietokannasta. Avataan login form, jossa kysytään pin-koodi
{
    ui->groupBox->hide();
    objLogin->setModal(true);
    int koodi = objLogin->exec();
    if(koodi == 0)
    {
        emit palautaNakyma();
    }
}

void MainWindow::logout()                       // Slot, johon välitetään menusta signaalin kun kirjaudutaan ulos pankkiautomaatilta
{
    emit logoutIlmoitus();
    objLogin->logout();
    objMenu->close();
    delete objMenu;
    objMenu = nullptr;
    this->show();
}

void MainWindow::logoutIlmoitus()               // Ilmoitusviesti käyttäjälle, että kortilla on kirjauduttu pankkiautomaatilta ulos
{
    QString logoutTeksti = "Kirjauduttu ulos";
    ui->label_6->setText(logoutTeksti);
    ui->label_6->show();
    ui->groupBox->hide();
    objTimer->singleShot(3500, this, SLOT(palautaNakyma()));
}

void MainWindow::kuoletaKortti(int korttiID)    // Ilmoitusviesti käyttäjälle, että kortilla on liian monta virheellistä kirjautumisyritystä ja kortti on  kuoletettu
{
    QString korttiLukkoon =
    "	  VÄÄRÄ PIN-KOODI\n\nPin-koodi syötetty väärin liian monta kertaa\n        Doge söi korttin ID#"+QString::number(korttiID);
    ui->label_6->setText(korttiLukkoon);
    ui->label_6->show();
    ui->groupBox->hide();
    objTimer->singleShot(3500, this, SLOT(palautaNakyma()));
}

void MainWindow::korttiEiNatsaa()               // Ilmoitusviesti käyttäjälle, että syötettyä kortia ei löydy tietokannasta
{
    QString korttiEiNatsaa = "Virhe sisäänkirjautumisessa!\n   Tarkista syötetty kortti";
    ui->label_5->setText(korttiEiNatsaa);
    ui->label_5->show();
    ui->groupBox->hide();
    objTimer->singleShot(3500, this, SLOT(palautaNakyma()));
}

void MainWindow::palautaNakyma()                // Palauttaa formin alkuperäiseen ulkomuotoon
{
    ui->groupBox->show();
    ui->label_5->hide();
    ui->label_6->hide();
}
