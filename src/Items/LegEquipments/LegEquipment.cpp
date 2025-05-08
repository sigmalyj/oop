#include "LegEquipment.h"

LegEquipment::LegEquipment(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {
}

void LegEquipment::mountToParent() {
    Mountable::mountToParent();
    setScale(0.8);
    setPos(-60, -110);
    scale = 0.8;
    this->setZValue(3);
    pixmapItem->setZValue(3);
    pixmapItem->setPos(0, 0);
}

void LegEquipment::unmount()
{
    Mountable::unmount();
    setScale(0.4);
    if (pixmapItem != nullptr)
    {
        pixmapItem->setPos(0, 0-120);
    }
}
