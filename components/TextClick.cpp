#include "textclick.h"

TextClick::TextClick(QWidget *parent, bool showUnderline):
    QLabel(parent),
    show(showUnderline)
{}

TextClick::~TextClick(){}

void TextClick::paintEvent(QPaintEvent *event) {
    QLabel::paintEvent(event);

    if (show) {
        QPainter painter(this);
        QColor textColor = palette().color(QPalette::WindowText);
        painter.setPen(QPen(textColor, 1, Qt::DashLine));
        painter.drawLine(0, height() - 1, width(), height() - 1);
    }
}

void TextClick::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit textClicked();
    }
}

void TextClick::enterEvent(QEnterEvent *event) {
    QLabel::enterEvent(event);
    setCursor(Qt::PointingHandCursor);
}

void TextClick::leaveEvent(QEvent *event) {
    QLabel::leaveEvent(event);
    unsetCursor();
}
