#ifndef GRADIENTWIDGET_H
#define GRADIENTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QLinearGradient>
#include <QPushButton>
#include <QIcon>
#include <QPixmap>
#include <QTimer>
#include <QFont>
#include <QMouseEvent>
#include <cmath>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QDebug>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "components/TextClick.h"
#include "components/PixmapClickable.h"
#include "components/InputCityDialog.h"
#include "CloudState.h"
#include "LightingState.h"
#include "SunState.h"
#include "RainState.h"
#include "NetworkMananger.h"
#include "QueryDataStruct.h"

class GradientWidget : public QWidget {
    Q_OBJECT
public:
    explicit GradientWidget(QWidget* parent=nullptr);
    void paintEvent(QPaintEvent *) override;

public slots:
    void getResultQuest(const QJsonObject&data);
    void getConfirmCity(QString getCity);

signals:
    void questWasUpdated();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


private:
    QPoint              dragStartPosition;
    SunState*           sunState;
    CloudState*         cloudeState;
    LightingState*      lightingState;
    RainState*          rain;
    QLabel*             lastUpdateWeatherDate;
    QLabel*             infoAboutTemperature;
    QLabel*             errorStatusImg;
    QLabel*             errorStatusText;
    QJsonObject         resultQuest;
    QString             getCityFromDialog;
    TextClick*          closeClickableText;
    TextClick*          chooseCityClickableText;
    PixmapClickable*    pixmapClickable;
    PixmapClickable*    resizedLocationIcon;
    NetworkMananger*    netMg;
    InputCityDialog*    cityDialog;
    int                 loadStatus;

    void initInfoAboutTemperature();
    void initUpdateWeatherBtn();
    void initCloseWeatherBtn();
    void initChooseCityWeatherBtn();
    void initLastUpdateWeatherDate();
    void initConnectionError();

    void paintCloud(double inputX, double inputY);
    void paintSun(double inputX, double inputY);
    void paintLightning(double inputX, double inputY);
    void paintRain(double inputX, double inputY);
    void paintTemperature(int inputTemperature);
    void paintUpdateWeatherDate(QString inputValue);
    void clearWidget();
    void paintNoConnection();
    void preparePost(QString inputCity);
    void sentPost();

    int countDigits(int number);
};

#endif // GRADIENTWIDGET_H
