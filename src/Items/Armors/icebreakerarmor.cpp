#include "icebreakerarmor.h"

IceBreakerArmor::IceBreakerArmor(QGraphicsItem *parent) : Armor(parent,
            ":/Items/Armors/IcebreakerArmor/IceArmor.png") {
    pro_elec=0;
    pro_flame=0;
    pro_ice=1;
    name="冰铠";
}
