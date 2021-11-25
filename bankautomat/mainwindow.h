#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include "login.h"
#include "menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *getManager;
    QNetworkAccessManager *mainManager;
    QNetworkReply *reply;
    QByteArray response_data;
    menu *objMenu;
    login *objLogin;

private slots:
    void korttiEiNatsaa();
    void palautaNakyma();
    void on_btnLueKortti_clicked();
    void kuoletaKortti(int);
    void loginValmis(int);

signals:
    void korttiLuettu(int);
};

#endif // MAINWINDOW_H
