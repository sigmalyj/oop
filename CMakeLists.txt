cmake_minimum_required(VERSION 3.16)

# 项目信息
project(qthomework LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Qt 包
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

#用来编译ui文件
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 添加资源文件
qt6_add_resources(RESOURCES src/assets/assets.qrc)

# 包含头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加头文件
set(HEADERS
    src/MyGame.h
    src/Items/Item.h
    src/Items/Mountable.h
    src/Items/platform.h
    src/Scenes/BattleScene.h
    src/Scenes/StartScene.h
    src/Scenes/HelpScene.h
    src/Scenes/GameOverScene.h
    src/Scenes/cheatline.h
    src/Scenes/woodplat.h
    src/Scenes/iceplat.h
    src/Scenes/rockplat.h
    src/Scenes/Scene.h
    src/Items/Armors/Armor.h
    src/Items/Armors/elecbreakerarmor.h
    src/Items/Armors/FlamebreakerArmor.h
    src/Items/Armors/icebreakerarmor.h
    src/Items/Armors/OldShirt.h
    src/Items/Arrow/arrow.h
    src/Items/Arrow/elec_arrow.h
    src/Items/Arrow/flame_arrow.h
    src/Items/Arrow/ice_arrow.h
    src/Items/Bow/bow.h
    src/Items/Bow/lone_ice_metal.h
    src/Items/Bow/middle_elec_metal.h
    src/Items/Bow/short_flame_wooden_bow.h
    src/Items/Characters/Character.h
    src/Items/Characters/conf.h
    src/Items/Characters/Link.h
    src/Items/HeadEquipments/CapOfTheHero.h
    src/Items/HeadEquipments/elecbreakerhead.h
    src/Items/HeadEquipments/flamebreakerhead.h
    src/Items/HeadEquipments/HeadEquipment.h
    src/Items/HeadEquipments/icebreakerhead.h
    src/Items/LegEquipments/elecbreakertrou.h
    src/Items/LegEquipments/flamebreakertrou.h
    src/Items/LegEquipments/icebreakertrou.h
    src/Items/LegEquipments/LegEquipment.h
    src/Items/LegEquipments/WellWornTrousers.h
    src/Items/Maps/Battlefield.h
    src/Items/Maps/Map.h
    src/Items/Sword/double_ice_metal.h
    src/Items/Sword/long_elec_metal.h
    src/Items/Sword/short_flame_wooden.h
    src/Items/Sword/sword.h
)

# 添加源文件
set(SOURCES
    src/main.cpp
    src/MyGame.cpp
    src/Items/Item.cpp
    src/Items/Mountable.cpp
    src/Items/platform.cpp
    src/Scenes/BattleScene.cpp
    src/Scenes/StartScene.cpp
    src/Scenes/HelpScene.cpp
    src/Scenes/GameOverScene.cpp
    src/Scenes/cheatline.cpp
    src/Scenes/woodplat.cpp
    src/Scenes/iceplat.cpp
    src/Scenes/rockplat.cpp
    src/Scenes/Scene.cpp
    src/Items/Armors/Armor.cpp
    src/Items/Armors/elecbreakerarmor.cpp
    src/Items/Armors/FlamebreakerArmor.cpp
    src/Items/Armors/icebreakerarmor.cpp
    src/Items/Armors/OldShirt.cpp
    src/Items/Arrow/arrow.cpp
    src/Items/Arrow/elec_arrow.cpp
    src/Items/Arrow/flame_arrow.cpp
    src/Items/Arrow/ice_arrow.cpp
    src/Items/Bow/bow.cpp
    src/Items/Bow/lone_ice_metal.cpp
    src/Items/Bow/middle_elec_metal.cpp
    src/Items/Bow/short_flame_wooden_bow.cpp
    src/Items/Characters/Character.cpp
    src/Items/Characters/Link.cpp
    src/Items/HeadEquipments/CapOfTheHero.cpp
    src/Items/HeadEquipments/elecbreakerhead.cpp
    src/Items/HeadEquipments/flamebreakerhead.cpp
    src/Items/HeadEquipments/HeadEquipment.cpp
    src/Items/HeadEquipments/icebreakerhead.cpp
    src/Items/LegEquipments/elecbreakertrou.cpp
    src/Items/LegEquipments/flamebreakertrou.cpp
    src/Items/LegEquipments/icebreakertrou.cpp
    src/Items/LegEquipments/LegEquipment.cpp
    src/Items/LegEquipments/WellWornTrousers.cpp
    src/Items/Maps/Battlefield.cpp
    src/Items/Maps/Map.cpp
    src/Items/Sword/double_ice_metal.cpp
    src/Items/Sword/long_elec_metal.cpp
    src/Items/Sword/short_flame_wooden.cpp
    src/Items/Sword/sword.cpp
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets)