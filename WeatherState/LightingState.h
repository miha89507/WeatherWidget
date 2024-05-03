#include <QPainter>
#include <QPolygonF>
#include <QWidget>

class LightingState {
public:
    LightingState(QWidget* parent, double inputXPosition,
                  double inputYPosition, double scale = 1.0);
    void changePosition(double inputXPosition, double inputYPosition);
    void draw();
    ~LightingState();

private:
    double      xPosition;
    double      yPosition;
    double      scale;
    QWidget*    parentWidget;
    QPolygonF   trapezoid;
    QPolygonF   triangle;
};
