#include "sword.h"
#include<QTransform>
Sword::Sword(QGraphicsItem *parent, const QString &pixmapPath):Item(parent, pixmapPath) {

}

void Sword::mountToParent()
{
    Mountable::mountToParent();
    setScale(0.5);
    setPos(-90, -160);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
        this->setZValue(4);
        pixmapItem->setZValue(4);
    }
}
void Sword::unmount() {                     //设置脱下效果
    Mountable::unmount();
    setScale(0.5);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void Sword::SwordAttack()
{
    QTransform transform;
    transform.translate(100,100).rotate(-45).translate(-100,-100);
    setTransform(transform);
}

void Sword::CompleteSwordAttack()
{
    setTransform(QTransform().rotate(0));
}
