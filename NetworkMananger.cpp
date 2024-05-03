#include "NetworkMananger.h"

NetworkMananger::NetworkMananger(){
    mananger = new QNetworkAccessManager();
}

void NetworkMananger::setUrl(QString inputUrl) {
    url = new QUrl(inputUrl);
    request = new QNetworkRequest(*url);
    request->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request->setTransferTimeout(3000);
}

void NetworkMananger::setPostData(QVector<queryData> &inputPostData) {
    postData = new QUrlQuery();
    if (static_cast<bool>(inputPostData.size())) {
        for (int vectorIndex = 0; vectorIndex < inputPostData.size(); vectorIndex++) {
            postData->addQueryItem(inputPostData.at(vectorIndex).key,
                                   inputPostData.at(vectorIndex).value);
        }
    }
}

void NetworkMananger::runPostQuest() {
    response = mananger->post(*request, postData->toString(QUrl::FullyEncoded).toUtf8());
    QObject::connect(response, &QNetworkReply::finished, [&]() {
        if (response->error() == QNetworkReply::NoError) {
            emit sentResultQuest(QJsonDocument::fromJson(response->readAll()).object());
        } else {
            const QJsonObject emptyObj;
            emit sentResultQuest(emptyObj);
        }
    });
}

NetworkMananger::~NetworkMananger(){}
