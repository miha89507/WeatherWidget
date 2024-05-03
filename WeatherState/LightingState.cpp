#include "LightingState.h"

LightingState::LightingState(QWidget *parent, double xPositionPosition,
                             double yPositionPosition, double scale) :
    parentWidget(parent),
    xPosition(xPositionPosition),
    yPosition(yPositionPosition),
    scale(scale)
{}

void LightingState::changePosition(double xPositionPosition, double yPositionPosition) {
    xPosition = xPositionPosition;
    yPosition = yPositionPosition;
}

void LightingState::draw() {
    QPainter painter(parentWidget);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#F7B40F"));
    trapezoid << QPointF(xPosition + 60 * scale, yPosition)
              << QPointF(xPosition + 150 * scale, yPosition)
              << QPointF(xPosition + 100 * scale, yPosition + 100 * scale)
              << QPointF(xPosition + 50 * scale, yPosition + 100 * scale);

    triangle << QPointF(xPosition + 100 * scale, yPosition + 60 * scale)
             << QPointF(xPosition + 155 * scale, yPosition + 60 * scale)
             << QPointF(xPosition + 60 * scale, yPosition + 180 * scale);
    painter.drawPolygon(trapezoid);
    painter.drawPolygon(triangle);
}
