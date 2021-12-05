#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "menu.h"
#include "creditvaidebit.h"

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

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    menu *objmenu;
    creditvaidebit *objkysy;
};

#endif // MAINWINDOW_H
