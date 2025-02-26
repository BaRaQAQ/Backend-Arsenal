#include <iostream>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include "game.h"

// 全局变量
const int WIDTH = 20;
const int HEIGHT = 20;
std::vector<Point> snake;
Point food;
int direction;
bool gameOver;

// 非阻塞读取输入
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// 初始化游戏
void init() {
    gameOver = false;
    direction = 1; // 1: 右, 2: 左, 3: 上, 4: 下
    snake.clear();
    snake.push_back(Point(WIDTH / 2, HEIGHT / 2));
    srand(time(NULL));
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

// 绘制游戏界面
void draw() {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            bool isSnake = false;
            for (size_t k = 0; k < snake.size(); k++) {
                if (snake[k].x == j && snake[k].y == i) {
                    std::cout << "O";
                    isSnake = true;
                    break;
                }
            }
            if (!isSnake) {
                if (food.x == j && food.y == i) {
                    std::cout << "F";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}

// 处理用户输入
void input() {
    if (std::cin.rdbuf()->in_avail()) {
        switch (getch()) {
        case 'w':
            if (direction != 4) direction = 3;
            break;
        case 's':
            if (direction != 3) direction = 4;
            break;
        case 'a':
            if (direction != 1) direction = 2;
            break;
        case 'd':
            if (direction != 2) direction = 1;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// 游戏逻辑更新
void logic() {
    Point head = snake[0];
    switch (direction) {
    case 1:
        head.x++;
        break;
    case 2:
        head.x--;
        break;
    case 3:
        head.y--;
        break;
    case 4:
        head.y++;
        break;
    }

    // 检查是否吃到食物
    if (head.x == food.x && head.y == food.y) {
        snake.insert(snake.begin(), head);
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
    } else {
        snake.insert(snake.begin(), head);
        snake.pop_back();
    }

    // 检查是否撞到边界或自身
    if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) {
        gameOver = true;
    }
    for (size_t i = 1; i < snake.size(); i++) {
        if (head.x == snake[i].x && head.y == snake[i].y) {
            gameOver = true;
        }
    }
}

// 检查游戏是否结束
bool isGameOver() {
    return gameOver;
}