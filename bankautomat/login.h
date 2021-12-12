#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QAbstractButton>
#include <QTimer>
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void logout();
    void tarkistaKortti(int);

private slots:
    void on_btnLogin_clicked();
    void korttiSlot(QNetworkReply *reply);
    void loginSlot(QNetworkReply *reply);
    void pinTarkastus(QNetworkReply *reply);
    void resetLogoutTimer();

private:
    Ui::login *ui;
    int luettuKortti;
    QNetworkAccessManager *korttiManager;
    QNetworkAccessManager *loginManager;
    QNetworkAccessManager *pinManager;
    QNetworkAccessManager *pinManager1;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QTimer *objTimer;

signals:
    void korttiEiNatsaa();
    void korttiAutuaammilleAutomaateille(int);
    void korttiOk();
    void loginOk(int);
    void resetTimer();
};

#endif // LOGIN_H
