#include "elecbreakerhead.h"

ElecBreakerHead::ElecBreakerHead(QGraphicsItem *parent) :HeadEquipment(parent,
                    ":/Items/HeadEquipments/ElecBreakerHead/ElecHelmet.png")
{
    pro_elec=1;
    pro_flame=0;
    pro_ice=0;
    name="电盔";
}
