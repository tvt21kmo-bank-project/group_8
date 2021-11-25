#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private:
    Ui::menu *ui;
    QByteArray response_data;
    QNetworkReply *reply;
    QNetworkAccessManager *getManager;

private slots:
    void avaaMenu(QNetworkReply *reply);

signals:

};

#endif // MENU_H
