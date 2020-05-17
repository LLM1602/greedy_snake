#include "startinterface.h"
#include <windows.h>

void StartInterface::PrintFirst()//蛇从左边出现到完全出现的过程,
{
    //明白了
    for(auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);//sleep():延时，执行挂起一段时间，也就是等待一段时间在继续执行，，
        //这样就有蛇在移动了的效果，因为直接打印点，太快了，一下子全部打出来了，通过Sleep()，延时打印，就好像在动
    }
}

//下面几个函数要好好理解
void StartInterface::PrintSecond()//蛇从左向右移动的过程
{
    //懂啦
    for(int i=10;i!=40;++i)//蛇头需要从10 移动到40,因为屏幕设置就是41*32,
    {
        /*计算蛇头的下一个位置，并将其压入startsnake中，绘制出来，将蛇尾去掉*/
        int j = ( ((i-2)%8) < 4 ) ? (15 + (i-2)%8) : (21-(i-2)%8);
        //15+(i-2)%8 :往下降
        //21-(i-2)%8 :往上升
        startsnake.emplace_back(Point(i,j));//双端队列，放入队列的后面，实际上在屏幕上是蛇头，也就是最右方
        startsnake.back().Print();//最后一个元素打印出来，也就是蛇头打印出来，
        startsnake.front().Clear();//然后清除屏幕上的一个点，也就是屏幕最左边的，即蛇尾
        startsnake.pop_front();//从队列中删除，即保证蛇的长度不变
        Sleep(speed);
    }
}

void StartInterface::PrintThird()////蛇从接触右边到消失的过程
{
    //懂啦
    while ( !startsnake.empty() || textsnake.back().GetX() < 33 ) //当蛇还没消失或文字没移动到指定位置
    {
        if ( !startsnake.empty() ) //如果蛇还没消失，继续移动
        {
            startsnake.front().Clear();//清除屏幕最左边的，将最左边的出队
            startsnake.pop_front();
        }
        ClearText();//清除已有文字，
        PrintText();//文字SNAKE开始慢慢出现
        //这里其实就是，先把显示的文字，直接用空格清除，但是在ClearText()时，已经显示的文字会被空格代替，并且会把所有文字向右移动一格
        Sleep(speed);
    }
}
void StartInterface::PrintText()
{
    //懂啦
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Print();//只显示X大于0的位置
    }
}
void StartInterface::ClearText()
{
    //懂啦
    for (auto& point : textsnake) //把在屏幕上显示的文字，SNAKE全用空格覆盖，覆盖后再把所有的点往右移一格
    {
        if (point.GetX() >= 0)
            point.Clear();//清除已经显示的文字，也就是x>=0 的文字
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}



