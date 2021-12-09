#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "creditvaidebit.h"
#include "menu.h"
#include "saldo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnKirjaudu_clicked();
    void loginSlot(QNetworkReply *reply);

    void on_btnperu_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    creditvaidebit *objkysy;
    menu *objmenu;


};

#endif // MAINWINDOW_H
