#include "sword.h"

Sword::Sword(QGraphicsItem *parent, const QString &pixmapPath):Item(parent, pixmapPath) {

}

void Sword::mountToParent()
{
    Mountable::mountToParent();
    setScale(0.5);
    setPos(-90, -160);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}
