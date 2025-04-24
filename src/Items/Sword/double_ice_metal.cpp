#include "double_ice_metal.h"

Double_Ice_Metal::Double_Ice_Metal(QGraphicsItem *parent): Sword(parent,
            ":/Items/weapon/sword/Double_Ice_Metal/IceSword.png")
{
    attackdistance=100;
    elec_value=3;
    flame_value=3;
    ice_value=7;
    material="Metal";
    element="Ice";
    name="双手寒冰铁剑";
}
