#include "fireplat.h"

FirePlat::FirePlat(QGraphicsItem *parent):PlatForm(parent,":/Items/plat/木.png")
{
    flameItem->setPos(60,-60);
}
