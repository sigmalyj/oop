#ifndef QT_PROGRAMMING_2024_ITEM_H
#define QT_PROGRAMMING_2024_ITEM_H

#include <QGraphicsItem>
#include <QPainter>

class Item : public QGraphicsItem {
public:
    explicit Item(QGraphicsItem *parent, const QString &pixmapPath);

    //返回一个物品的矩形
    [[nodiscard]] QRectF boundingRect() const override {
        if (pixmapItem != nullptr) {
            return this->pixmapItem->boundingRect();
        }
        return {};
    }

    //由子类决定具体画什么样子
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
    bool setonground(bool isonground);
    void setfall_v(QPointF fallv);

    QPointF fall_v;
    QPointF x_speed;                //物体的速度
    QPointF acceleration;          //物体的加速度
    QGraphicsPixmapItem *flameItem{};       //燃烧效果
    QGraphicsPixmapItem *iceItem{};         //冰冻效果
    QGraphicsPixmapItem *elecItem{};        //触电效果
    bool flame_attacked{};                  //触电、燃烧、冰冻状态
    bool ice_attacked{};
    bool elec_attacked{};
    bool isonground{};               //是否在地面上

protected:
    QGraphicsPixmapItem *pixmapItem{};      //贴图

};


#endif //QT_PROGRAMMING_2024_ITEM_H
