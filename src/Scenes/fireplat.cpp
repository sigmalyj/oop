#include "fireplat.h"

FirePlat::FirePlat(QGraphicsItem *parent):PlatForm(parent,":/Items/plat/FirePlat.png")
{
    flameItem->setPos(60,-60);
}
