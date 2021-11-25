#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_btnLogin_clicked();
    void tarkistaKortti(int);
    void korttiSlot(QNetworkReply *reply);
    void loginSlot(QNetworkReply *reply);
    void virheellinenPin();

private:
    Ui::login *ui;
    int luettuKortti;
    QNetworkAccessManager *korttiManager;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

signals:
    void korttiEiNatsaa();
    void korttiImastu(int);
    void loginOk(int);
};

#endif // LOGIN_H
