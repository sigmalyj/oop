#include "flame_arrow.h"


Flame_Arrow::Flame_Arrow(QGraphicsItem *parent): Arrow(parent,
            ":/Items/Arrow/FlameArrow.gif")
{
    flydistance=700;
    elec_value=0;
    flame_value=3;
    ice_value=0;
    element="Flame";
    name="火箭";
}
