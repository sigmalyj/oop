#include "short_flame_wooden.h"

Short_Flame_Wooden::Short_Flame_Wooden(QGraphicsItem *parent): Sword(parent,
            ":/Items/weapon/sword/Short_Flame_Wooden/FlameSword.gif")
{
    attackdistance=90;
    elec_value=3;
    flame_value=6;
    ice_value=3;
    material="Wooden";
    element="Flame";
    name="避火木制短剑";
}
