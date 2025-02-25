#include <memory>
#include "Link.h"
#include "../HeadEquipments/CapOfTheHero.h"
#include "../Armors/OldShirt.h"
#include "../LegEquipments/WellWornTrousers.h"

Link::Link(QGraphicsItem *parent) : Character(parent)
{
    headEquipment = new CapOfTheHero(this);                                 //初始化人物防具、血条、状态栏、箭头存储数组
    legEquipment = new WellWornTrousers(this);
    armor = new OldShirt(this);
    bloodbar=NULL;
    state=NULL;
    for(int i=0;i<20;i++)
    {
        repos[i]=NULL;
    }

    headEquipment->mountToParent();
    legEquipment->mountToParent();
    armor->mountToParent();
}
