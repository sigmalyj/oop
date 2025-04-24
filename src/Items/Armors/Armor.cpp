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

    // if (parentItem() != nullptr) {
    //     // 获取父对象的中心点
    //     QPointF parentCenter = parentItem()->boundingRect().center();

    //     // 可视化中心点：绘制一个小圆点
    //     QGraphicsEllipseItem *centerMarker = new QGraphicsEllipseItem(-5, -5, 10, 10, parentItem());
    //     centerMarker->setBrush(Qt::red); // 设置为红色
    //     centerMarker->setPos(parentCenter); // 将圆点放置在中心点
    // }
}

void Armor::unmount() {                     //设置脱下效果
    Mountable::unmount();
    setScale(0.5);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}
