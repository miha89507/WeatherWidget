#ifndef PIXMAPCLICKABLE_H
#define PIXMAPCLICKABLE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QEvent>
#include <QCursor>

class PixmapClickable :  public QWidget {
    Q_OBJECT

public:
    PixmapClickable(QWidget* parent, const QPixmap& pixmap,
                    double inputWidth, double inputHeight);

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    QPixmap         m_pixmap;
    double          width;
    double          height;
};

#endif // PIXMAPCLICKABLE_H
