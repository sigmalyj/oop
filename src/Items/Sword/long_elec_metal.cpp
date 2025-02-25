#include "long_elec_metal.h"

Long_Elec_Metal::Long_Elec_Metal(QGraphicsItem *parent): Sword(parent,
            ":/Items/weapon/sword/Long_Elec_Metal/elecsword.gif")
{
    attackdistance=170;
    elec_value=7;
    flame_value=3;
    ice_value=3;
    material ="Metal";
    element="Elec";
    name="雷电合金长剑";
}
