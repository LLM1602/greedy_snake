#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"
class Food;
class Snake
{
public:
    enum Direction{UP,DOWN,LEFT,RIGHT};//enum :用来枚举变量
    Snake(){
        //最开始蛇的大小以及方向
        snake.emplace_back(14,8);
        snake.emplace_back(15,8);
        snake.emplace_back(16,8);
        direction = Direction::DOWN;//初始选择方向，蛇一绘制完成，direction就是：down
    }
    void InitSnake();//初始化蛇
    void Move();//蛇吃到食物，增长
    void NormalMove();//蛇没吃到食物时的正常移动
    bool OverEdge();//判断蛇是否撞到边界
    bool HitItself();//判断是否撞到自己
    bool ChangeDirection();//改变方向，用来判断方向是否改变，并把direction的值改变，
    bool GetFood(const Food& food);//吃到食物
    bool GetBigFood(Food& food);//吃到限时食物
private:
    std::deque<Point>snake;//双端队列,有类似vector的功能
    Direction direction;
    friend class Food;//将Food类置为友元，以便访问其私有元素
};
#endif // SNAKE_H

