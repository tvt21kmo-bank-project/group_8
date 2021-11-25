#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    luettuKortti = 0;
}

login::~login()
{
    delete ui;
}

void login::tarkistaKortti(int korttiID)
{
    emit korttiImastu(korttiID);/*
    QString site_url="http://localhost:3000/login/";
    site_url.append(QString::number(korttiID));
    QString credentials="root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;

    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

    korttiManager = new QNetworkAccessManager(this);
    connect(korttiManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(korttiSlot(QNetworkReply*)));
    reply = korttiManager->get(request);
    luettuKortti = korttiID;*/
}

void login::korttiSlot(QNetworkReply *reply)
{
    int korttiOk = 0;

    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       korttiOk=json_obj["pass"].toInt();
    }
    if(korttiOk == 1)
    {
        login::show();
    }
    else
    {
        emit korttiEiNatsaa();
    }
    reply->deleteLater();
}


void login::on_btnLogin_clicked()
{
    QJsonObject json;
    json.insert("korttinumero", luettuKortti);
    json.insert("pin", ui->lineEditLogin->text());
    QString site_url = "http://localhost:3000/login";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;

    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(json).toJson());

    ui->lineEditLogin->clear();

}

void login::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    if(response_data == "true")
    {
        emit loginOk(luettuKortti);
        luettuKortti = 0;
        login::hide();
        // nollaa väärät pinnit
    }
    else
    {
        //emit v
    }
    reply->deleteLater();
}

void login::virheellinenPin()
{


    /*if(pinVaarin == 3)
    {
        emit korttiImastu(int);
        luettuKortti = 0;
        reply->deleteLater();
    }*/
}
