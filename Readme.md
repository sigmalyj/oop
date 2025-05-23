# ZELDA：THE FINAL BATTLE

## ![开始界面](src/assets/Items/Maps/StartScene/StartScene.jpg)

## 开发者及分工：

- 王田杨，2022010251，wang-ty22@mails.tsinghua.edu.cn
  - 主要游戏逻辑函数编写
  - 修改并提高代码逻辑复用性
  - 装备穿戴位置优化
  - 受击动画实现
  - 游戏结束界面及逻辑
- 李炎佳，2022030078，yj-li22@mails.tsinghua.edu.cn
  - 主要游戏逻辑函数编写
  - 解决程序warning
  - 美工素材修改与整理
  - 增加cCmakelists
  - 游戏开始和帮助界面逻辑


## 1 学习内容

1. 使用Qt开发实现。
2. 充分使用面向对象编程的思想，对不同模块进行抽象与封装。充分利用继承性与多态性，处理各子类的共性与差异。
3. 利用信号-槽机制实现了页面切换等控制

## 2 如何编译运行

本项目使用 `Qt Creator` 构建，
开发环境为：

    Win11
    Qt Creator 14.0.1
    Qt 6.5.3

编译运行：

    1. 在 Qt Creator 中选择 qthomework.pro 打开项目
    2. 选择 Qt 6.8.0 MinGW 64-bit 或其他构建套件进行配置
    3. 点击编译运行

运行：

    双击 bin 目录下的 qt_programming_2024.exe 即可

## 3 操作介绍

### 3.1 玩家 1

`按键A`：向左移动

`按键D`：向右移动

`按键J`：攻击

`按键K`：跳跃

`space`:拾取

`按键E`：远程武器攻击 / 扔出近战武器

`按键Q`：切换武器

`按键R`：切换箭头

### 3.2 玩家 2

`按键Left`：向左移动

`按键Right`：向右移动

`按键Up`：跳跃

`按键Comma`：拾取

`按键N`：攻击

`按键V`：切换箭矢

`按键B`：远程武器攻击 / 扔出近战武器

`按键M`：切换武器

### 3.3 其他操作

`右上角作弊框：`输入两个数字“01~18"用于生成不同的掉落物，便于测试。


## 4 验证部分

**程序运行流程**：

程序初始进入 `StartScene` 界面

在 `BattleScene` 中，程序主要依靠 90FPS 的 `BattleScene::update()` （核心函数）推动运行，

每次 `update` 中，处理以下流程，每个都有对应地函数实现：

1. 用户输入
2. 移动并更新所有物品位置
3. 掉落，拾取
5. 攻击，动画（受击动画，火/电传导）
7. 生命值进度条显示更新、游戏进程判断

## 5 功能展示

### 5.1：基本移动和生命值

- [x] 人物左右移动
- [x] 人物跳跃，能够跳到更高的平台上
- [x] 实现重力加速度
- [x] 两个玩家同屏对战

### 5.2 ：多种地形

- [x] 不同高度的平台
- [x] 不同材质的平台：岩石、木质、金属

### 5.3 ：生命值系统

- [x] 每个玩家各有100点生命值，在上方血条显示

- [x] 受到伤害会减少生命值。一方生命值 $\leq 0$ 时，进入死亡状态；跳转到游戏结算界面，结束界面决定是否重新开始游戏或者直接退出

### 5.4 ：物品掉落

- [x] 物品从空中随机出现，按照重力规律下落


- [x] 玩家可捡起附近物品。

- [x] 使用作弊码生成指定物品

### 5.5 ：近战武器

- [x] 能渲染玩家装备的武器，有攻击动画（旋转表示）
- [x] 可进行攻击
- [x] 近战武器有多种类型
- [x] 近战武器有两种材质：木质、金属质

- [x] 可投掷近战武器，受重力作用，接触人或平台触发攻击并消失

### 5.6 ：弓和箭

- [x] 同时拥有近战武器和弓时，玩家可切换武器
- [x] 空中会掉落不同元素类型的箭，拾取可增加弹容量。可在不同类型的能量球间切换，可以射出，不受重力作用。

- [x] 支持三种类型不同的箭矢

- [x] 箭矢有两种材质：木质、金属质
- [x] 能够渲染飞行中的箭和投掷武器

### 5.7 ：火属性

- [x] 有火属性的箭和近战武器，被这些武器攻击后进入着火状态


- [x] 玩家在着火物体附近会持续受到伤害
- [x] 木质物品着火后一段时间燃尽消失
- [x] 着火效果能够传播

- [x] 显示燃烧效果

### 5.8 ：冰属性

- [x] 有冰属性的箭和近战武器，被这些武器攻击后进入冰冻状态
- [x] 玩家在冰冻状态下不能进行任何操作，稍后解除冰冻状态
- [x] 在冰冻状态下受到攻击双倍伤害，立即解除冰冻状态
- [x] 显示冰冻效果

### 5.9 ：电属性

- [x] 有电属性的箭和近战武器，被这些武器攻击后进入触电状态

- [x] 通电效果能够快速传播

- [x] 人物触电时，若手持金属武器，则武器掉落

- [x] 显示触电效果

### 5.10 ：多种盔甲

- [x] 有三个部分的盔甲，每个部分都有火抗、冰抗、电抗的免疫效果

### 5.11 用户体验

- [x] 用户界面友好，移动、攻击、受击、生命值、buff/debuff状态等有清晰的显示

- [x] 动作流畅，帧率能稳定在30FPS以上

  
