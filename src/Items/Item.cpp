#include "Item.h"

Item::Item(QGraphicsItem *parent, const QString &pixmapPath) : QGraphicsItem(parent)
{
    if (pixmapPath != "") {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    }

    //初始化攻击效果图片
    flameItem=new QGraphicsPixmapItem(QPixmap(":/Items/attacked/FlameAttack.gif"), this);
    iceItem=new QGraphicsPixmapItem(QPixmap(":/Items/attacked/IceAttack.gif"), this);
    elecItem=new QGraphicsPixmapItem(QPixmap(":/Items/attacked/ElecAttack.gif"), this);
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

bool Item::setonground(bool isonground)
{
    Item::isonground = isonground;
    return isonground;
}

void Item::setfall_v(QPointF fallv)
{
    fall_v=fallv;
}
