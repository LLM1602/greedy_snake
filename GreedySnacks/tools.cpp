#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)//设置窗口大小
{
    //懂了
    system("title 贪吃蛇");//设置窗口标题，黑款左上角会显示贪吃蛇,固定的“title+....."
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)：设置窗口宽度和高度,固定的库函数以及写法
}

void SetCursorPosition(const int x, const int y)//设置光标位置,相当于是个接口，还要调用windows里 的函数，SetConsoleCursorPosition
{
    //懂了
    COORD position;//COORD:固定的结构体变量，有两个成员X,Y
    position.X = x * 2 ;//一个图形■占两个字符，故宽度乘以2
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    //可直接记住即可。
    //GetStdHandle(STD_OUTPUT_HANDLE)：标准输出程序的句柄
    //SetConsoleCursorPosition:在写入输出之前将光标移动到所需位置，即(x,y)的位置m
}

void SetColor(int colorID)//设置文本颜色
{
    //懂了
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
    //GetStdHandle(STD_OUTPUT_HANDLE)：固定输出句柄
    //
}

void SetBackColor()//设置文本背景色
{
    //懂了
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}

