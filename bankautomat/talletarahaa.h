#ifndef TALLETARAHAA_H
#define TALLETARAHAA_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class talletaRahaa;
}

class talletaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit talletaRahaa(QWidget *parent, int, int);
    ~talletaRahaa();
    void setupUI(QString);

private slots:
    void on_btnTakaisin_clicked();
    void on_btnTalleta_clicked();
    void talletusTehty(QNetworkReply *reply);

private:
    Ui::talletaRahaa *ui;
    int tilinumero;
    int korttinumero;
    QTimer *objTimer;
    QNetworkAccessManager *panoManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TALLETARAHAA_H
