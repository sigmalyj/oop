#include "fireplat.h"

FirePlat::FirePlat(QGraphicsItem *parent):PlatForm(parent,":/Items/plat/WoodPlat.jpg")
{
    flameItem->setPos(60,-60);
}
