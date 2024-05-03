#ifndef NETWORKMANANGER_H
#define NETWORKMANANGER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVector>

#include <QueryDataStruct.h>

class NetworkMananger: public QObject {
    Q_OBJECT
signals:
    void sentResultQuest(const QJsonObject &data);

public:
    NetworkMananger();
    void setUrl(QString inputUrl);
    void setPostData(QVector<queryData>&inputPostData);
    void runPostQuest();
    ~NetworkMananger();

private:
    QNetworkAccessManager*  mananger;
    QUrlQuery*              postData;
    QNetworkReply*          response;
    QUrl*                   url;
    QNetworkRequest*        request;
};

#endif // NETWORKMANANGER_H
