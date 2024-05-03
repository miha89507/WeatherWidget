#include "PixmapClickable.h"

PixmapClickable::PixmapClickable(QWidget* parent, const QPixmap& pixmap,
                                 double inputWidth, double inputHeight):
    QWidget(parent),
    m_pixmap(pixmap),
    width(inputWidth),
    height(inputHeight)
{}

void PixmapClickable::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);
    painter.drawPixmap(0, 0, width, height, m_pixmap);
}

void PixmapClickable::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

void PixmapClickable::enterEvent(QEnterEvent *event) {
    setCursor(Qt::PointingHandCursor);
}

void PixmapClickable::leaveEvent(QEvent *event) {
    unsetCursor();
}
