#include "arrow.h"

Arrow::Arrow(QGraphicsItem *parent, const QString &pixmapPath):Item(parent, pixmapPath) {

}

void Arrow::mountToParent()
{
    Mountable::mountToParent();
    // setScale(0.5);
    // setPos(-90, -160);
    // if (pixmapItem != nullptr) {
    //     pixmapItem->setPos(0, 0);
    // }
}
void Arrow::unmount() {                     //设置脱下效果
    Mountable::unmount();
    setScale(0.5);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}
