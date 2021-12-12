#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QApplication>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include "login.h"
#include "menu.h"
#include <QDialog>

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
    menu *objMenu;
    login *objLogin;
    QTimer *objTimer;

private slots:
    void korttiEiNatsaa();
    void palautaNakyma();
    void on_btnLueKortti_clicked();
    void kuoletaKortti(int);
    void loginValmis(int);
    void logoutTimerReset();
    void logout();
    void logoutIlmoitus();
    void avaaLogin();

signals:
    void nollaaLogoutTimer();
};

#endif // MAINWINDOW_H
