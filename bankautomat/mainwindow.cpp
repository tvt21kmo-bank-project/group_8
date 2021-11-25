#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objLogin = new login;
    objMenu = new menu;
    ui->label_5->hide();
    ui->label_6->hide();
    connect(objLogin, SIGNAL(korttiEiNatsaa()), this, SLOT(korttiEiNatsaa()), Qt::QueuedConnection);
    connect(this, SIGNAL(korttiLuettu(int)), objLogin, SLOT(tarkistaKortti(int)), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(korttiImastu(int)), this, SLOT(kuoletaKortti(int)), Qt::QueuedConnection);
    connect(objLogin, SIGNAL(loginOk(int)), this, SLOT(loginValmis(int)), Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objLogin;
    objLogin = nullptr;
    delete objMenu;
    objMenu = nullptr;
}

void MainWindow::korttiEiNatsaa()
{
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->show();
    ui->lineEditKortti->hide();
    ui->btnLueKortti->hide();
    QTimer::singleShot(3500, this, SLOT(palautaNakyma()));
}

void MainWindow::palautaNakyma()
{
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->lineEditKortti->show();
    ui->btnLueKortti->show();
}

void MainWindow::on_btnLueKortti_clicked()
{
    if(ui->lineEditKortti->text().toInt() > 0)
    {
        emit korttiLuettu(ui->lineEditKortti->text().toInt());
        ui->lineEditKortti->clear();
    }
}

void MainWindow::kuoletaKortti(int korttiID)
{
    QString pinVaarin =
    "	  VÄÄRÄ PIN-KOODI\n\nPin-koodi syötetty väärin liian monta kertaa\n        KorttiID#";
    pinVaarin.append(QString::number(korttiID));
    pinVaarin.append(" on poistettu käytöstä");
    ui->label_6->setText(pinVaarin);
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_6->show();
    ui->lineEditKortti->hide();
    ui->btnLueKortti->hide();
    QTimer::singleShot(3500, this, SLOT(palautaNakyma()));

    // KUOLETETAAN KORTTI POISTAMALLA SE TIETOKANNASTA //
    QString site_url="http://localhost:3000/pankkikortti/poista/";
    site_url.append(QString::number(korttiID));
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    getManager = new QNetworkAccessManager(this);
    //connect(getManager, SIGNAL(finished (QNetworkReply*)), objMenu, SLOT(avaaMenu(QNetworkReply*)));
    reply = getManager->get(request);
}

void MainWindow::loginValmis(int korttiID)
{
    MainWindow::hide();

    QString site_url="http://localhost:3000/pankkikortti/";
    site_url.append(QString::number(korttiID));
    QString credentials="root:root";
    QNetworkRequest request((site_url));
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

    mainManager = new QNetworkAccessManager(this);
    connect(mainManager, SIGNAL(finished (QNetworkReply*)), objMenu, SLOT(avaaMenu(QNetworkReply*)));
    reply = mainManager->get(request);
}
