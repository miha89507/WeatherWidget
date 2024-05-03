#include "BlobComponent.h"
#include <QWidget>

class RainState{
public:
    RainState(QWidget* parent, double inputXPosition,
              double inputYPosition);
    void draw();
    ~RainState();

private:
    double          xPosition;
    double          yPosition;
    QWidget*        parentWidget;
    BlobComponent*  blobFirst;
    BlobComponent*  blobSecond;
    BlobComponent*  blobThird;
};
