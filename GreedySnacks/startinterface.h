#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "point.h"

class StartInterface
{
public:
    StartInterface() : speed(30){
        startsnake.emplace_back(Point(0,14));//Éß,蛇刚开始的像v字形一样
        startsnake.emplace_back(Point(1,14));
        startsnake.emplace_back(Point(2,15));
        startsnake.emplace_back(Point(3,16));
        startsnake.emplace_back(Point(4,17));
        startsnake.emplace_back(Point(5,18));
        startsnake.emplace_back(Point(6,17));
        startsnake.emplace_back(Point(7,16));
        startsnake.emplace_back(Point(8,15));
        startsnake.emplace_back(Point(9,14));

        textsnake.emplace_back(Point(-26, 14));//S，刚开始SNAKE的点在X轴的负半轴
        textsnake.emplace_back(Point(-25, 14));
        textsnake.emplace_back(Point(-27, 15));
        textsnake.emplace_back(Point(-26, 16));
        textsnake.emplace_back(Point(-25, 17));
        textsnake.emplace_back(Point(-27, 18));
        textsnake.emplace_back(Point(-26, 18));

        textsnake.emplace_back(Point(-23, 14));//N
        textsnake.emplace_back(Point(-23, 15));
        textsnake.emplace_back(Point(-23, 16));
        textsnake.emplace_back(Point(-23, 17));
        textsnake.emplace_back(Point(-23, 18));
        textsnake.emplace_back(Point(-22, 15));
        textsnake.emplace_back(Point(-21, 16));
        textsnake.emplace_back(Point(-20, 17));
        textsnake.emplace_back(Point(-19, 14));
        textsnake.emplace_back(Point(-19, 15));
        textsnake.emplace_back(Point(-19, 16));
        textsnake.emplace_back(Point(-19, 17));
        textsnake.emplace_back(Point(-19, 18));

        textsnake.emplace_back(Point(-17, 18));//A
        textsnake.emplace_back(Point(-16, 17));
        textsnake.emplace_back(Point(-15, 16));
        textsnake.emplace_back(Point(-14, 15));
        textsnake.emplace_back(Point(-14, 16));
        textsnake.emplace_back(Point(-13, 14));
        textsnake.emplace_back(Point(-13, 16));
        textsnake.emplace_back(Point(-12, 15));
        textsnake.emplace_back(Point(-12, 16));
        textsnake.emplace_back(Point(-11, 16));
        textsnake.emplace_back(Point(-10, 17));
        textsnake.emplace_back(Point(-9, 18));

        textsnake.emplace_back(Point(-7, 14));//K
        textsnake.emplace_back(Point(-7, 15));
        textsnake.emplace_back(Point(-7, 16));
        textsnake.emplace_back(Point(-7, 17));
        textsnake.emplace_back(Point(-7, 18));
        textsnake.emplace_back(Point(-6, 16));
        textsnake.emplace_back(Point(-5, 15));
        textsnake.emplace_back(Point(-5, 17));
        textsnake.emplace_back(Point(-4, 14));
        textsnake.emplace_back(Point(-4, 18));

        textsnake.emplace_back(Point(-2, 14));//E
        textsnake.emplace_back(Point(-2, 15));
        textsnake.emplace_back(Point(-2, 16));
        textsnake.emplace_back(Point(-2, 17));
        textsnake.emplace_back(Point(-2, 18));
        textsnake.emplace_back(Point(-1, 14));
        textsnake.emplace_back(Point(-1, 16));
        textsnake.emplace_back(Point(-1, 18));
        textsnake.emplace_back(Point(0, 14));
        textsnake.emplace_back(Point(0, 16));
        textsnake.emplace_back(Point(0, 18));
    }
    void PrintFirst();//蛇（v字形）出现再界面上
    void PrintSecond();//蛇从左移动到右，
    void PrintThird();//蛇逐渐消失
    void PrintText();//SNAKE文字的移动
    void ClearText();//SNAKE文字的消失
    void Action();
private:
    std::deque<Point> startsnake;//开始动画中的蛇
    std::vector<Point> textsnake;//开始动画中的文字
    int speed;//动画的速度
};
#endif // STRATINTERFACE_H



