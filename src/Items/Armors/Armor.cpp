#include "Armor.h"

Armor::Armor(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

}

void Armor::mountToParent()
{
    Mountable::mountToParent();             //设置穿戴效果
    setScale(0.8);
    setPos(-59, -177);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Armor::unmount() {                     //设置脱下效果
    Mountable::unmount();
    setScale(0.5);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}
