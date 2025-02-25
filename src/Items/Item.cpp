#include "Item.h"

Item::Item(QGraphicsItem *parent, const QString &pixmapPath) : QGraphicsItem(parent)
{
    if (pixmapPath != "") {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    }

    //初始化攻击效果图片
    flameItem=new QGraphicsPixmapItem(QPixmap(":/Items/attacked/795f73dbbdc59760461a53ecea3267f0.gif"), this);
    iceItem=new QGraphicsPixmapItem(QPixmap(":/Items/attacked/45da19dce11dd571aa7de2fe54801f02.gif"), this);
    elecItem=new QGraphicsPixmapItem(QPixmap(":/Items/attacked/df940ca0d80338fc833ea0f12fabad96.gif"), this);
    flameItem->setVisible(false);
    iceItem->setVisible(false);
    elecItem->setVisible(false);
    flameItem->setScale(0.2);
    iceItem->setScale(0.2);
    elecItem->setScale(0.2);
    flameItem->setPos(-90,-200);
    flameItem->setZValue(5);
    iceItem->setPos(-90,-200);
    iceItem->setZValue(5);
    elecItem->setZValue(5);
    elecItem->setPos(-90,-200);
}
