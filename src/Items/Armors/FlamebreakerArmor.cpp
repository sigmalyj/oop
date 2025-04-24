#include "FlamebreakerArmor.h"

FlamebreakerArmor::FlamebreakerArmor(QGraphicsItem *parent) : Armor(parent,
                                                                    ":/Items/Armors/FlamebreakerArmor/FlameArmor.png") {
    pro_elec=0;
    pro_flame=1;
    pro_ice=0;
    name="火铠";
}

