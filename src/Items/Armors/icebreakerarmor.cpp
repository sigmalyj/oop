#include "icebreakerarmor.h"

IceBreakerArmor::IceBreakerArmor(QGraphicsItem *parent) : Armor(parent,
            ":/Items/Armors/IcebreakerArmor/IceArmor.gif") {
    pro_elec=0;
    pro_flame=0;
    pro_ice=1;
    name="冰铠";
}
