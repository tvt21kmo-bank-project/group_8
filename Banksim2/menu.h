#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>



namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();



private:
    Ui::menu *ui;
    QNetworkAccessManager *debitManager;
    QNetworkReply *reply;
};

#endif // MENU_H
