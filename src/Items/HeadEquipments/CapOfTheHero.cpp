#include "CapOfTheHero.h"

CapOfTheHero::CapOfTheHero(QGraphicsItem *parent) : HeadEquipment(parent,
                                                                  ":/Items/HeadEquipments/CapOfTheHero/DefaultHelmet.png")
{
    pro_elec=0;
    pro_flame=0;
    pro_ice=0;
    name="素盔";
}
