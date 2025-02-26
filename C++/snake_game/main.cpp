#include <iostream>
#include <unistd.h>
#include "game.h"

int main() {
    init();
    while (!isGameOver()) {
        draw();
        input();
        logic();
        usleep(2000000); // 控制游戏速度，单位是微秒
    }
    std::cout << "Game Over!" << std::endl;
    return 0;
}