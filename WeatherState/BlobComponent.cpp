#include "blobcomponent.h"

BlobComponent::BlobComponent(QWidget *parent, double inputXPosition,
                             double inputYPosition, double scale) :
    parentWidget(parent),
    xPosition(inputXPosition),
    yPosition(inputYPosition),
    scale(scale)
{}

void BlobComponent::changePosition(double inputXPosition, double inputYPosition) {
    xPosition = inputXPosition;
    yPosition = inputYPosition;
}

void BlobComponent::draw() {
    QPainter painter(parentWidget);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#6DADD7"));
    triangle << QPointF(xPosition + 100 * scale, yPosition)
             << QPointF(xPosition + 61.5 * scale, yPosition + 40 * scale)
             << QPointF(xPosition + 85 * scale, yPosition + 50 * scale);
    elipse = new QRectF(xPosition + 61.5 * scale, yPosition + 32.5 * scale,
                     25 * scale, 25 * scale);
    painter.drawPolygon(triangle);
    painter.drawEllipse(*elipse);
}
