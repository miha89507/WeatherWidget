#include "RainState.h"

RainState::RainState(QWidget *parent, double inputXPosition, double inputYPosition) :
    parentWidget(parent),
    xPosition(inputXPosition),
    yPosition(inputYPosition) {
    blobFirst = new BlobComponent(parentWidget, xPosition - 50,
                                  yPosition + 40, 0.3);
    blobSecond = new BlobComponent(parentWidget, xPosition,
                                  yPosition, 0.3);
    blobThird = new BlobComponent(parentWidget, xPosition + 50,
                                  yPosition + 60, 0.3);
}

void RainState::draw() {
    blobFirst->draw();
    blobSecond->draw();
    blobThird->draw();
}
