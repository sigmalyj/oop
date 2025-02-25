#include "middle_elec_metal.h"


Middle_Elec_Metal::Middle_Elec_Metal(QGraphicsItem *parent) : Bow(parent,
          ":/Items/weapon/bow/Middle_Elec_Metal/26162F311N_2.gif")
{
    attackdistance=650;
    elec_value=7;
    flame_value=3;
    ice_value=3;
    material="Metal";
    element="Elec";
    name="中程雷电铁弓";
    arrownum=2;
}
