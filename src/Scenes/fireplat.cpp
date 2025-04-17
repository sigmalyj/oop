#include "fireplat.h"

FirePlat::FirePlat(QGraphicsItem *parent):PlatForm(parent,":/Items/plat/fire.png")
{
    flameItem->setPos(60,-60);
}
