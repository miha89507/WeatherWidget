#include "SunState.h"

SunState::SunState(QWidget *parent, double xPosition,
                             double yPosition) :
    parentWidget(parent),
    xPosition(xPosition),
    yPosition(yPosition)
{}

void SunState::changePosition(double inputXPosition, double inputYPosition) {
    xPosition = inputXPosition;
    yPosition = inputYPosition;
}

void SunState::setAnimationFrameValue(double inputValue) {
    animationFrame = inputValue;
    if (animationFrame >= 360.0) {
        animationFrame -= 360.0;
    }
    qInfo() << "SunState::setAnimationFrameValue_animationFrame:" << animationFrame;
}

void SunState::draw() {
    QPainter painter(parentWidget);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor("#F7ED91"));
    painter.setPen(Qt::NoPen);
    QRectF rectangle1(xPosition, yPosition, 100, 100);
    painter.drawEllipse(rectangle1);

    double centerX = xPosition + 50.0;
    double centerY = yPosition + 50.0;
    double radius = 70.0;
    double rayRadius = 20.0;

    for (int i = 0; i < 8; ++i) {
        double angle = i * (360.0 / 8);
//                + animationFrame;
        double x = centerX + radius * std::cos(qDegreesToRadians(angle));
        double y = centerY + radius * std::sin(qDegreesToRadians(angle));
        QRectF rayRect(x - rayRadius / 2, y - rayRadius / 2, rayRadius, rayRadius);
        painter.drawEllipse(rayRect);
    }
}
