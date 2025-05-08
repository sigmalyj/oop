#include "short_flame_wooden_bow.h"

Short_Flame_Wooden_Bow::Short_Flame_Wooden_Bow(QGraphicsItem *parent) : Bow(parent,
          ":/Items/weapon/bow/Short_Flame_Wooden/FlameBow.gif")
{
    attackdistance=400;
    elec_value=3;
    flame_value=6;
    ice_value=3;
    arrownum=1;
    material="Wooden";
    element="Flame";
    name="近程避火木弓";
}
