#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->label_2->hide();
    // Kikkailtu login-formista tausta pois ja liitetty mainwindowin formin päälle
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);

    objTimer = new QTimer;
    luettuKortti = 0;
    connect(objTimer, &QTimer::timeout, this, logout);
    qDebug()<<"login luotu";
}

login::~login()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
    qDebug()<<"login tuhottu";
}

void login::logout()
{
    luettuKortti = 0;
    this->reject();
}

void login::tarkistaKortti(int korttiID)
{
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
    qDebug()<<"kortti tarkastettu";
    luettuKortti = korttiID;
}

void login::korttiSlot(QNetworkReply *reply)
{
    qDebug()<<"slotissa";
    int tulos = 0;
    response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       tulos=json_obj["pass"].toInt();
    }
    qDebug()<<tulos;
    if(tulos == 1)
    {
        objTimer->start(10000);
        emit korttiOk();
    }
    else
    {
        luettuKortti = 0;
        emit korttiEiNatsaa();
    }
    reply->deleteLater();
}

void login::on_btnLogin_clicked()
{
    emit resetTimer();
    qDebug()<<"nappi painettu";
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
    qDebug()<<response_data;
    if(response_data == "true")
    {
        // nollaa väärät pinnit
        QJsonObject json;
        json.insert("korttinumero", luettuKortti);
        json.insert("pin", 0);
        QString site_url = "http://localhost:3000/pankkikortti/pin";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        pinManager = new QNetworkAccessManager(this);
        reply = pinManager->post(request, QJsonDocument(json).toJson());
        emit loginOk(luettuKortti);
        luettuKortti = 0;
        this->accept();
        //reply->deleteLater();
    }
    else if(response_data == "err")
    {
        //
    }
    else
    {
        qDebug()<<"väärä pin laskentaan";
        QJsonObject json;
        json.insert("korttinumero", luettuKortti);
        json.insert("pin", 1);
        QString site_url = "http://localhost:3000/pankkikortti/pin";
        QString credentials = "root:root";
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", headerData.toLocal8Bit());
        pinManager1= new QNetworkAccessManager(this);
        connect(pinManager1, SIGNAL(finished(QNetworkReply*)),this, SLOT(kortinKuoletusEhka(QNetworkReply*)));
        reply = pinManager1->post(request, QJsonDocument(json).toJson());
    }
}

void login::kortinKuoletusEhka(QNetworkReply *reply)
{
    int vaarinLkm = 0;
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       vaarinLkm = json_obj["lkm"].toInt();
    }
    qDebug()<<vaarinLkm;
    if(vaarinLkm >= 3)
    {
        /*QString site_url="http://localhost:3000/pankkikortti/poista/";       // poistettu käytöstä testien ajaksi
        site_url.append(QString::number(luettuKortti));
        QString credentials="root:root";
        QNetworkRequest request((site_url));
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        getManager = new QNetworkAccessManager(this);
        reply = getManager->get(request);*/

        emit korttiAutuaammilleAutomaateille(luettuKortti);
        luettuKortti = 0;
        this->reject();
    }
    else
    {
        qDebug()<<"elselauseessa";
        ui->groupBox->hide();
        ui->label_2->show();
        objTimer->singleShot(3500,[=]()
        {
            ui->groupBox->show();
            ui->label_2->hide();
        });
    }
    //reply->deleteLater();
}

void login::resetLogoutTimer()
{
    objTimer->start(10000);
}

