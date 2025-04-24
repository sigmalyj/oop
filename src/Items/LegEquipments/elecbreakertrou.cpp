#include "elecbreakertrou.h"

ElecBreakerTrou::ElecBreakerTrou(QGraphicsItem *parent) : LegEquipment(parent, ":/Items/LegEquipments/ElecBreakerTrou/ElecPants.png") {
    pro_elec=1;
    pro_flame=0;
    pro_ice=0;
    name="电裤";
}

