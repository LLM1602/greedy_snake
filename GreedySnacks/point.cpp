#include "point.h"
#include "tools.h"
#include <iostream>


void Point::Print()//输出方块
{
    //懂了
    SetCursorPosition(x,y);
    std::cout<<"■" ;//Alt+41462，一个方块占2个字节，
}

void Point::PrintCircular()//输出图形
{
    //懂啦，打印蛇
    SetCursorPosition(x,y);
    std::cout<<"●";//●
}
void Point::Clear()//清除输出
{
    //懂了，
    SetCursorPosition(x,y);//清除(x,y)这个点，不是真正清除，是通过覆盖，用空格来覆盖原来的点
    std::cout<<"  ";//此处是两个空格，因为都是占了2个字节的
}
void Point::ChangePosition(const int x,const int y)//改变坐标
{
    //懂啦
    this->x = x;
    this->y = y;
}


