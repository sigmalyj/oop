#include "cheatline.h"

 CheatLine::CheatLine(QWidget *parent) : QLineEdit(parent) {
    // 设置最大长度为2，以便只能输入两个字符
    setMaxLength(2);
}
