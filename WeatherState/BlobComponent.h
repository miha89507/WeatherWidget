#include <QPainter>
#include <QPolygonF>
#include <QRectF>
#include <QWidget>


class BlobComponent {
public:
    BlobComponent(QWidget* parent, double inputXPosition,
                  double inputYPosition, double scale = 1.0);
    void changePosition(double inputXPosition, double inputYPosition);
    void draw();
    ~BlobComponent();

private:
    double      xPosition;
    double      yPosition;
    double      scale;
    QWidget*    parentWidget;
    QPolygonF   triangle;
    QRectF*     elipse;
};
