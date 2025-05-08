#include "StartScene.h"
#include <QGraphicsProxyWidget>
#include <QBrush>
#include <QPixmap>
#include <QDebug>
#include <QFont>

StartScene::StartScene(QObject *parent) : Scene(parent)
{
    // 加载背景图片
    QPixmap pixmap(":/Items/Maps/StartScene/StartScene.jpg");

    // 设置背景图片和场景大小为 1280x720
    setBackgroundBrush(QBrush(pixmap.scaled(1280, 720, Qt::KeepAspectRatioByExpanding)));
    setSceneRect(0, 0, 1280, 720);

    // 创建 Start 按钮
    startButton = new QPushButton("Start");
    startButton->setFixedSize(300, 120); // 增大按钮大小
    QFont font("Helvetica [Cronyx]", 40, QFont::StyleItalic, true); // 设置艺术字体
    startButton->setFont(font);

    // 设置按钮样式表，增加颜色和阴影效果
    startButton->setStyleSheet(
        "background-color: transparent;color: white;" // 背景透明
    );

    QGraphicsProxyWidget *proxy = addWidget(startButton);

    // 设置按钮位置
    proxy->setPos((1280 - startButton->width()) -200, (720 - startButton->height()) / 2); // 居中按钮

    // 连接按钮点击信号
    connect(startButton, &QPushButton::clicked, this, &StartScene::startButtonClicked);
}
