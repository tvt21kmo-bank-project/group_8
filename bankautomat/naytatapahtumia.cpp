#include "naytatapahtumia.h"
#include "ui_naytatapahtumia.h"

naytaTapahtumia::naytaTapahtumia(QWidget *parent, int korttinro, int tilinro, bool credit) :
    QDialog(parent),
    ui(new Ui::naytaTapahtumia)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_PaintOnScreen);
    setParent(0);
    aloitusRivi = 0;
    korttinumero = korttinro;
    tilinumero = tilinro;
    creditValittu = credit;
    objTimer = new QTimer;
    connect(objTimer, &QTimer::timeout, this, close);
    objTimer->start(10000);
    haeTapahtumia();
    haeTilinTiedot();
}

naytaTapahtumia::~naytaTapahtumia()
{
    delete ui;
    delete objTimer;
    objTimer = nullptr;
}

void naytaTapahtumia::haeTapahtumia()
{
    QJsonObject json;
    json.insert("korttinro", korttinumero);
    json.insert("luotto", creditValittu);
    json.insert("montakoRivia", 10);
    json.insert("alkaenRivilta", aloitusRivi);
    QString site_url = "http://localhost:3000/pankki/tapahtumat";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    tapahtumaManager = new QNetworkAccessManager(this);
    connect(tapahtumaManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(tapahtumat(QNetworkReply*)));
    reply = tapahtumaManager->post(request, QJsonDocument(json).toJson());

    if(aloitusRivi > 0)
    {
        ui->btnEdelliset->setEnabled(true);
    }
    else
    {
        ui->btnEdelliset->setEnabled(false);
    }
}

void naytaTapahtumia::tapahtumat(QNetworkReply *reply)
{
    qDebug()<<"Tapahtumat haettu";
    int korttinro[10];
    QString aikaleima[10];
    QString tilitapahtuma[10];
    double summa[10];
    int i = 0;

    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       korttinro[i] = json_obj["korttinumero"].toInt();
       aikaleima[i] = json_obj["aikaleima"].toString();
       tilitapahtuma[i] = json_obj["tapahtuma"].toString();
       summa[i] = json_obj["summa"].toDouble();
       i++;
    }

    QString aikaleimatTuloste = "Pvm ja klo\n";
    QString summatTuloste = "Summa\n";
    QString tapahtumatTuloste = "Tapahtumatyyppi\n";
    QString maksajatTuloste = "Pankkikortti\n";
    for(int j=0; j < i; j++)
    {
        QString aikaleimanMuokkaus = aikaleima[j];
        aikaleimanMuokkaus.replace(10, 1, " ");
        aikaleimanMuokkaus.remove(19, 5);
        aikaleimatTuloste.append(aikaleimanMuokkaus+"\n");
        summatTuloste.append(QString::number(summa[j])+"\n");
        tapahtumatTuloste.append(tilitapahtuma[j]+"\n");
        maksajatTuloste.append(QString::number(korttinro[j])+"\n");
    }
    ui->textEditAikaleima->setText(aikaleimatTuloste);
    ui->textEditSumma->setText(summatTuloste);
    ui->textEditTapahtumatyyppi->setText(tapahtumatTuloste);
    ui->textEditMaksaja->setText(maksajatTuloste);

    if(i == 10)
    {
        ui->btnSeuraavat->setEnabled(true);
    }
    else
    {
        ui->btnSeuraavat->setEnabled(false);
    }
    reply->deleteLater();
}

void naytaTapahtumia::haeTilinTiedot()
{
    QJsonObject json;
    json.insert("id1", tilinumero);
    QString site_url = "http://localhost:3000/pankki/tili_Katsaus";
    QString credentials = "root:root";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", headerData.toLocal8Bit());
    tiliManager = new QNetworkAccessManager(this);
    connect(tiliManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(tilitiedot(QNetworkReply*)));
    reply = tiliManager->post(request, QJsonDocument(json).toJson());
}

void naytaTapahtumia::tilitiedot(QNetworkReply *reply)
{
    qDebug()<<"Tilitiedot haettu";
    double saldo ;
    double creditSaldo ;
    QString omistajanNimi;
    QByteArray response_data = reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    //qDebug()<<json_doc;
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array)
    {
       QJsonObject json_obj = value.toObject();
       saldo = json_obj["saldo"].toDouble();
       creditSaldo = json_obj["credit"].toDouble();
       omistajanNimi = json_obj["nimi"].toString();
    }

    ui->labelTilitiedot_tilinOmistaja->setText(omistajanNimi);
    ui->labelTilitiedot_tilinumero->setText(QString::number(tilinumero));
    if(creditValittu == true)
    {
        double luottoraja = -5000;              // demoaa tietokannan luottorajaa
        ui->labelTilitiedot_tilityyppi->setText("Credit");
        ui->labelTilitiedot_tilinSaldo->setText(QString::number(creditSaldo-luottoraja).append(" €"));
    }
    else
    {
        ui->labelTilitiedot_tilityyppi->setText("Debit");
        ui->labelTilitiedot_tilinSaldo->setText(QString::number(saldo).append(" €"));
    }
}

void naytaTapahtumia::on_btnTakaisin_clicked()
{
    this->close();
}

void naytaTapahtumia::on_btnEdelliset_clicked()
{
    objTimer->start(10000);
    aloitusRivi = aloitusRivi - 10;
    haeTapahtumia();
}

void naytaTapahtumia::on_btnSeuraavat_clicked()
{
    objTimer->start(10000);
    aloitusRivi = aloitusRivi + 10;
    haeTapahtumia();
}
