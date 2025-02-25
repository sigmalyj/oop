#include "bow.h"

Bow::Bow(QGraphicsItem *parent, const QString &pixmapPath):Item(parent, pixmapPath) {

}

void Bow::mountToParent()
{
    Mountable::mountToParent();
    setScale(0.5);
    setPos(-59, -177);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}
