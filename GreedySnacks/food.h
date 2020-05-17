#ifndef FOOD_H
#define FOOD_H
#include "snake.h"
class Snake;
class Food
{

private:
    int cnt;//记录连续吃到多少次食物了，到了第五次就出现限时食物，并被清0
    bool flash_flag;//闪烁标记
    bool big_flag;//是否有限时食物标记
    int x,y;//食物的位置
    int big_x,big_y;//限时食物的坐标
    int progress_bar;//限时食物进度条，用来控制加多少分的
    friend class Snake;//设置友元，可以访问私有元素
public:
    Food():cnt(0),flash_flag(false),big_flag(false),x(0),y(0),big_x(0),big_y(0),progress_bar(0){}
    void DrawFood(Snake& snake);//这里的参数，传递的是Snake的对象
    void DrawBigFood(Snake& snake);//这里的参数，传递的是Snake的对象
    void FlashBigFood();//闪烁限时食物
    bool GetBigFlag();//是否有限时食物出现
    int GetProgressBar();//返回吃到限时食物应得的分数
};
#endif // FOOD_H
