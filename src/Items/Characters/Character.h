#ifndef QT_PROGRAMMING_2024_CHARACTER_H
#define QT_PROGRAMMING_2024_CHARACTER_H


#include "../HeadEquipments/HeadEquipment.h"
#include "../Armors/Armor.h"
#include "../LegEquipments/LegEquipment.h"
#include"../Bow/bow.h"
#include"../Sword/sword.h"
#include <QGraphicsEllipseItem>
#include<QProgressBar>
#include"../Arrow/arrow.h"
#include"../Arrow/elec_arrow.h"
#include"../Arrow/flame_arrow.h"
#include"../Arrow/ice_arrow.h"
#include <QGraphicsScene>

class Character : public Item
{
public:
    explicit Character(QGraphicsItem *parent);

    [[nodiscard]] bool isLeftDown() const;

    void setLeftDown(bool leftDown);

    [[nodiscard]] bool isRightDown() const;

    void setRightDown(bool rightDown);

    [[nodiscard]] bool isAttackDown() const;                        //摁下攻击键 空格键

    void setAttackDown(bool attack);

    [[nodiscard]] bool isPickDown() const;

    [[nodiscard]] bool isFace() const;                              //设置角色朝向

    void setface(bool newface);

    void setPickDown(bool pickDown);

    [[nodiscard]] bool isJumpDown() const;

    void setJumpDown(bool jumpDown);                                //摁下跳跃K

    [[nodiscard]] bool isCastDown() const;                          //摁下投掷按键E

    void setCastDown(bool castDown);

    [[nodiscard]] bool isLastPickDowm()const;

    void setLastPickDown(bool lastpickdown);

    [[nodiscard]] bool ischangeweaponDown()const;                   //摁下换武器按键Q

    void setchangeweaponDown(bool changeweapondown);

    bool ischangearrowDown()const;                                  //摁下切换箭头键

    void setchangearrowDown(bool changearrowdown);

    bool isonground() const;                                     //是否在地面上
    void setonground(bool onground);                               //设置是否在地面上



    [[nodiscard]] const QPointF &getVelocity() const;

    [[nodiscard]] bool isPicking() const
    {
        return picking;
    }
    void setPicking (bool Picking);

    void setVelocity(const QPointF &velocity);

    void processInput();

    void characterattack(Character *other);                         //攻击对方的函数

    void changeWeapon();                                            //切换武器

    void showstate();                                               //展示当前状态，防御值，使用武器、箭头类型

    void charactercast();                                           //投掷近战武器

    void characterdropbow();                                        //触电掉落弓

    Sword* getsword();

    Bow* getbow();

    Armor* pickupArmor(Armor* newArmor);                            //捡起防具

    LegEquipment *pickupLegArmor(LegEquipment *newArmor);

    HeadEquipment*pickupHeadArmor(HeadEquipment *newArmor);

    Sword* pickupSword(Sword* newSword);

    Bow *pickupBow(Bow* newBow);

    void pickupArrow(Arrow*newArrow);

    void changenow_arrow();                                         //换箭头

    Arrow* getshootedarrow();                                       //得到对象（发生的箭）

    void shootarrow();

    bool isattack();

    void setattackstate(bool state);                                //攻击状态（是否正在攻击），用以设置攻击间隔

    void visualize(QGraphicsScene *scene);                          // 添加可视化方法

    void beAttacked();                                               //被攻击，设置受击状态
    void notBeAttacked();                                           //取消受击状态

    QGraphicsRectItem* GetBoundingBox(QPointF &point);       //获取角色的边界矩形

    Item *now_weapon{};                     //当前所使用武器
    Sword* sword{};                         //所拥有的近战武器
    Bow* bow{};
    QProgressBar * bloodbar;                //血条
    QGraphicsTextItem *state;               //状态文本框
    int lifevalue=200;                      //生命值
    int protect_flame=0;                    //各属性护甲值
    int protect_elec=0;
    int protect_ice=0;
    Character *opponent{};
    bool isAttacked=false;
protected:

    HeadEquipment *headEquipment{};         //防具
    LegEquipment *legEquipment{};
    Armor *armor{};
    QPointF velocity{};
    QPointF acceleration{};
    Arrow *now_arrow{};                     //当前使用箭头
    Arrow * repos[20];
    int attackvalue=0;
    QString nameofnow_weapon="No";          //当前所使用箭头、武器的名称
    QString nameofnow_arrow="No";
                    //对方角色


private:
    bool leftDown{}, rightDown{}, pickDown{};
    bool lastPickDown{};                    //按键状态
    bool picking{};
    bool jumpDown{};
    bool attackDown{};
    bool changeweapon{};
    bool face{};
    bool castDown{};
    bool changearrow{};
    bool attackstate{};
    bool onground=true;

};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
