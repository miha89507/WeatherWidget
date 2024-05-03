#include "CloudState.h"

CloudState::CloudState(QWidget *parent, double inputXPosition, double inputYPosition) :
    parentWidget(parent),
    xPosition(inputXPosition),
    yPosition(inputYPosition) {}

void CloudState::changePosition(double inputXPosition, double inputYPosition) {
    xPosition = inputXPosition;
    yPosition = inputYPosition;
}

void CloudState::draw() {
    QPainter painter(parentWidget);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor("#E5E5E5"));
    painter.setPen(Qt::NoPen);
    rectangle1 = new QRectF(xPosition, yPosition, 100.0, 100.0);
    rectangle2 = new QRectF(xPosition + 60.0, yPosition - 30, 150.0, 150.0);
    rectangle3 = new QRectF(xPosition + 180.0, yPosition + 10, 75.0, 75.0);
    painter.drawEllipse(*rectangle1);
    painter.drawEllipse(*rectangle2);
    painter.drawEllipse(*rectangle3);
}
