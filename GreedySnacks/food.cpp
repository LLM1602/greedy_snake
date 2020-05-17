#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void Food::DrawFood(Snake& csnake)//把蛇当作参数，这样可以计算随机出现的food是否合理
{
    /*利用rand函数获得坐标，并将其范围限制在2-29内，即在地图内，如果获得的坐标与蛇身重叠，则重新获取。
      同时每5颗食物就出现一颗限时食物*/
    while(true)
    {
        int tmp_x = rand()%30;
        int tmp_y = rand()%30;
        if(tmp_x<2)
            tmp_x += 2;
        if(tmp_y<2)
            tmp_y += 2;
        bool flag = false;
        for(auto& point : csnake.snake)
        {
            if((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y) )//big_x：先不管
            {
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        x = tmp_x;//x,y是为了记录出现的food的位置，因为后面在绘制限时食物时，要用来和x,y比较，也就是不同与这个普通食物重复。
        y = tmp_y;
        SetCursorPosition(x,y);
        //SetCursorPosition(tmp_x,tmp_y);
        SetColor(13);
        std::cout<<"★";//星星的颜色
        ++cnt;
        cnt%=5;
        if(cnt == 0)
        {
            //每吃到5次食物，就会出现限时食物
            DrawBigFood(csnake);
        }
        break;
    }
}
void Food::DrawBigFood(Snake& csnake)//绘制限时食物
{
    SetCursorPosition(5,0);
    SetColor(11);
    std::cout<<"------------------------------------------" ;//进度条
    progress_bar = 42;//进度条的分数
    while(true)
    {
        int tmp_x = rand()%30;
        int tmp_y = rand() % 30;
        if(tmp_x < 2) tmp_x += 2;
        if(tmp_y < 2) tmp_y += 2;
        bool flag = false;
        for (auto& point : csnake.snake)
        {
            if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        big_x = tmp_x;
        big_y = tmp_y;
        SetCursorPosition(big_x, big_y);
        SetColor(18);
        std::cout << "■" ;
        big_flag = true;//有限时食物
        flash_flag = true;//限时食物闪烁
        break;
    }
}

void Food::FlashBigFood()//闪烁限时食物
{
    SetCursorPosition(big_x,big_y);
    SetColor(18);
    if(flash_flag)
    {
        std::cout<<" ";
        flash_flag = false;
    }
    else
    {
        std::cout<<"■" ;
        flash_flag = true;
    }//这个if,else,就是在闪烁，
    SetCursorPosition(26,0);
    SetColor(11);
    for(int i=42;i>= progress_bar;--i)
        std::cout<<"\b\b";//因为progress_bar一直在变，所以显示出来，它会一直在动，就是闪在progress_bar那个位置
    --progress_bar;
    if(progress_bar == 0)
    {
        //时间走完了，急用空格把那个限时食物覆盖掉
        SetCursorPosition(big_x,big_y);
        std::cout<<"  ";
        SetCursorPosition(5,0);
        std::cout<<"                                          " ;//用空格去掉进度条
        big_flag = false;
        big_x = 0;
        big_y = 0;
    }
}
bool Food::GetBigFlag()
{
    return big_flag;
}
int Food::GetProgressBar()
{
    return progress_bar;
}



