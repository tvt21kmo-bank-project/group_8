#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT


public:
    explicit nosto(QWidget *parent, int, bool, int);
    ~nosto();
    void setupUI(QString);
    void summanValinta(int, int);
    void tarkistaKate(int);

private:
    Ui::nosto *ui;
    int tilinumero;
    bool creditValittu;
    int korttinumero;
    int muuSummaValikko;
    double nostettavaSumma;
    QTimer *objTimer;
    QNetworkAccessManager *atmManager;
    QNetworkAccessManager *nostoManager;
    QNetworkReply *reply;
    QByteArray response_data;

private slots:
    void on_btn20_clicked();
    void on_btn40_clicked();
    void on_btn60_clicked();
    void on_btn100_clicked();
    void on_btn200_clicked();
    void on_btn500_clicked();
    void on_btnMuu_clicked();
    void on_btnTakaisin_clicked();
    void on_btnOtaRahat_clicked();
    void onkoKatetta(QNetworkReply *reply);
    void onnistuikoNosto(QNetworkReply *reply);
    void timerLogout();
};

#endif // NOSTO_H
