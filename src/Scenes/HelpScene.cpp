#include "HelpScene.h"
#include <QGraphicsProxyWidget>
#include <QBrush>
#include <QPixmap>
#include <QFont>

HelpScene::HelpScene(QObject *parent) : Scene(parent)
{
    // 加载背景图片
    QPixmap pixmap(":/Items/Maps/HelpScene/HelpScene.png");
    setBackgroundBrush(QBrush(pixmap.scaled(1280, 720, Qt::KeepAspectRatioByExpanding)));
    setSceneRect(0, 0, 1280, 720);

    // 创建 Return 按钮
    returnButton = new QPushButton("Return");
    returnButton->setFixedSize(180, 60);
    QFont font("Algerian", 30, QFont::Bold, true);
    returnButton->setFont(font);

    // 设置按钮样式表，增加鼠标悬停时的反馈效果
    returnButton->setStyleSheet(
        "QPushButton {"
        "    background-color: transparent;"
        "    color: white;"
        "}"
        "QPushButton:hover {"
        "    background-color: rgba(0, 0, 0, 50); /* 浅透明蒙版 */"
        "    color: white;"
        "}"
        "QPushButton:pressed {"
        "    background-color: rgba(0, 0, 0, 100); /* 更深的透明蒙版 */"
        "    color: lightgray;"
        "}"
    );

    QGraphicsProxyWidget *proxy = addWidget(returnButton);
    proxy->setPos(70, 50);

    // 连接 Return 按钮信号
    connect(returnButton, &QPushButton::clicked, this, &HelpScene::returnButtonClicked);
}
