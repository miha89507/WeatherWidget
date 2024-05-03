#include <QPainter>
#include <QRectF>
#include <QWidget>

class CloudState {
public:
    CloudState(QWidget* parent, double inputXPosition, double inputYPosition);
    void changePosition(double inputXPosition, double inputYPosition);
    void draw();
    ~CloudState();

private:
    double      xPosition;
    double      yPosition;
    QWidget*    parentWidget;
    QRectF*     rectangle1;
    QRectF*     rectangle2;
    QRectF*     rectangle3;
};
