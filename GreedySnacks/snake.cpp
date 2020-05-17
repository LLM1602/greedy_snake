#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>
using namespace std;
void Snake::InitSnake()//初始化蛇
{
    //打印最开始的蛇
    for(auto& point : snake)
        point.PrintCircular();
}

void Snake::Move()//蛇增长
{
    //懂啦
    //cout<<"move "<<direction<<endl;
    switch(direction)//是对的，back()是头部
    {
        case Direction::UP:
            snake.emplace_back(Point(snake.back().GetX(),snake.back().GetY()-1));
            break;
        case Direction::DOWN:
        snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1 ));
        break;
    case Direction::LEFT:
        snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY() ));
        break;
    case Direction::RIGHT:
        snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY() ));
        break;
    default:
        break;
    }
    SetColor(14);
    snake.back().PrintCircular();//绘制新的蛇的头部
}

void Snake::NormalMove()//蛇正常移动，头增长，尾缩短
{
    //cout<<"normalmove "<<direction<<endl;
    Move();//
    snake.front().Clear();//front()对应的是尾巴
    snake.pop_front();//

}
bool Snake::OverEdge()//超出边界
{
    //懂啦
    //snack.back()就是蛇的头部
    return snake.back().GetX() <30 &&snake.back().GetY() <30 &&
           snake.back().GetX() >1  &&snake.back().GetY() >1;
}
bool Snake::HitItself()//撞到自己
{
    std::deque<Point>::size_type cnt = 1;
    Point *head = new Point(snake.back().GetX(),snake.back().GetY());//?这不是尾部元素吗啊？-》就是蛇头
    for(auto& point:snake)//????如果整条蛇中与蛇头不相同的坐标不等于蛇长，则意味着蛇头碰撞到自身
    {
        if(!(point == *head))
            cnt++;
        else
            break;
    }
    delete head;
    if(cnt == snake.size())//应该是size()-1
        return true;
    else
        return false;

}
bool Snake::ChangeDirection()//改变方向
{
    //操纵蛇的方向，懂啦
    //char ch;
    //cout<<"changeDirction "<<direction<<endl;
    int ch;
    if(kbhit())//kbhit():检查是否有键盘输入,有返回非0，无返回0
    {
        ch = getch();//getch():当用户按下某个字符时，函数自动读取，无需按回车
        //在用getch（）（在头文件conio.h）获得上下左右键的键值时候，他们是双键值，会返回高八位和低八位的int型数值。
        //这里getch():先读前8位，上下左右的前8位的值是 无符号值224，对应有符号值是-32，用int :第一次就是224，第二次就是，72，用char :只有8位，且是有符号，-32
        //可用这个程序去试
//        char ch;
//        while((ch=getch())!=0x1B) /* ESC to quit */
//        {
//            printf("%d \n", ch);
//        }
        switch(ch)
        {

        case 224://
            ch = getch();//这里再读取后八位，
            //printf("22 %d\n",ch);
            switch(ch)
            {
            case 72://up
                if(direction != Direction::DOWN)//判断想要移动方向与原本运动方向是否相反，相反则无效
                    direction = Direction::UP;
                break;
            case 80://down
                if(direction != Direction::UP)
                    direction = Direction::DOWN;
                break;
            case 75://left
                if (direction != Direction::RIGHT)
                    direction = Direction::LEFT;
                break;
            case 77://right
                if (direction != Direction::LEFT)
                    direction = Direction::RIGHT;
                break;
            default:
                break;
            }
            return true;
        case 27://esc:跳出esc:0x1B->也就是27
            return false;
        default:
            return true;
        }
    }
    return true;
}
bool Snake::GetFood(const Food& cfood)
{
    //懂啦
    if(snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
        return true;
    else
        return false;
}
bool Snake::GetBigFood(Food& cfood)//吃到限时食物
{
    if(snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
    {
        cfood.big_flag = false;//限时食物置为false
        cfood.big_x = 0;
        cfood.big_y = 0;//还原
        SetCursorPosition(1, 0);//吃大了，也要把进度条清空
        std::cout << "                                                            " ;//进度条清空
        return true;
    }
    else
        return false;
}




































