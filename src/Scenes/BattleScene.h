#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H


#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"
#include "../Items/platform.h"
#include"cheatline.h"
#include<QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QKeyEvent>
class BattleScene : public Scene {
    Q_OBJECT

public:
    explicit BattleScene(QObject *parent);

    void processInput() override;               //用户按键处理

    void processMovement() override;            //更新场景中所有item的位置信息

    void processPicking() override;

    void HeroInPut(Character*character);        //移动、拾取、跳跃动作的实现

    void fall() override;                       //随机掉落物品

    void handlefallthing() override;            //处理掉落物品，更改其速度，调用gravity();

    void deletefallthing() override;            //掉落物品每隔一段时间会自动消失

    void fallthing(int x,int num) override;     //掉落哪一种物品

    void handleCheatLine() override;            //作弊行输入

    void attack() override;                     //攻击函数

    void changeweapon() override;               //切换武器

    void cast() override;                       //投掷近战武器和射箭，设置初速度

    void gravity(Item *, qreal g=0.015) override;              //游戏重力引擎，处理需要下落的物品

    void handlecastthing()override;             //处理投掷物，计算伤害值，确定受击状态

    void isgameover()override;                  //判断游戏是否结束

    void gameover(QString text) override;       //弹出游戏结束对话框并结束程序

    void changearrow() override;                //切换箭头

    void attackanimation() override;            //判断场上物品的受击状态，显示其受击效果（燃烧，触电，冰冻），以及人物攻击动画

    void burnt () override;                     //木制平台燃烧导致周围木制武器被点燃

    void elecspread() override;                 //金属平台触电时传到至周围金属物品和人物

    bool Collision_detection(Item* a,Item* b) ;         //碰撞检测

    bool Collision_detection(Item* a,QRectF b);         //碰撞检测

    bool stop_detection(Item* item, Item *rect, QString text);         //碰撞检测

    void handlecastweapon(Sword* item,Character *attacker,Character* opponent); //处理投掷物碰撞
    void handleshootarrowattack(Arrow* item,Character *attacker,Character* opponent); //处理射出的箭碰撞

    void newgravity(Item* item);              //物品下落函数

    void processPlayerInput(Character* character);   //处理人物输入

    void CharacterAttackAnimation(Character* character); //人物攻击函数
protected slots:

    void update() override;                     //游戏主循环

protected:
    void keyPressEvent(QKeyEvent *event) override;      //处理按键摁下事件

    void keyReleaseEvent(QKeyEvent *event) override;    //处理按键松开事件
               //游戏结束信号

private:
    //寻找周围可拾取的最近物品

    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max());

    //返回拾取新物品时换下来的旧物品

    static Mountable * pickupMountable(Character *character, Mountable *mountable);

    Map *map;                               //界面元素：地图、两个人物、三个平台、两个血条、两个文本框、游戏结束对话框
    Character *character;
    Character *character_2;
    PlatForm *iceplat;
    PlatForm *fireplat;
    PlatForm *rockplat;
    QVector<Item*>total_random_fallthing;           //两个记录已投掷武器的数组、两个记录已发射的箭的数组、一个记录凋落物的数组
    QVector<Sword *>totalcasting;
    QVector<Sword*>totalcasting_2;
    QVector<Arrow*>totalshooted;
    QVector<Arrow*>totalshooted_2;
    CheatLine *lineEdit;
    QDialog dialog;
    Character* characters[2];               //两个角色
    PlatForm* platforms[3];                //三个平台

};


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
