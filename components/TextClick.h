#ifndef TEXTCLICK_H
#define TEXTCLICK_H

#include <QLabel>
#include <QMouseEvent>
#include <QCursor>
#include <QPainter>

class TextClick : public QLabel {
    Q_OBJECT
public:
    TextClick(QWidget *parent = nullptr, bool showUnderline = false);
    ~TextClick();

signals:
    void textClicked();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    bool show;
};

#endif // TEXTCLICK_H
