#include "elec_arrow.h"

Elec_Arrow::Elec_Arrow(QGraphicsItem *parent): Arrow(parent,
            ":/Items/Arrow/251KH339A.png")
{
    flydistance=700;
    elec_value=3;
    flame_value=0;
    ice_value=0;
    element="Elec";
    name="电箭";
}
