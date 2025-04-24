#include <QTransform>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include "Character.h"
#include"conf.h"
#include"../Sword/double_ice_metal.h"
#include"../Sword/long_elec_metal.h"
#include"../Sword/short_flame_wooden.h"
#include<QPointF>
Character::Character(QGraphicsItem *parent) : Item(parent, "")
{
}

void Character::visualize(QGraphicsScene *scene) {
    if (!scene) return;

    // 可视化中心点
    QPointF center = QPointF(pos().x() + boundingRect().width() / 2, pos().y() + boundingRect().height() / 2);
    QGraphicsEllipseItem *centerPoint = new QGraphicsEllipseItem(center.x() - 2, center.y() - 2, 4, 4);
    centerPoint->setBrush(Qt::red);
    scene->addItem(centerPoint);

    // 可视化边界矩形
    QGraphicsRectItem *boundingBox = new QGraphicsRectItem(boundingRect());
    boundingBox->setPen(QPen(Qt::blue));
    boundingBox->setPos(pos());
    scene->addItem(boundingBox);
}

bool Character::isLeftDown() const
{
    return leftDown;
}

void Character::setLeftDown(bool leftDown) {
    Character::leftDown = leftDown;
    face=false;
}

bool Character::isRightDown() const {
    return rightDown;
}

void Character::setRightDown(bool rightDown) {
    Character::rightDown = rightDown;
    face=true;
}

bool Character::isAttackDown() const
{
    return attackDown;
}

void Character::setAttackDown(bool attack)
{
    if(attack==true)
    {
        attackDown=true;
        attackstate=true;
    }
    else
    {
        attackDown=false;
    }

}

bool Character::isPickDown() const {
    return pickDown;
}

bool Character::isFace() const
{
    return face;
}

void Character::setface(bool newface)
{
    face=newface;
}

void Character::setPickDown(bool pickDown)   {
    Character::pickDown = pickDown;
}

bool Character::isJumpDown() const
{
    return jumpDown;
}

void Character::setJumpDown(bool jumpDown)
{
    Character::jumpDown= jumpDown;
}

bool Character::isCastDown() const
{
    return castDown;
}

void Character::setCastDown(bool castDown)
{
    Character::castDown=castDown;
}

bool Character::isLastPickDowm() const
{
    return lastPickDown;
}

void Character::setLastPickDown(bool lastpickdown)
{
    lastPickDown=lastpickdown;
}

bool Character::ischangeweaponDown() const
{
    return changeweapon;
}

void Character::setchangeweaponDown(bool changeweapondown)
{
    changeweapon=changeweapondown;
}

bool Character::ischangearrowDown() const
{
    return changearrow;
}

void Character::setchangearrowDown(bool changearrowdown)
{
    changearrow=changearrowdown;
}

bool Character::isonground() const
{
    return onground;
}
void Character::setonground(bool onground)
{
    Character::onground = onground;
}


const QPointF &Character::getVelocity() const {
    return velocity;
}

void Character::setPicking(bool Picking)
{
    picking=Picking;
}

void Character::setVelocity(const QPointF &velocity) {
    Character::velocity = velocity;
}

void Character::characterattack(Character *other)
{
    if(now_weapon==NULL)
    {
        return;
    }
    if(auto weapon=dynamic_cast<Sword*>(now_weapon))                                                //当前武器为箭
    {
        QPointF attack(pos().x()+boundingRect().width()/2,pos().y()+boundingRect().height()/2);
        QPointF attacked(other->pos().x()+other->boundingRect().width()/2,other->pos().y()+other->boundingRect().height()/2);
        auto distance=QLineF(attack,attacked).length();                                            //判断是否在攻击范围内
        if(auto swordweapon=dynamic_cast<Double_Ice_Metal*>(weapon))                                //武器为双手刀
        {
            if(distance<swordweapon->attackdistance)
            {
                int elec=(swordweapon->elec_value-other->protect_elec);
                int ice=(swordweapon->ice_value-other->protect_ice);
                int flame=(swordweapon->flame_value-other->protect_flame);                          //三种元素攻击伤害
                int sum=elec+ice+flame;
                if(other->ice_attacked)
                {
                    sum*=2;                                                                         //被冰冻时伤害翻倍

                }
                other->ice_attacked=true;
                other->iceItem->setVisible(true);
                other->lifevalue-=sum;                                                              //显示对应攻击效果，更新血量

            }

        }
        else
        {
            if((face==false&&pos().x()>other->pos().x())||(face==true&&pos().x()<other->pos().x())) //当前武器为单向剑
            {
                if(distance<weapon->attackdistance)                                                 //判断攻击距离
                {
                    int elec=(weapon->elec_value-other->protect_elec);
                    int ice=(weapon->ice_value-other->protect_ice);
                    int flame=(weapon->flame_value-other->protect_flame);

                    if(dynamic_cast<Long_Elec_Metal*>(now_weapon))                                  //判断元素属性以播放不同的攻击效果，确定是否被冰冻，如被冰冻则被攻击立即解除
                    {
                        other->elec_attacked=true;
                        other->elecItem->setVisible(true);
                    }
                    else
                    {
                        other->flame_attacked=true;
                        other->flameItem->setVisible(true);
                    }
                    int sum=elec+ice+flame;
                    if(other->ice_attacked)
                    {
                        sum*=2;
                        other->ice_attacked=false;
                        other->iceItem->setVisible(false);
                    }
                    other->lifevalue-=sum;
                }
            }
        }
        (void)dynamic_cast<Item*>(now_weapon);
        return;
    }

}

void Character::changeWeapon()
{
    if(sword!=NULL&&bow!=NULL)                                                   //切换武器，更新当前手持武器及其名称
    {
        if(now_weapon==sword)
        {
            now_weapon=bow;
            nameofnow_weapon=bow->name;
        }
        else if(now_weapon==bow)
        {
            now_weapon=sword;
            nameofnow_weapon=sword->name;
        }
    }
}

void Character::showstate()                                                      //显示人物状态，生命、防御、武器、箭头
{
    state->setPlainText("elec_free "+QString::number(protect_elec)+"     ice_free "+QString::number(protect_ice)+
    "     flame_free  "+QString::number(protect_flame)+"\t"+"手持 "+nameofnow_weapon+"\t"+
    "身穿 "+armor->name+headEquipment->name+legEquipment->name+" 箭头 "+nameofnow_arrow);
}

void Character::charactercast()                                                  //投掷近战武器、射箭及其伤害判定
{
    if(sword!=NULL)
    {
        sword->unmount();                                                       //卸下被投掷武器

        sword->setParentItem(parentItem());
        sword=NULL;
        now_weapon=bow;                                                         //将当前武器设为弓
        if(now_weapon==NULL)
        {
            nameofnow_weapon="N0";
        }
        else
        {
            nameofnow_weapon=bow->name;                                         //更改当前武器的名字
        }

    }
}

void Character::characterdropbow()
{
    if(bow!=NULL)
    {
        bow->unmount();

        bow->setParentItem(parentItem());
        bow=NULL;
        now_weapon=sword;
        if(now_weapon==NULL)
        {
            nameofnow_weapon="N0";
        }
        else
        {
            nameofnow_weapon=sword->name;
        }

    }
}

Sword *Character::getsword()
{
    return sword;
}

Bow *Character::getbow()
{
    return bow;
}

Armor *Character::pickupArmor(Armor *newArmor)
{
    auto oldArmor = armor;                                                                  //卸下当前装备
    if (oldArmor != nullptr) {
        oldArmor->unmount();
        oldArmor->setPos(newArmor->pos());                                                  //将旧装备放到新装备的位置
        oldArmor->setParentItem(parentItem());
    }
    newArmor->setParentItem(this);                                                          //装备新装备
    newArmor->mountToParent();
    armor = newArmor;
    protect_elec+=(newArmor->pro_elec-oldArmor->pro_elec);
    protect_flame+=(newArmor->pro_flame-oldArmor->pro_flame);
    protect_ice+=(newArmor->pro_ice-oldArmor->pro_ice);
    return oldArmor;
}

LegEquipment *Character::pickupLegArmor(LegEquipment *newArmor)
{
    auto oldArmor = legEquipment;
    if (oldArmor != nullptr)
    {
        oldArmor->unmount();
        oldArmor->setPos(newArmor->pos());
        oldArmor->setParentItem(parentItem());
    }
    newArmor->setParentItem(this);
    newArmor->mountToParent();
    legEquipment = newArmor;
    protect_elec+=(newArmor->pro_elec-oldArmor->pro_elec);
    protect_flame+=(newArmor->pro_flame-oldArmor->pro_flame);
    protect_ice+=(newArmor->pro_ice-oldArmor->pro_ice);
    return oldArmor;
}

HeadEquipment *Character::pickupHeadArmor(HeadEquipment *newArmor)
{
    auto oldArmor = headEquipment;
    if (oldArmor != nullptr) {
        oldArmor->unmount();
        oldArmor->setPos(newArmor->pos());
        oldArmor->setParentItem(parentItem());
    }
    newArmor->setParentItem(this);
    newArmor->mountToParent();
    headEquipment = newArmor;
    protect_elec+=(newArmor->pro_elec-oldArmor->pro_elec);
    protect_flame+=(newArmor->pro_flame-oldArmor->pro_flame);
    protect_ice+=(newArmor->pro_ice-oldArmor->pro_ice);
    return oldArmor;
}

Sword *Character::pickupSword(Sword *newSword)
{
    if(sword==NULL)
    {
        newSword->setParentItem(this);
        newSword->mountToParent();
        sword=newSword;
        now_weapon=sword;
        nameofnow_weapon=sword->name;
        return NULL;
    }
    else
    {
        auto oldsword=sword;
        oldsword->unmount();
        oldsword->setPos(newSword->pos());
        oldsword->setParentItem(parentItem());
        newSword->setParentItem(this);
        newSword->mountToParent();
        sword=newSword;
        now_weapon=sword;
        nameofnow_weapon=sword->name;
        return oldsword;
    }
}

Bow *Character::pickupBow(Bow *newBow)
{
    if(bow==NULL)
    {
        newBow->setParentItem(this);
        newBow->mountToParent();
        bow=newBow;
        now_weapon=bow;
        nameofnow_weapon=bow->name;
        return NULL;
    }
    else
    {
        auto oldbow=bow;
        oldbow->unmount();
        oldbow->setPos(newBow->pos());
        oldbow->setParentItem(parentItem());
        newBow->setParentItem(this);
        newBow->mountToParent();
        bow=newBow;
        now_weapon=bow;
        nameofnow_weapon=bow->name;
        return oldbow;
    }
}

void Character::pickupArrow(Arrow *newArrow)                                                    //将捡到的新箭头放入空的数组位置中,最多储存20根
{
    for(int i=0;i<20;i++)
    {
        if(repos[i]==NULL)
        {
            repos[i]=newArrow;

            repos[i]->setParentItem(this);
            repos[i]->mountToParent();
            repos[i]->setPos(10*i-80,-250);
            now_arrow=repos[i];
            nameofnow_arrow=repos[i]->name;
            break;
        }
    }
}

void Character::changenow_arrow()                                                           //切换所用箭头
{
    if(now_arrow!=NULL)
    {
        if(dynamic_cast<Elec_Arrow*>(now_arrow))                                            //当前为电属性箭头，则换位冰属性
        {
            (void)dynamic_cast<Arrow*>(now_arrow);
            for(int i=0;i<20;i++)
            {
                if(dynamic_cast<Ice_Arrow*>(repos[i]))
                {
                    (void)dynamic_cast<Arrow*>(repos[i]);
                    now_arrow=repos[i];
                    nameofnow_arrow=now_arrow->name;
                    break;
                }
            }
            for(int i=0;i<20;i++)                                                           //没有冰属性则换为火属性，都没有则不切换
            {
                if(dynamic_cast<Flame_Arrow*>(repos[i]))
                {
                    (void)dynamic_cast<Arrow*>(repos[i]);
                    now_arrow=repos[i];
                    nameofnow_arrow=now_arrow->name;
                    break;
                }
            }

        }
        else if(dynamic_cast<Ice_Arrow*>(now_arrow))
        {
            (void)dynamic_cast<Arrow*>(now_arrow);
            for(int i=0;i<20;i++)
            {
                if(dynamic_cast<Flame_Arrow*>(repos[i]))
                {
                    (void)dynamic_cast<Arrow*>(repos[i]);
                    now_arrow=repos[i];
                    nameofnow_arrow=now_arrow->name;
                    break;
                }
            }

            for(int i=0;i<20;i++)
            {
                if(dynamic_cast<Elec_Arrow*>(repos[i]))
                {
                    (void)dynamic_cast<Arrow*>(repos[i]);
                    now_arrow=repos[i];
                    nameofnow_arrow=now_arrow->name;
                    break;
                }
            }
        }
        else if(dynamic_cast<Flame_Arrow*>(now_arrow))
        {
            (void)dynamic_cast<Arrow*>(now_arrow);
            for(int i=0;i<20;i++)
            {
                if(dynamic_cast<Elec_Arrow*>(repos[i]))
                {
                    (void)dynamic_cast<Arrow*>(repos[i]);
                    now_arrow=repos[i];
                    nameofnow_arrow=now_arrow->name;
                    break;
                }
            }
            for(int i=0;i<20;i++)
            {
                if(dynamic_cast<Ice_Arrow*>(repos[i]))
                {
                    (void)dynamic_cast<Arrow*>(repos[i]);
                    now_arrow=repos[i];
                    nameofnow_arrow=now_arrow->name;
                    break;
                }
            }
        }
    }
}

void Character::shootarrow()                                                                //将已射出箭从自身数组中除去
{
    if(now_arrow!=NULL)
    {

        for(int i=0;i<20;i++)
        {
            if(repos[i]==now_arrow)
            {

                repos[i]->unmount();
                repos[i]->setParentItem(parentItem());
                repos[i]=NULL;
                break;
            }
        }
        now_arrow=NULL;                                                                     //将当前箭头设置为非空的第一根箭
        for(int i=0;i<20;i++)
        {
            if(repos[i]!=NULL)
            {
                now_arrow=repos[i];
                nameofnow_arrow=now_arrow->name;
                break;
            }

        }

    }
}

bool Character::isattack()
{
    return attackstate;
}

void Character::setattackstate(bool state)
{
    attackstate=state;
}

Arrow* Character::getshootedarrow()
{
    if(now_arrow!=NULL)
    {
        return now_arrow;
    }
    return NULL;
}

