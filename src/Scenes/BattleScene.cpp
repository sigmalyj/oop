#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Maps/Battlefield.h"
#include "../Items/Armors/FlamebreakerArmor.h"
#include"../Items/Armors/icebreakerarmor.h"
#include"../Items/Armors/elecbreakerarmor.h"
#include"../Items/HeadEquipments/flamebreakerhead.h"
#include"../Items/HeadEquipments/elecbreakerhead.h"
#include"../Items/HeadEquipments/icebreakerhead.h"
#include"../Items/LegEquipments/elecbreakertrou.h"
#include"../Items/LegEquipments/flamebreakertrou.h"
#include"../Items/LegEquipments/icebreakertrou.h"
#include"iceplat.h"
#include"fireplat.h"
#include"rockplat.h"
#include"../Items/Sword/double_ice_metal.h"
#include"../Items/Sword/short_flame_wooden.h"
#include"../Items/Sword/long_elec_metal.h"
#include"../Items/Bow/short_flame_wooden_bow.h"
#include"../Items/Bow/middle_elec_metal.h"
#include"../Items/Bow/lone_ice_metal.h"
#include"../Items/Arrow/elec_arrow.h"
#include"../Items/Arrow/flame_arrow.h"
#include"../Items/Arrow/ice_arrow.h"
#include<ctime>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QProgressBar>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include<QMessageBox>
#include <QApplication>
BattleScene::BattleScene(QObject *parent) : Scene(parent)
{

    setSceneRect(0, 0, 1280, 720);                                      //添加地图、人物、平台
    srand((unsigned int)time(NULL));                                    //添加随机数种子
    map = new Battlefield();
    character = new Link();
    character_2 = new Link();
    character->opponent = character_2;
    character_2->opponent = character;
    characters[0] = character;
    characters[1] = character_2;
    iceplat = new IcePlat();
    iceplat->setPos(270, 300);
    fireplat = new FirePlat();
    fireplat->setPos(1000, 320);
    rockplat = new RockPlat();
    rockplat->setPos(560, 150);

    platforms[0] = iceplat;
    platforms[1] = fireplat;
    platforms[2] = rockplat;

    addItem(map);
    addItem(character);
    addItem(character_2);
    addItem(iceplat);
    addItem(fireplat);
    addItem(rockplat);
    map->scaleToFitScene(this);
    character->setPos(map->getSpawnPos());
    character_2->setPos(map->getSpawnPos().x() + 100, map->getSpawnPos().y());

    // 调用可视化方法
    character->visualize(this);
    character_2->visualize(this);

    QProgressBar *progressBar = new QProgressBar();                                     //添加血条
    progressBar->setRange(0, 200);
    progressBar->setValue(200);                                                         // 设置进度条的值
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    proxy->setWidget(progressBar);
    addItem(proxy);
    proxy->setPos(10, 10);

    QProgressBar *progressBar_2 = new QProgressBar();
    progressBar_2->setRange(0, 200);
    progressBar_2->setValue(200);
    QGraphicsProxyWidget *proxy_2 = new QGraphicsProxyWidget();
    proxy_2->setWidget(progressBar_2);
    addItem(proxy_2);
    proxy_2->setPos(10, 40);

    character->bloodbar = progressBar;                                                    //人物存一个指向血条的指针，用新添加的血条初始化人物血条
    character_2->bloodbar = progressBar_2;

    lineEdit = new CheatLine();                                                         //作弊框
    lineEdit->setPlaceholderText("作弊框");                                              // 设置占位符文本
    lineEdit->setAlignment(Qt::AlignCenter);                                            // 设置对齐方式

    QGraphicsProxyWidget *proxy_3 = new QGraphicsProxyWidget();                         //添加作弊框
    proxy_3->setWidget(lineEdit);
    addItem(proxy_3);
    proxy_3->setPos(1050, 10);
    connect(lineEdit, &QLineEdit::returnPressed, this, &BattleScene::handleCheatLine);
    QGraphicsTextItem *textItem = new QGraphicsTextItem("状态栏");

    textItem->setPos(300, 10);                                                          // 设置文本项的位置
    textItem->setDefaultTextColor(Qt::white);
    QFont font("Arial", 13);
    textItem->setFont(font);
    addItem(textItem);

    QGraphicsTextItem *textItem_2 = new QGraphicsTextItem("状态栏");
    textItem_2->setPos(300, 40);
    textItem_2->setDefaultTextColor(Qt::white);
    textItem_2->setFont(font);
    addItem(textItem_2);

    character->state = textItem;                                                          //人物存一个指向作弊框的指针
    character_2->state = textItem_2;

}



void BattleScene::processInput()                                                        //人物被冰冻时不能接受输入
{
    if (!character->ice_attacked)
    {
        HeroInPut(character);
    }
    if (!character_2->ice_attacked)
    {
        HeroInPut(character_2);
    }

    // if(!character->ice_attacked)
    // {
    //     processPlayerInput(character);
    // }
    // if(!character_2->ice_attacked)
    // {
    //     processPlayerInput(character_2);
    // }

}

void BattleScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        if (character != nullptr) {
            character->setLeftDown(true);
        }
        break;
    case Qt::Key_D:
        if (character != nullptr) {
            character->setRightDown(true);
        }
        break;
    case Qt::Key_J:
        if (character != nullptr) {
            character->setPickDown(true);
        }
        break;
    case Qt::Key_K:
        if (character != nullptr)
        {
            character->setJumpDown(true);
        }break;
    case Qt::Key_Space:
        if (character != nullptr)
        {
            character->setAttackDown(true);
        }break;
    case Qt::Key_Q:
        if (character != nullptr)
        {
            character->setchangeweaponDown(true);
        }break;
    case Qt::Key_E:
        if (character != nullptr)
        {
            character->setCastDown(true);
        }break;
    case Qt::Key_R:
        if (character != nullptr)
        {
            character->setchangearrowDown(true);
        }break;

    case Qt::Key_Left:
        if (character_2 != nullptr) {
            character_2->setLeftDown(true);
        }
        break;
    case Qt::Key_Right:
        if (character_2 != nullptr) {
            character_2->setRightDown(true);
        }
        break;
    case Qt::Key_Down:
        if (character_2 != nullptr) {
            character_2->setPickDown(true);
        }
        break;
    case Qt::Key_Up:
        if (character_2 != nullptr)
        {
            character_2->setJumpDown(true);
        }break;
    case Qt::Key_N:
        if (character_2 != nullptr)
        {
            character_2->setAttackDown(true);
        }break;
    case Qt::Key_M:
        if (character_2 != NULL)
        {
            character_2->setchangeweaponDown(true);
        }
        break;
    case Qt::Key_B:
        if (character_2 != NULL)
        {
            character_2->setCastDown(true);
        }
        break;
    case Qt::Key_V:
        if (character_2 != NULL)
        {
            character_2->setchangearrowDown(true);
        }
        break;
    default:
        Scene::keyPressEvent(event);
    }
}

void BattleScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        if (character != nullptr) {
            character->setLeftDown(false);
        }
        break;
    case Qt::Key_D:
        if (character != nullptr) {
            character->setRightDown(false);
        }
        break;
    case Qt::Key_J:
        if (character != nullptr) {
            character->setPickDown(false);
        }
        break;
    case Qt::Key_K:
        if (character != nullptr)
        {
            character->setJumpDown(false);
        }
        break;
    case Qt::Key_Space:
        if (character != nullptr)
        {
            character->setAttackDown(false);
        }break;
    case Qt::Key_Q:
        if (character != nullptr)
        {
            character->setchangeweaponDown(false);
        }break;
    case Qt::Key_E:
        if (character != NULL)
        {
            character->setCastDown(false);
        }
        break;
    case Qt::Key_R:
        if (character != NULL)
        {
            character->setchangearrowDown(false);
        }
        break;
    case Qt::Key_Left:
        if (character_2 != nullptr) {
            character_2->setLeftDown(false);
        }
        break;
    case Qt::Key_Right:
        if (character_2 != nullptr) {
            character_2->setRightDown(false);
        }
        break;
    case Qt::Key_Down:
        if (character_2 != nullptr) {
            character_2->setPickDown(false);
        }
        break;
    case Qt::Key_Up:
        if (character_2 != nullptr)
        {
            character_2->setJumpDown(false);
        }break;
    case Qt::Key_N:
        if (character_2 != nullptr)
        {
            character_2->setAttackDown(false);
        }break;
    case Qt::Key_M:
        if (character_2 != NULL)
        {
            character_2->setchangeweaponDown(false);
        }
        break;
    case Qt::Key_B:
        if (character_2 != NULL)
        {
            character_2->setCastDown(false);
        }
        break;
    case Qt::Key_V:
        if (character_2 != NULL)
        {
            character_2->setchangearrowDown(false);
        }
        break;
    default:
        Scene::keyReleaseEvent(event);
    }
}

void BattleScene::update()                                              //主循环
{
    Scene::update();
}

void BattleScene::processMovement()                                     //更新所有物品位置信息
{
    Scene::processMovement();
    if (character != nullptr) {
        character->setPos(character->pos() + character->getVelocity() * (double)deltaTime);
    }
    if (character_2 != nullptr) {
        character_2->setPos(character_2->pos() + character_2->getVelocity() * (double)deltaTime);
    }
    for (Item *item : total_random_fallthing)                                      //掉落物
    {
        item->setPos(item->pos() + item->fall_v * deltaTime);
    }

    for (Item *item : totalcasting)                                        //投掷物
    {
        item->setPos(item->pos() + item->fall_v * deltaTime);
    }
    for (Item *item : totalcasting_2)
    {
        item->setPos(item->pos() + item->fall_v * deltaTime);
    }
    for (Arrow *item : totalshooted)                                       //射出的弓箭
    {
        item->setPos(item->pos() + item->fall_v * deltaTime);
    }
    for (Arrow *item : totalshooted_2)
    {
        item->setPos(item->pos() + item->fall_v * deltaTime);
    }
}

void BattleScene::processPicking()
{
    Scene::processPicking();

    for (Character *chara : characters)
    {
        if (chara->isPicking())
        {
            auto mountable = findNearestUnmountedMountable(chara->pos(), 100);
            if (mountable != nullptr)
            {
                if (auto newArrow = dynamic_cast<Arrow *>(mountable)) // 捡起箭头
                {
                    chara->pickupArrow(newArrow);
                }
                else // 捡起其他装备
                {
                    mountable = pickupMountable(chara, mountable);
                }
            }
        }
    }
}
// test wty
void BattleScene::HeroInPut(Character *character)                        //人物移动与拾取
{
    Scene::processInput();

    QRectF iceRec = iceplat->sceneBoundingRect();
    QRectF fireRec = fireplat->sceneBoundingRect();
    QRectF rockRec = rockplat->sceneBoundingRect();
    int x = character->pos().x();
    int y = character->pos().y();
    int h = character->boundingRect().height();

    if (character != nullptr)
    {
        auto v = QPointF(0, 0);
        v.setY(character->getVelocity().y());
        if (character->isLeftDown())
        {

            v.setX(-0.3);
            character->setTransform(QTransform().scale(1, 1));

        }
        if (character->isRightDown())
        {
            v.setX(0.3);
            character->setTransform(QTransform().scale(-1, 1));
        }
        if (character->isJumpDown())                                                             //跳跃时检测在地面还是在某个平台
        {
            if ((v.y() == 0) && (character->pos().y() - map->getFloorHeight()) < 20 && character->isonground())
            {
                v.setY(-0.8);

            }
            else if ((v.y() == 0) && (y - iceRec.top()) < 20 && (x > iceRec.left()) && (x < iceRec.right()))
            {
                v.setY(-0.8);
            }
            else if (fireplat->pos().x() != -1000)                                                 //木制平台未被燃烧至消失时
            {
                if ((v.y() == 0) && (y - fireRec.top()) < 20 && (x > fireRec.left()) && (x < fireRec.right()))
                {
                    v.setY(-0.8);
                }
            }
            if ((v.y() == 0) && (y - rockRec.top()) < 20 && (x > rockRec.left()) && (x < rockRec.right()))
            {
                v.setY(-0.8);
            }
        }
        if (character->getVelocity().y() != 0)                                                     //人物在空中就会受到重力加速度
        {
            v.setY(v.y() + 0.02);
            if (character->pos().y() > map->getFloorHeight())
            {
                v.setY(0);
            }
        }
        for (PlatForm *platform : platforms)
        {
            QRectF platRec = platform->sceneBoundingRect();
            if (platform->exists())
            {
                if (x > (platRec.left() - 5) && x < (platRec.right() + 5))
                {

                    if (y > (platRec.bottom() - h) && y < (platRec.bottom() + 200))
                    {


                        if (character->isLeftDown() && x > platRec.right())
                        {
                            v.setX(0);
                        }
                        if (character->isRightDown() && x < platRec.left())
                        {
                            v.setX(0);
                        }
                    }
                    else
                    {
                        if (v.y() > 0 && abs(y - platRec.top()) < 5)
                        {
                            v.setY(0);
                        }
                    }
                }
                else
                {
                    if ((abs(y - platRec.top()) < 5 && v.y() == 0))
                    {
                        v.setY(0.02);
                    }
                }
            }
            else
            {
                if (character->pos().x() > 1000)

                {
                    if (v.y() == 0 && y < map->getFloorHeight())
                    {
                        v.setY(v.y() + 0.001);
                    }
                    if (v.y() > 0 && y > map->getFloorHeight() - 5)
                    {
                        v.setY(0);
                    }
                }
            }


        }

        if (x < 0 && character->isLeftDown())                                                                    //控制人物不能离开左右边界
        {
            character->setPos(0, character->pos().y());
        }
        if (x > 1280 - character->sceneBoundingRect().width())
        {
            character->setPos(1280 - character->sceneBoundingRect().width(), character->pos().y());
        }
        character->setVelocity(v);
        if (!character->isLastPickDowm() && character->isPickDown())                                         //拾取
        { // first time pickDown
            character->setPicking(true);
        }
        else
        {
            character->setPicking(false);
        }
        bool is = character->isPickDown();
        character->setLastPickDown(is);

    }
}

void BattleScene::fall()                                                 //掉落间隔
{
    static int interval = 0;
    interval++;
    if (interval < 270)
    {
        return;
    }

    int num = rand() % (18);                                               //掉落，随机位置，随机物品
    int x = rand() % (1270);
    interval = 0;
    fallthing(x, num);
}

void BattleScene::handlefallthing()                                      //更新掉落物速度
{
    for (Item *item : total_random_fallthing)
    {
        if (totalshooted.contains(item) || totalshooted_2.contains(item))
        {
            continue;
        }
        gravity(item);

    }
}

void BattleScene::deletefallthing()                                      //生成的掉落物品每隔一段时间消失
{
    static int num = 0;
    QPoint p(200, 200);
    num++;
    if (num < 500)
    {
        return;
    }

    for (auto it = total_random_fallthing.begin(); it != total_random_fallthing.end(); ++it)
    {
        Item *item = *it;
        if (item->pos().x() != -200 && item->pos().y() != -200)
        {
            if (item->parentItem() != character && item->parentItem() != character_2)
            {
                item->setPos(p);
                total_random_fallthing.erase(it);                // 移除对象
                removeItem(item);
                num = 0;
                break;
            }
        }
    }
}

void BattleScene::fallthing(int x, int num)                               //生成掉落物
{
    switch (num)
    {
    case 1:
    {   Armor *elecbreakerarmor = new ElecBreakerArmor();
        elecbreakerarmor->setPos(x, 0);
        elecbreakerarmor->setScale(0.2);
        elecbreakerarmor->unmount();
        elecbreakerarmor->fall_v.setY(0);
        elecbreakerarmor->fall_v.setX(0);
        addItem(elecbreakerarmor);
        total_random_fallthing.push_back(elecbreakerarmor);
        break;
    }
    case 2:
    {
        Armor *flamebreakerarmor = new FlamebreakerArmor();
        flamebreakerarmor->setPos(x, 0);
        flamebreakerarmor->setScale(0.4);
        flamebreakerarmor->unmount();
        flamebreakerarmor->fall_v.setX(0);
        flamebreakerarmor->fall_v.setY(0);
        addItem(flamebreakerarmor);
        total_random_fallthing.push_back(flamebreakerarmor);
        break;
    }
    case 3:
    {
        Armor *icebreakerarmor = new IceBreakerArmor();
        icebreakerarmor->setPos(x, 0);
        icebreakerarmor->setScale(0.4);
        icebreakerarmor->unmount();
        icebreakerarmor->fall_v.setX(0);
        icebreakerarmor->fall_v.setY(0);
        addItem(icebreakerarmor);
        total_random_fallthing.push_back(icebreakerarmor);
        break;
    }
    case 4:
    {
        HeadEquipment *flamebreakerhead = new FlameBreakerHead();
        flamebreakerhead->setPos(x, 0);
        flamebreakerhead->setScale(0.4);
        flamebreakerhead->unmount();
        flamebreakerhead->fall_v.setX(0);
        flamebreakerhead->fall_v.setY(0);
        addItem(flamebreakerhead);
        total_random_fallthing.push_back(flamebreakerhead);
        break;
    }
    case 5:
    {
        HeadEquipment *elecbreakerhead = new ElecBreakerHead();
        elecbreakerhead->setPos(x, 0);
        elecbreakerhead->setScale(0.3);
        elecbreakerhead->unmount();
        elecbreakerhead->fall_v.setX(0);
        elecbreakerhead->fall_v.setY(0);
        addItem(elecbreakerhead);
        total_random_fallthing.push_back(elecbreakerhead);
        break;
    }
    case 6:
    {
        HeadEquipment *icebreakerhead = new IceBreakerHead();
        icebreakerhead->setPos(x, 0);
        icebreakerhead->setScale(0.3);
        icebreakerhead->unmount();
        icebreakerhead->fall_v.setX(0);
        icebreakerhead->fall_v.setY(0);
        addItem(icebreakerhead);
        total_random_fallthing.push_back(icebreakerhead);
        break;
    }
    case 7:
    {
        LegEquipment *flamebreaketrou = new FlameBreakerTrou();
        flamebreaketrou->setPos(x, 0);
        flamebreaketrou->setScale(0.4);
        flamebreaketrou->unmount();
        flamebreaketrou->fall_v.setX(0);
        flamebreaketrou->fall_v.setY(0);
        addItem(flamebreaketrou);
        total_random_fallthing.push_back(flamebreaketrou);
        break;
    }
    case 8:
    {
        LegEquipment *icebreaketrou = new IceBreakerTrou();
        icebreaketrou->setPos(x, 0);
        icebreaketrou->setScale(0.4);
        icebreaketrou->unmount();
        icebreaketrou->fall_v.setX(0);
        icebreaketrou->fall_v.setY(0);
        addItem(icebreaketrou);
        total_random_fallthing.push_back(icebreaketrou);
        break;
    }
    case 9:
    {
        LegEquipment *elecbreaketrou = new ElecBreakerTrou();
        elecbreaketrou->setPos(x, 0);
        elecbreaketrou->setScale(0.4);
        elecbreaketrou->unmount();
        elecbreaketrou->fall_v.setX(0);
        elecbreaketrou->fall_v.setY(0);
        addItem(elecbreaketrou);
        total_random_fallthing.push_back(elecbreaketrou);
        break;
    }
    case 10:
    {
        Sword *doubleicemetal = new Double_Ice_Metal();
        doubleicemetal->setPos(x, 0);
        doubleicemetal->setScale(0.4);
        doubleicemetal->unmount();
        doubleicemetal->fall_v.setX(0);
        doubleicemetal->fall_v.setY(0);
        addItem(doubleicemetal);
        total_random_fallthing.push_back(doubleicemetal);
        break;
    }
    case 11:
    {
        Sword *longelecmetal = new Long_Elec_Metal();
        longelecmetal->setPos(x, 0);
        longelecmetal->setScale(0.4);
        longelecmetal->unmount();
        longelecmetal->fall_v.setX(0);
        longelecmetal->fall_v.setY(0);
        addItem(longelecmetal);
        total_random_fallthing.push_back(longelecmetal);
        break;
    }
    case 12:
    {
        Sword *shortflamewooden = new Short_Flame_Wooden();
        shortflamewooden->setPos(x, 0);
        shortflamewooden->setScale(0.4);
        shortflamewooden->unmount();
        shortflamewooden->fall_v.setX(0);
        shortflamewooden->fall_v.setY(0);
        addItem(shortflamewooden);
        total_random_fallthing.push_back(shortflamewooden);
        break;
    }
    case 13:
    {
        Bow *longicemetal = new Lone_Ice_Metal();
        longicemetal->setPos(x, 0);
        longicemetal->setScale(0.4);
        longicemetal->unmount();
        longicemetal->fall_v.setX(0);
        longicemetal->fall_v.setY(0);
        addItem(longicemetal);
        total_random_fallthing.push_back(longicemetal);
        break;
    }
    case 14:
    {
        Bow *middleelecmetal = new Middle_Elec_Metal();
        middleelecmetal->setPos(x, 0);
        middleelecmetal->setScale(0.4);
        middleelecmetal->unmount();
        middleelecmetal->fall_v.setX(0);
        middleelecmetal->fall_v.setY(0);
        addItem(middleelecmetal);
        total_random_fallthing.push_back(middleelecmetal);
        break;
    }
    case 15:
    {
        Bow *shortflamewooden = new Short_Flame_Wooden_Bow();
        shortflamewooden->setPos(x, 0);
        shortflamewooden->setScale(0.4);
        shortflamewooden->unmount();
        shortflamewooden->fall_v.setX(0);
        shortflamewooden->fall_v.setY(0);
        addItem(shortflamewooden);
        total_random_fallthing.push_back(shortflamewooden);
        break;
    }
    case 16:
    {
        Arrow *elecarrow = new Elec_Arrow();
        elecarrow->setPos(x, 0);
        elecarrow->setScale(0.2);
        elecarrow->unmount();
        elecarrow->fall_v.setX(0);
        elecarrow->fall_v.setY(0);
        addItem(elecarrow);
        total_random_fallthing.push_back(elecarrow);
        break;
    }
    case 17:
    {
        Arrow *icearrow = new Ice_Arrow();
        icearrow->setPos(x, 0);
        icearrow->setScale(0.2);
        icearrow->unmount();
        icearrow->fall_v.setX(0);
        icearrow->fall_v.setY(0);
        addItem(icearrow);
        total_random_fallthing.push_back(icearrow);
        break;
    }
    case 18:
    {
        Arrow *flamearrow = new Flame_Arrow();
        flamearrow->setPos(x, 0);
        flamearrow->setScale(0.2);
        flamearrow->unmount();
        flamearrow->fall_v.setX(0);
        flamearrow->fall_v.setY(0);
        addItem(flamearrow);
        total_random_fallthing.push_back(flamearrow);
        break;
    }
    default:
        break;
    }
}

void BattleScene::handleCheatLine()                                      //设置信号与槽，摁下回车则调用fallthing函数
{
    QString text = lineEdit->text();
    int num = 0;
    if (text.toInt() != 0 && text.length() == 2)
    {
        num = text.toInt();
    }
    int x = rand() % (1270);
    fallthing(x, num);
}

void BattleScene::attack()
{
    static int num = 0;
    num++;
    if (num < 30)
    {
        return;
    }
    num = 0;


    Character *opponents[] = {character_2, character};

    for (int i = 0; i < 2; ++i)
    {
        if (!characters[i]->ice_attacked && characters[i]->isAttackDown())
        {
            characters[i]->characterattack(opponents[i]);
            if (opponents[i]->lifevalue < 0)
            {
                opponents[i]->bloodbar->setValue(0);
            }
            else
            {
                opponents[i]->bloodbar->setValue(opponents[i]->lifevalue);
            }
        }
    }

    character->showstate();
    character_2->showstate();
}

void BattleScene::changeweapon()
{
    for (Character *chara : characters)
    {
        if (chara->ischangeweaponDown() && !chara->ice_attacked)
        {
            chara->changeWeapon();
        }
    }
}

void BattleScene::cast()
{
    static int num = 0; // 设置有效投掷间隔
    num++;
    if (num < 50)
    {
        return;
    }
    num = 0;

    Character *characters[] = {character, character_2};
    QVector<Sword *> *totalCasting[] = {&totalcasting, &totalcasting_2}; // 使用指针数组指向 totalcasting 和 totalcasting_2

    for (int i = 0; i < 2; ++i)
    {
        Character *chara = characters[i];
        if (!chara->ice_attacked && chara->isCastDown() && chara->now_weapon != nullptr)
        {
            if (chara->now_weapon == chara->sword) // 当前使用近战武器
            {
                Sword *castthing = chara->getsword();
                if (castthing != nullptr)
                {
                    castthing->setPos(chara->pos().x(), chara->pos().y() - 130);
                    castthing->fall_v.setX(chara->isFace() ? 0.6 : -0.6); // 投掷初速度
                    totalCasting[i]->push_back(castthing); // 加入对应的投掷物数组
                    chara->charactercast();
                }
            }
            else // 当前使用武器为弓箭
            {
                chara->setattackstate(true);
                int arrowCount = chara->bow->arrownum;
                int distance = chara->bow->attackdistance;
                for (int j = 0; j < arrowCount; j++)
                {
                    Arrow *shootedarrow = chara->getshootedarrow();
                    if (shootedarrow != nullptr)
                    {
                        shootedarrow->setPos(chara->pos().x(), chara->pos().y() - 100);
                        if (chara->isFace()) // 确定人物朝向
                        {
                            shootedarrow->fall_v.setX(distance == 900 ? 3 : (distance == 650 ? 1 : 0.9));
                            shootedarrow->setRotation(45);
                        }
                        else
                        {
                            shootedarrow->fall_v.setX(distance == 900 ? -1 : (distance == 650 ? -1 : -0.9));
                            shootedarrow->setRotation(225);
                        }
                        totalshooted.push_back(shootedarrow);
                        chara->shootarrow();
                    }
                }
            }
        }
    }
}

void BattleScene::gravity(Item *item, qreal g)                                    //重力的实现
{
    int x = item->pos().x();
    int y = item->pos().y();

    if (item->parentItem() != character && item->parentItem() != character_2)  //处理那些没有被捡起的物品
    {
        if (x >= 0 && x < 270)                                                 //根据横坐标不同，讨论不同的落点
        {
            if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
            {
                item->fall_v.setY(item->fall_v.y() + g);
            }
            else
            {
                item->fall_v.setY(0);
            }
            if (y > map->getFloorHeight() - 10)
            {
                item->setPos(x, map->getFloorHeight());
            }
        }
        else if (x >= 270 && x < (270 + iceplat->boundingRect().width()))
        {
            if (item->fall_v.y() >= 0 && y < (300 - 30))
            {
                item->fall_v.setY(item->fall_v.y() + g);
            }
            else
            {
                item->fall_v.setY(0);
            }
            if (y > 290)
            {
                item->setPos(x, 300);
            }
        }
        else if (x >= (270 + iceplat->boundingRect().width()) && x < 560)
        {
            if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
            {
                item->fall_v.setY(item->fall_v.y() + g);
            }
            else
            {
                item->fall_v.setY(0);
            }
            if (y > (map->getFloorHeight() - 10))
            {
                item->setPos(x, map->getFloorHeight());
            }
        }
        else if (x >= 560 && x < (560 + rockplat->boundingRect().width()))
        {
            if (item->fall_v.y() >= 0 && y < (110) && y != -120)
            {
                item->fall_v.setY(item->fall_v.y() + g);
            }
            else if (item->fall_v.y() > 0 && y >= 110 && y < 150)
            {
                item->fall_v.setY(0);
                item->setPos(x, 120);
            }
            if (y > 170)
            {
                item->fall_v.setY(item->fall_v.y() + g);
                if (y > map->getFloorHeight())
                {
                    item->setPos(-120, -120);
                    item->fall_v.setX(0);
                    item->fall_v.setY(0);
                }
            }

        }
        else if (x >= (560 + rockplat->boundingRect().width()) && x < 1000)
        {
            if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
            {
                item->fall_v.setY(item->fall_v.y() + g);
            }
            else
            {
                item->fall_v.setY(0);
            }
            if (y > map->getFloorHeight() - 10)
            {
                item->setPos(x, map->getFloorHeight());
            }
        }
        else
        {
            if (fireplat->pos().x() == -1000)
            {
                if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
                {
                    item->fall_v.setY(item->fall_v.y() + g);
                }
                else
                {
                    item->fall_v.setY(0);
                }
                if (y > map->getFloorHeight() - 10)
                {
                    item->setPos(x, map->getFloorHeight());
                }
            }
            else
            {
                if (item->fall_v.y() >= 0 && y < (320 - 30))
                {
                    item->fall_v.setY(item->fall_v.y() + g);
                }
                else
                {
                    item->fall_v.setY(0);
                }
                if (y > 310)
                {
                    item->setPos(x, 320);
                }
            }

        }
    }
    if (item->fall_v.y() >= 0.8)
    {
        item->fall_v.setY(0.8);
    }

}
void BattleScene::handlecastthing()
{
    for (Sword *item : totalcasting)                                               //人物一所投掷的近战武器，位置更新和伤害判定
    {
        if (item == NULL)
        {
            continue;
        }
        handlecastweapon(item, character, character_2);
    }
    for (Sword *item : totalcasting_2)                                                         //人物二所投掷的近战武器，位置更新和伤害判定
    {
        if (item == NULL)
        {
            continue;
        }
        handlecastweapon(item, character_2, character);
    }
    for (Arrow *item : totalshooted_2)                                                         //人物二所射出的箭头，位置更新和伤害判定
    {
        if (item == NULL)
        {
            continue;
        }
        handleshootarrowattack(item, character, character_2);
    }
    for (Arrow *item : totalshooted)                                                                           //人物二所射出的箭头，位置更新和伤害判定，以下与人物以同理
    {
        if (item == NULL)
        {
            continue;
        }
        handleshootarrowattack(item, character_2, character);
    }

}

void BattleScene::isgameover()                                          //判断游戏是否结束（一方生命值小于0，判断另一方获胜）
{
    QString messages[] = {"玩家二胜利", "玩家一胜利"};

    for (int i = 0; i < 2; ++i)
    {
        if (characters[i]->lifevalue < 0)
        {
            characters[i]->bloodbar->setValue(0);
            gameover(messages[i]);
            return; // 游戏结束，退出函数
        }
    }

}

void BattleScene::gameover(QString text)                                //游戏结束弹出提示框，显示某方获胜，并关闭程序
{

    QMessageBox::critical(nullptr, "Game Over", text);
    timer->stop();
    QApplication::quit();
}

void BattleScene::changearrow()
{
    if (character->ischangearrowDown() && !character->ice_attacked)        //人物被冰冻时不能进行其他操作
    {
        character->changenow_arrow();
    }
    if (character_2->ischangearrowDown() && !character_2->ice_attacked)
    {
        character_2->changenow_arrow();
    }
}

void BattleScene::attackanimation()                                     //判断场上物品的受击状态，显示其受击效果（燃烧，触电，冰冻），以及人物攻击动画
{
    for(Character *character:characters)
    {
        if(character->isattack()&&character->now_weapon!=NULL)
        {
            character->opponent->beAttacked();

            static int num=0;
            num++;
            CharacterAttackAnimation(character);
            if(num>15)
            {
                num=0;
                Sword* sword =character->getsword();
                character->setattackstate(false);
                if(sword!=nullptr)
                {
                    sword->CompleteSwordAttack();
                    character->opponent->notBeAttacked();

                }

            }
        }
    }

    for (QGraphicsItem *item : items())                                                     //处理其他所有物品的受击效果
    {
        if (auto m_item = dynamic_cast<Item *>(item))
        {
            if (m_item->flame_attacked)
            {

                if (auto hero = dynamic_cast<Link *>(item))                                 //人物着火时持续受到伤害
                {
                    static int num_1 = 0;
                    num_1++;
                    if (num_1 % 50 == 0)
                    {
                        hero->lifevalue -= 1;
                        hero->bloodbar->setValue(hero->lifevalue);
                    }

                    if (num_1 > 250)
                    {
                        num_1 = 0;
                        hero->flame_attacked = false;
                        hero->flameItem->setVisible(false);
                    }
                    if (hero->now_weapon != NULL)                                          //检测手中的弓或剑是否是木制
                    {
                        if (auto weapon = dynamic_cast<Sword *>(hero->now_weapon))
                        {
                            if (weapon->material == "Wooden")
                            {
                                hero->now_weapon->flameItem->setVisible(true);
                                hero->now_weapon->flame_attacked = true;
                            }
                            (void)dynamic_cast<Item *>(hero->now_weapon);
                        }
                        else
                        {
                            if (auto weapon = dynamic_cast<Bow *>(hero->now_weapon))
                            {
                                if (weapon->material == "Wooden")
                                {
                                    hero->now_weapon->flameItem->setVisible(true);
                                    hero->now_weapon->flame_attacked = true;
                                }
                                (void)dynamic_cast<Item *>(hero->now_weapon);
                            }
                        }

                    }


                }
                else                                                                    //其他物品点燃后过一段时间会消失
                {
                    static int num_1 = 0;
                    static int life = 0;

                    num_1++;
                    if (num_1 > 250)
                    {
                        num_1 = 0;
                        life++;
                        m_item->flame_attacked = false;
                        m_item->flameItem->setVisible(false);

                    }
                    if (life > 3)
                    {
                        m_item->setPos(-1000, -1000);
                        removeItem(m_item);
                        if (item->pos().x() > 1000 && item->pos().y() > 200 && item->pos().y() < 340)
                        {
                            fireplat->platform_life--;
                            if (fireplat->platform_life <= 0)
                            {
                                fireplat->setPos(-1000, -1000);
                                fireplat->flame_attacked = false;
                                fireplat->flameItem->setVisible(false);

                            }
                        }
                        life = 0;
                    }
                }
            }
            if (m_item->ice_attacked)                                                  //被冰属性攻击后人物被冰冻
            {
                static int num_2 = 0;
                num_2++;
                if (num_2 > 250)
                {
                    num_2 = 0;
                    m_item->ice_attacked = false;
                    m_item->iceItem->setVisible(false);
                }


            }
            if (m_item->elec_attacked)                                                   //被电击的攻击效果
            {

                if (auto hero = dynamic_cast<Link *>(item))                                 //人物被电击，受到持续伤害
                {
                    static int num_3 = 0;
                    num_3++;
                    if (num_3 % 50 == 0)
                    {
                        hero->lifevalue -= 1;
                        hero->bloodbar->setValue(hero->lifevalue);
                    }

                    if (num_3 > 250)
                    {
                        num_3 = 0;
                        hero->elec_attacked = false;
                        hero->elecItem->setVisible(false);
                    }
                    if (hero->now_weapon != NULL)                                          //检测手中的弓或剑是否是金属材质，如果是金属材质，则掉落需重新捡起
                    {
                        if (auto weapon = dynamic_cast<Sword *>(hero->now_weapon))
                        {
                            if (weapon->material == "Metal")
                            {
                                auto castthing = hero->getsword();
                                castthing->setPos(hero->pos().x(), hero->pos().y() - 80);
                                hero->charactercast();
                            }
                            (void)dynamic_cast<Item *>(hero->now_weapon);
                        }
                        else
                        {
                            if (auto weapon = dynamic_cast<Bow *>(hero->now_weapon))
                            {
                                if (weapon->material == "Metal")
                                {
                                    auto castthing = hero->getbow();
                                    castthing->setPos(hero->pos().x(), hero->pos().y() - 80);
                                    hero->characterdropbow();
                                }
                                (void)dynamic_cast<Item *>(hero->now_weapon);
                            }
                        }

                    }

                }
                else                                                                    //其他物品被电击，显现电击效果
                {
                    static int num_3 = 0;
                    num_3++;
                    if (num_3 > 250)
                    {
                        num_3 = 0;
                        m_item->elec_attacked = false;
                        m_item->elecItem->setVisible(false);
                    }
                }

            }

        }
        (void)dynamic_cast<Item *>(item);


    }


}

void BattleScene::burnt()
{
    if (fireplat->flame_attacked)
    {
        for (Item *item : total_random_fallthing)
        {
            if (auto sword = dynamic_cast<Sword *>(item))
            {
                if (sword->material == "Wooden")                                                           //木制平台燃烧导致周围木制武器（弓和箭，无论是否捡起）被点燃
                {
                    if (sword->pos().x() > 1000 && sword->pos().y() > 150 && sword->pos().y() < 340)
                    {
                        sword->flame_attacked = true;
                        sword->flameItem->setVisible(true);
                    }
                }
            }
            else if (auto sword = dynamic_cast<Bow *>(item))
            {
                if (sword->material == "Wooden")
                {
                    if (sword->pos().x() > 1000 && sword->pos().y() > 200 && sword->pos().y() < 340)
                    {
                        sword->flame_attacked = true;
                        sword->flameItem->setVisible(true);
                    }
                }
            }
            (void)dynamic_cast<Item *>(item);

        }
        if (character->pos().x() > 1000 && character->pos().y() > 200 && character->pos().y() < 340)                   //人在着火平台旁会持续受到伤害
        {
            character->flameItem->setVisible(true);
            character->flame_attacked = true;
        }
        if (character_2->pos().x() > 1000 && character_2->pos().y() > 200 && character_2->pos().y() < 340)
        {
            character_2->flameItem->setVisible(true);
            character_2->flame_attacked = true;
        }
    }
    if (character->flame_attacked || character_2->flame_attacked)
    {
        for (Item *item : total_random_fallthing)
        {
            if (auto sword = dynamic_cast<Sword *>(item))
            {
                if (sword->material == "Wooden")                                                           //人物移动点燃周围木制物品
                {
                    if (Collision_detection(sword, character) && character->flame_attacked)
                    {
                        sword->flame_attacked = true;
                        sword->flameItem->setVisible(true);
                    }
                    if (Collision_detection(sword, character_2) && character_2->flame_attacked)
                    {
                        sword->flame_attacked = true;
                        sword->flameItem->setVisible(true);
                    }
                }
            }
            else if (auto sword = dynamic_cast<Bow *>(item))
            {
                if (sword->material == "Wooden")
                {
                    if (Collision_detection(sword, character) && character->flame_attacked)
                    {
                        sword->flame_attacked = true;
                        sword->flameItem->setVisible(true);
                    }
                    if (Collision_detection(sword, character_2) && character_2->flame_attacked)
                    {
                        sword->flame_attacked = true;
                        sword->flameItem->setVisible(true);
                    }
                }
            }
            (void)dynamic_cast<Item *>(item);

        }
        if (Collision_detection(character, character_2) && character->flame_attacked)
        {
            character_2->flameItem->setVisible(true);
            character_2->flame_attacked = true;
        }
        if (Collision_detection(character_2, character) && character_2->flame_attacked)
        {
            character->flameItem->setVisible(true);
            character->flame_attacked = true;
        }
        static int num_1 = 0;
        if (Collision_detection(character, fireplat) && character->flame_attacked)
        {
            fireplat->flame_attacked = true;
            fireplat->flameItem->setVisible(true);
            num_1++;
            if (num_1 >= 750)
            {
                fireplat->platform_life--;
                if (fireplat->platform_life <= 0)
                {
                    fireplat->setPos(-1000, -1000);
                    fireplat->flame_attacked = false;
                    fireplat->flameItem->setVisible(false);
                }
                num_1 = 0;
            }
        }
        static int num_2 = 0;
        if (Collision_detection(character_2, fireplat) && character_2->flame_attacked)
        {
            fireplat->flame_attacked = true;
            fireplat->flameItem->setVisible(true);
            num_2++;
            if (num_2 >= 750)
            {
                fireplat->platform_life--;
                if (fireplat->platform_life <= 0)
                {
                    fireplat->setPos(-1000, -1000);
                    fireplat->flame_attacked = false;
                    fireplat->flameItem->setVisible(false);
                }
                num_2 = 0;
            }
        }
    }
}

void BattleScene::elecspread()                                          //金属平台触电时传到至周围金属物品和人物
{
    if (iceplat->elec_attacked)
    {
        for (Item *item : total_random_fallthing)
        {
            if (auto sword = dynamic_cast<Sword *>(item))
            {
                if (sword->material == "Metal")
                {
                    if (sword->pos().x() > 240 && sword->pos().x() < 450 && sword->pos().y() > 250 && sword->pos().y() < 400)  //电流传导距离阈值
                    {
                        sword->elec_attacked = true;
                        sword->elecItem->setVisible(true);
                    }
                }
            }
            else if (auto sword = dynamic_cast<Bow *>(item))
            {
                if (sword->material == "Metal")
                {
                    if (sword->pos().x() > 1000 && sword->pos().y() > 200 && sword->pos().y() < 400)
                    {
                        sword->elec_attacked = true;
                        sword->elecItem->setVisible(true);
                    }
                }
            }
            (void)dynamic_cast<Item *>(item);

        }
        if (character->pos().x() > 240 && character->pos().x() < 450 && character->pos().y() > 200 && character->pos().y() < 340)          //人物在导电平台附近会受到电击
        {
            character->elecItem->setVisible(true);
            character->elec_attacked = true;
        }
        if (character_2->pos().x() > 240 && character_2->pos().x() < 450 && character_2->pos().y() > 200 && character_2->pos().y() < 340)
        {
            character_2->elecItem->setVisible(true);
            character_2->elec_attacked = true;
        }

    }
    if (character->elec_attacked || character_2->elec_attacked)                                          //人物被电击后，周围金属物品也会受到电击
    {
        for (Item *item : total_random_fallthing)
        {
            if (auto sword = dynamic_cast<Sword *>(item))
            {
                if (sword->material == "Metal")                                                           //人物移动导致周围金属物品触电
                {
                    if (Collision_detection(character, sword) && character->elec_attacked)
                    {
                        sword->elec_attacked = true;
                        sword->elecItem->setVisible(true);
                    }
                    if (Collision_detection(character_2, sword) && character_2->elec_attacked)
                    {
                        sword->elec_attacked = true;
                        sword->elecItem->setVisible(true);
                    }
                }
            }
            else if (auto sword = dynamic_cast<Bow *>(item))
            {
                if (sword->material == "Metal")
                {
                    if (Collision_detection(character, sword) && character->elec_attacked)
                    {
                        sword->elec_attacked = true;
                        sword->elecItem->setVisible(true);
                    }
                    if (Collision_detection(character_2, sword) && character_2->elec_attacked)
                    {
                        sword->elec_attacked = true;
                        sword->elecItem->setVisible(true);
                    }
                }
            }
            dynamic_cast<Item *>(item);

        }

        if (Collision_detection(character, character_2) && character->elec_attacked)
        {
            character_2->elecItem->setVisible(true);
            character_2->elec_attacked = true;
        }
        if (Collision_detection(character_2, character) && character_2->elec_attacked)
        {
            character->elecItem->setVisible(true);
            character->elec_attacked = true;
        }
        if (Collision_detection(character, iceplat) && character->elec_attacked)
        {
            iceplat->elec_attacked = true;
            iceplat->elecItem->setVisible(true);
        }
        if (Collision_detection(character_2, iceplat) && character_2->elec_attacked)
        {
            iceplat->elec_attacked = true;
            iceplat->elecItem->setVisible(true);
        }

    }
}

bool BattleScene::Collision_detection(Item *a, Item *b)
{
    if (abs(a->pos().x() - b->pos().x()) < 150 && abs(a->pos().y() - b->pos().y()) < 150) //人物之间的碰撞检测
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool BattleScene::handlecastweapon(Sword *item, Character *character_2, Character *character)
{
    if (item->pos().x() > 0)
    {
        int x = item->pos().x();
        int y = item->pos().y();

        if (item->parentItem() != character && item->parentItem() != character_2)
        {
            if (x >= 0 && x < 270)
            {
                if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                }
                else
                {
                    item->fall_v.setY(0);
                }
                if (y > map->getFloorHeight() - 10)
                {
                    item->setPos(x, map->getFloorHeight());
                }
            }
            else if (x >= 270 && x < (270 + iceplat->boundingRect().width()))
            {
                if (item->fall_v.y() >= 0 && y < (300 - 30))
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                }
                else
                {
                    item->fall_v.setY(0);
                    if (item->element == "Elec")
                    {
                        iceplat->elecItem->setVisible(true);
                        iceplat->elec_attacked = true;
                    }
                }
                if (y > 290)
                {
                    item->setPos(x, 300);
                }
            }
            else if (x >= (270 + iceplat->boundingRect().width()) && x < 560)
            {
                if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                }
                else
                {
                    item->fall_v.setY(0);
                }
                if (y > (map->getFloorHeight() - 10))
                {
                    item->setPos(x, map->getFloorHeight());
                }
            }
            else if (x >= 560 && x < (560 + rockplat->boundingRect().width()))
            {
                if (item->fall_v.y() >= 0 && y < (150 - 30) && y != -120)
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                }
                else if (item->fall_v.y() > 0 && y >= 120 && y < 150)
                {
                    item->fall_v.setY(0);

                    item->setPos(x, 150);
                    if (item->element == "Ice")
                    {
                        rockplat->iceItem->setVisible(true);
                        rockplat->ice_attacked = true;
                    }
                }
                if (y > 150)
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                    if (y > map->getFloorHeight())
                    {
                        item->fall_v.setX(0);
                        item->fall_v.setY(0);
                        item->setPos(-120, -120);

                    }
                }

            }
            else if (x >= (560 + rockplat->boundingRect().width()) && x < 1000)
            {
                if (item->fall_v.y() >= 0 && y < (map->getFloorHeight() - 20))
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                }
                else
                {
                    item->fall_v.setY(0);

                }
                if (y > map->getFloorHeight() - 10)
                {
                    item->setPos(x, map->getFloorHeight());
                }
            }
            else
            {
                if (item->fall_v.y() >= 0 && y < (320 - 30))
                {
                    item->fall_v.setY(item->fall_v.y() + 0.0002);
                }
                else
                {
                    item->fall_v.setY(0);
                    if (item->element == "Flame")
                    {
                        fireplat->flameItem->setVisible(true);
                        fireplat->flame_attacked = true;
                    }

                }
                if (y > 310)
                {
                    item->setPos(x, 320);
                }
            }
        }

        int distance = QLineF(item->pos(), character->pos()).length();
        if (distance < 100)
        {
            item->fall_v.setY(0);
            int elec = item->elec_value - character->protect_elec;
            int ice = item->ice_value - character->protect_ice;
            int flame = item->flame_value - character->protect_flame;
            int sum = elec + ice + flame;

            if (item->element == "Elec")
            {
                character->elec_attacked = true;
                character->elecItem->setVisible(true);
                if (character->ice_attacked)
                {
                    sum *= 2;
                    character->ice_attacked = false;
                    character->iceItem->setVisible(false);
                }
            }
            else if (item->element == "Ice")
            {
                character->ice_attacked = true;
                character->iceItem->setVisible(true);
                if (character->ice_attacked)
                {
                    sum *= 2;
                }
            }
            else if (item->element == "Flame")
            {
                character->flame_attacked = true;
                character->flameItem->setVisible(true);
                if (character->ice_attacked)
                {
                    sum *= 2;
                    character->ice_attacked = false;
                    character->iceItem->setVisible(false);
                }
            }

            character->lifevalue -= sum;
            character->bloodbar->setValue(character->lifevalue);
        }
        if (item->fall_v.y() == 0 && item->pos().y() > 0)
        {
            item->setPos(-120, -120);
            item->fall_v.setX(0);
        }
    }
}

bool BattleScene::handleshootarrowattack(Arrow *item, Character *character, Character *character_2)
{
    double g = 0;;
    if (item->pos().x() > 0)
    {
        // gravity(item,g);
        bool flag = false;
        int distance = QLineF(item->pos(), character->pos()).length();                     //判断射出的箭是否打到对方，计算伤害并更新生命值
        if (distance < 100)
        {
            item->fall_v.setY(0);
            flag = true;
            int elec = item->elec_value + character_2->bow->elec_value - character->protect_elec;
            int ice = item->ice_value + character_2->bow->ice_value - character->protect_ice;
            int flame = item->flame_value + character_2->bow->flame_value - character->protect_flame;
            int sum = elec + ice + flame;
            if (item->element == "Elec")                                                   //根据箭头的属性，播放相应的攻击效果
            {
                character->elec_attacked = true;
                character->elecItem->setVisible(true);
                if (character->ice_attacked)
                {
                    sum *= 2;
                    character->ice_attacked = false;
                    character->iceItem->setVisible(false);
                }
            }
            else if (item->element == "Ice")
            {
                character->ice_attacked = true;
                character->iceItem->setVisible(true);
                if (character->ice_attacked)
                {
                    sum *= 2;

                }
            }
            else if (item->element == "Flame")                                             //冰属性下伤害翻倍，并且立即解除冰冻状态
            {
                character->flame_attacked = true;
                character->flameItem->setVisible(true);
                if (character->ice_attacked)
                {
                    sum *= 2;
                    character->ice_attacked = false;
                    character->iceItem->setVisible(false);
                }
            }

            character->lifevalue -= sum;
            character->bloodbar->setValue(character->lifevalue);

        }

        // if(item->fall_v.y()==0&&item->pos().y()>0&&g!=0&&flag)
        // {
        //     item->setPos(-120,-120);
        //     removeItem(item);
        //     item->fall_v.setX(0);
        // }
        // else if(g==0&&flag)
        // {
        //     item->setPos(-120,-120);
        //     removeItem(item);
        //     item->fall_v.setX(0);
        // }
        if (flag)
        {
            item->setPos(-120, -120);
            removeItem(item);
            item->fall_v.setX(0);
        }
    }
}

void BattleScene::CharacterAttackAnimation(Character *character)
{
    Sword* sword=character->getsword();
    if(sword!=nullptr)
    {
        sword->SwordAttack();
    }

}


Mountable *BattleScene::findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold)
{
    Mountable *nearest = nullptr;
    qreal minDistance = distance_threshold;

    for (QGraphicsItem *item : items())
    {
        if (auto mountable = dynamic_cast<Mountable *>(item))       //判断是否可以拾取
        {
            if (!mountable->isMounted())                            //有拾取属性，是否已经被拾取
            {
                qreal distance = QLineF(pos, item->pos()).length();
                if (distance < minDistance) {
                    minDistance = distance;
                    nearest = mountable;
                }
            }
        }
    }

    return nearest;                                                 //寻找周围可拾取的最近物品
}

Mountable *BattleScene::pickupMountable(Character *character, Mountable *mountable)
{
    //检测拾取物品是什么类型，调用对应的函数
    if (auto armor = dynamic_cast<Armor *>(mountable))
    {
        return character->pickupArmor(armor);
    }
    else if (auto legarmor = dynamic_cast<LegEquipment *>(mountable))
    {
        return character->pickupLegArmor(legarmor);
    }
    else if (auto headarmor = dynamic_cast<HeadEquipment *>(mountable))
    {
        return character->pickupHeadArmor(headarmor);
    }
    else if (auto newSword = dynamic_cast<Sword *>(mountable))
    {
        return character->pickupSword(newSword);
    }
    else if (auto newBow = dynamic_cast<Bow *>(mountable))
    {
        return character->pickupBow(newBow);
    }
    return nullptr;
}

