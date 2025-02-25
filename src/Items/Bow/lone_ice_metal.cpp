#include "lone_ice_metal.h"

Lone_Ice_Metal::Lone_Ice_Metal(QGraphicsItem *parent) : Bow(parent,
            ":/Items/weapon/bow/Lone_Ice_Metal/0G5013b243_2.gif")
{
    elec_value=3;
    flame_value=3;
    ice_value=7;
    attackdistance=900;
    material="Metal";
    element="ice";
    arrownum=1;
    name="远程寒冰铁弓";
}
