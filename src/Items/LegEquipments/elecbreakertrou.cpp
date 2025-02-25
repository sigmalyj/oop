#include "elecbreakertrou.h"

ElecBreakerTrou::ElecBreakerTrou(QGraphicsItem *parent) : LegEquipment(parent, ":/Items/LegEquipments/ElecBreakerTrou/ertong_76e67ae6753bcb1300232cfd8e6af0b0-3.png") {
    pro_elec=1;
    pro_flame=0;
    pro_ice=0;
    name="电裤";
}

