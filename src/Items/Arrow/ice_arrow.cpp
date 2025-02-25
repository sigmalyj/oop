#include "ice_arrow.h"

Ice_Arrow::Ice_Arrow(QGraphicsItem *parent): Arrow(parent,
            ":/Items/Arrow/ice.gif")
{
    flydistance=700;
    elec_value=0;
    flame_value=0;
    ice_value=3;
    element="Ice";
    name="冰箭";
}
