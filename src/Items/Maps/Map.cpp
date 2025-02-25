#include "Map.h"

Map::Map(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {}

void Map::scaleToFitScene(QGraphicsScene *scene) {
    // Calculate scale factors to scale the item to fit the entire scene
    //得到map地图的矩形和场景的矩形
    QRectF sceneRect = scene->sceneRect();
    QRectF itemRect = boundingRect();

    qreal scaleX = sceneRect.width() / itemRect.width();
    qreal scaleY = sceneRect.height() / itemRect.height();

    // Choose the smaller scale factor to maintain aspect ratio
    qreal scaleFactor = qMin(scaleX, scaleY);

    // Apply the scale to the item
    setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true);//缩放

    // Center the item in the scene (optional)
    setPos((sceneRect.width() - boundingRect().width() * scaleFactor) / 2,
           (sceneRect.height() - boundingRect().height() * scaleFactor) / 2);//将map图片放在中心

}

QPointF Map::getSpawnPos() {
    auto boundingRect = sceneBoundingRect();
    auto midX = (boundingRect.left() + boundingRect.right()) * 0.5;
    return {midX, getFloorHeight()};
}

qreal Map::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return sceneRect.top() -(sceneRect.top() -sceneRect.bottom()) * 0.5;
}
