#include "elecbreakerarmor.h"

ElecBreakerArmor::ElecBreakerArmor(QGraphicsItem *parent) : Armor(parent,
            ":/Items/Armors/ElecbreakerArmor/ElecArmor.gif") {
    pro_elec=1;
    pro_flame=0;
    pro_ice=0;
    name="电铠";
}
