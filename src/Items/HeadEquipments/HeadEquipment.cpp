#include "HeadEquipment.h"

HeadEquipment::HeadEquipment(QGraphicsItem *parent, const QString &pixmapPath) : Item (parent, pixmapPath) {
}

void HeadEquipment::mountToParent()
{
    Mountable::mountToParent();
    setScale(0.4);
    setPos(-30, -210);
}
void HeadEquipment::unmount()
{
    Mountable::unmount();
    setScale(0.4);
    if (pixmapItem != nullptr)
    {
        pixmapItem->setPos(0, 0);
    }
}
