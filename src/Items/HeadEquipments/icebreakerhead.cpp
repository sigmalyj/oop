#include "icebreakerhead.h"

IceBreakerHead::IceBreakerHead(QGraphicsItem *parent) :HeadEquipment(parent,
                    ":/Items/HeadEquipments/IceBreakerHead/0310101I5S.gif")
{
    pro_elec=0;
    pro_flame=0;
    pro_ice=0;
    name="冰盔";
}
