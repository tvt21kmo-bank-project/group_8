#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objPankki = new pankki;
    //objPankki->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete objPankki;
    objPankki = nullptr;
}

void MainWindow::on_btnKirjaudu_clicked()
{
    QJsonObject json;
    json.insert("username", ui->leKt->text());
    json.insert("password", ui->leSs->text());
    QString site_url = "http://localhost:3000/login";
    QString credentials = "1:1234";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)),
            this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(json).toJson());
}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    qDebug() << response_data;
    if(response_data == "true")
    {
        qDebug() << "Oikea tunnus.. avaa form";
        objPankki->show();
    }
    else
    {
        ui->leKt->setText("");
        ui->leSs->setText("");
        qDebug() << "Väärä tunnus nännännää";
    }
}
