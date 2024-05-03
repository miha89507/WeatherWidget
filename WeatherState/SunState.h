#include <QPainter>
#include <QRectF>
#include <QWidget>

class SunState {
public:
    SunState(QWidget* parent, double inputXPosition,
                  double inputYPosition);
    void changePosition(double inputXPosition, double inputYPosition);
    void setAnimationFrameValue(double inputValue);
    void draw();
    void clear();
    ~SunState();

private:
    double      xPosition;
    double      yPosition;
    double      animationFrame;
    QWidget*    parentWidget;
    QRectF      rectangle;
};
