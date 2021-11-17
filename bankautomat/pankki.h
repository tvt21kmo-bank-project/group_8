#ifndef PANKKI_H
#define PANKKI_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace Ui {
class pankki;
}

class pankki : public QDialog
{
    Q_OBJECT

public:
    explicit pankki(QWidget *parent = 0);
    ~pankki();

private slots:
    void on_btnSiirto_clicked();
    void debitSlot(QNetworkReply *reply);

private:
    Ui::pankki *ui;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
};

#endif // PANKKI_H
