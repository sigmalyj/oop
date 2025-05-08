#include "icebreakerhead.h"

IceBreakerHead::IceBreakerHead(QGraphicsItem *parent) :HeadEquipment(parent,
                    ":/Items/HeadEquipments/IceBreakerHead/IceHelmet.png")
{
    pro_elec=0;
    pro_flame=0;
    pro_ice=0;
    name="冰盔";
}
