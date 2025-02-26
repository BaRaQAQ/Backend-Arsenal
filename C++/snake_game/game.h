#ifndef GAME_H
#define GAME_H

#include <vector>

// 定义坐标结构体
struct Point {
    int x;
    int y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};

// 初始化游戏
void init();
// 绘制游戏界面
void draw();
// 处理用户输入
void input();
// 游戏逻辑更新
void logic();
// 检查游戏是否结束
bool isGameOver();

#endif