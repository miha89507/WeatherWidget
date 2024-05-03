#include "GradientWidget.h"

GradientWidget::GradientWidget(QWidget* parent) : QWidget(parent) {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowOpacity(0.8);

    /*INITIALIZATION*/
    cityDialog = new InputCityDialog(this);

    loadStatus = 0;
    netMg = new NetworkMananger();
    this->initInfoAboutTemperature();
    this->initUpdateWeatherBtn();
    this->initChooseCityWeatherBtn();
    this->initCloseWeatherBtn();
    this->initLastUpdateWeatherDate();
    this->initConnectionError();

    /*CONNECTING SIGNAL-SLOT*/
    connect(closeClickableText, &TextClick::textClicked, this, [this](){
        close();
    });

    connect(netMg, &NetworkMananger::sentResultQuest, this, &GradientWidget::getResultQuest);

    connect(this, &GradientWidget::questWasUpdated, this, [this](){
        update();
    });

    connect(pixmapClickable, &PixmapClickable::clicked, this, [this](){
        this->preparePost(getCityFromDialog);
        this->sentPost();
    });

    connect(chooseCityClickableText, &TextClick::textClicked, this, [this](){
        cityDialog->exec();
    });

    connect(resizedLocationIcon, &PixmapClickable::clicked, this, [this](){
        cityDialog->exec();
    });

    connect(cityDialog, &InputCityDialog::confirmCity, this, &GradientWidget::getConfirmCity);
}

void GradientWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragStartPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void GradientWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton){
        move(event->globalPos() - dragStartPosition);
        event->accept();
    }
}

void GradientWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(0, QColor("#8DB9EB"));
    gradient.setColorAt(1, QColor("#3B517D"));
    painter.fillRect(rect(), gradient);

    if (loadStatus != 0) {
        if (!resultQuest.isEmpty()){
            QString status = resultQuest["current"]
                    .toObject()["condition"]
                    .toObject()["text"].toString();
            int temeratureCelsia = resultQuest["current"]
                    .toObject()["temp_c"].toInt();
            double precipMM = resultQuest["current"]
                    .toObject()["precip_mm"].toDouble();
            QString lastUpdateWeatherDateValue = resultQuest["current"]
                    .toObject()["last_updated"].toString();

            if (status.indexOf("Light") != -1) {
                this->paintLightning(160, 190);
            }

            if (status.indexOf("Partly cloudy") != -1) {
                this->paintCloud(70, 90);
            }

            if (status.indexOf("Sunny") != -1) {
                this->paintSun(150, 100);
            }

            if (precipMM > 0) {
                this->paintRain(170, 210);
                this->paintCloud(70, 90);
            }

            this->paintTemperature(temeratureCelsia);
            this->paintUpdateWeatherDate(lastUpdateWeatherDateValue);
        } else {
            this->paintNoConnection();
        }
    }
}

void GradientWidget::initInfoAboutTemperature() {
    infoAboutTemperature = new QLabel(this);
    infoAboutTemperature->setText("         ");
    infoAboutTemperature->setFont(QFont("Arial", 72));
    infoAboutTemperature->setStyleSheet("color: #E5E5E5");
    infoAboutTemperature->move(90, 300);
}

void GradientWidget::initUpdateWeatherBtn() {
    QPixmap reloadIcon("{path to icon}//refresh.png");
    pixmapClickable = new PixmapClickable(this, reloadIcon.scaled(size()/16,
                                        Qt::KeepAspectRatio, Qt::SmoothTransformation),
                                        20, 20);
    pixmapClickable->move(30, 15);
}

void GradientWidget::initCloseWeatherBtn() {
    closeClickableText = new TextClick(this);
    closeClickableText->setText("x");
    closeClickableText->setAlignment(Qt::AlignCenter);
    closeClickableText->setFont(QFont("Arial bold", 20));
    closeClickableText->setStyleSheet("color: #E5E5E5");
    closeClickableText->move(370, 10);
}

void GradientWidget::initChooseCityWeatherBtn() {
    QPixmap locationIcon("{path to icon}//location.png");
    resizedLocationIcon = new PixmapClickable(this, locationIcon.scaled(size()/16,
                                        Qt::KeepAspectRatio, Qt::SmoothTransformation),
                                        20, 20);
    resizedLocationIcon->move(160, 15);

    chooseCityClickableText = new TextClick(this, true);
    chooseCityClickableText->setText("City");
    chooseCityClickableText->setAlignment(Qt::AlignCenter);
    chooseCityClickableText->setFont(QFont("Arial bold", 16));
    chooseCityClickableText->setStyleSheet("color: #E5E5E5; ");
    chooseCityClickableText->move(180, 15);
}

void GradientWidget::initLastUpdateWeatherDate() {
    lastUpdateWeatherDate = new QLabel(this);
    lastUpdateWeatherDate->setText("");
    lastUpdateWeatherDate->setAlignment(Qt::AlignCenter);
    lastUpdateWeatherDate->setFont(QFont("Arial bold", 12));
    lastUpdateWeatherDate->setStyleSheet("color: #E5E5E5");
    lastUpdateWeatherDate->move(80, 400);
    lastUpdateWeatherDate->setVisible(false);
}

void GradientWidget::initConnectionError() {
    errorStatusImg = new QLabel(this);
    QPixmap sadSmileIcon("{path to icon}//sadSmile.png");
    QPixmap sadSmileResized(sadSmileIcon.scaled(size()/2,
                                                Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
    errorStatusImg->setPixmap(sadSmileResized);
    errorStatusImg->move(80, 100);
    errorStatusImg->setVisible(false);

    errorStatusText = new QLabel(this);
    errorStatusText->setText("Something go wrong...");
    errorStatusText->setAlignment(Qt::AlignCenter);
    errorStatusText->setFont(QFont("Arial bold", 20));
    errorStatusText->setStyleSheet("color: #E5E5E5");
    errorStatusText->move(80, 360);
    errorStatusText->setVisible(false);
}

void GradientWidget::paintSun(double inputX, double inputY) {
    sunState = new SunState(this, inputX, inputY);
    sunState->draw();
}

void GradientWidget::paintCloud(double inputX, double inputY) {
   cloudeState = new CloudState(this, inputX, inputY);
   cloudeState->draw();
}

void GradientWidget::paintLightning(double inputX, double inputY) {
    lightingState = new LightingState(this, inputX, inputY, 0.6);
    lightingState->draw();
}

void GradientWidget::paintRain(double inputX, double inputY) {
    rain = new RainState(this, inputX, inputY);
    rain->draw();
}

void GradientWidget::paintTemperature(int inputTemperature) {
    switch(this->countDigits(inputTemperature)) {
        case 1: {
            infoAboutTemperature->setText(" " + QString::number(inputTemperature) + "°C");
            break;
        }

        default: {
            infoAboutTemperature->setText(QString::number(inputTemperature) + "°C");
            break;
        }
    }
    infoAboutTemperature->setVisible(true);
}

void GradientWidget::paintUpdateWeatherDate(QString inputValue) {
    lastUpdateWeatherDate->setText("Last update date: " + inputValue);
    lastUpdateWeatherDate->setVisible(true);
}

void GradientWidget::paintNoConnection() {
    errorStatusImg->setVisible(true);
    errorStatusText->setVisible(true);
}

void GradientWidget::preparePost(QString inputCity) {
    QVector<queryData> inputData = {
        {"key", "{YOUR KEY FROM https://www.weatherapi.com/}"},
        {"q", inputCity},
        {"aqi", "yes"}
    };

    netMg->setUrl("http://api.weatherapi.com/v1/current.json");
    netMg->setPostData(inputData);
}

void GradientWidget::sentPost() {
    netMg->runPostQuest();
}

void GradientWidget::clearWidget() {
    QPainter painter(this);
    QLinearGradient gradient(0, 0, width(), height());
    gradient.setColorAt(0, QColor("#8DB9EB"));
    gradient.setColorAt(1, QColor("#3B517D"));
    painter.fillRect(rect(), gradient);

    lastUpdateWeatherDate->setVisible(false);
    infoAboutTemperature->setVisible(false);
    errorStatusImg->setVisible(false);
    errorStatusText->setVisible(false);
    update();
}

void GradientWidget::getResultQuest(const QJsonObject& data) {
    resultQuest = data;
    loadStatus = 1;
    this->clearWidget();
    emit questWasUpdated();
}

void GradientWidget::getConfirmCity(QString getCity) {;
    chooseCityClickableText->setText(getCity);
    chooseCityClickableText->adjustSize();
    resizedLocationIcon->move(160 - ((getCity.size() - 4) * 2), 15);
    getCityFromDialog = getCity;
    this->preparePost(getCityFromDialog);
    this->sentPost();
}

int GradientWidget::countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}
