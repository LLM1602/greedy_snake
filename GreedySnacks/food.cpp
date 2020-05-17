#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void Food::DrawFood(Snake& csnake)//���ߵ����������������Լ���������ֵ�food�Ƿ����
{
    /*����rand����������꣬�����䷶Χ������2-29�ڣ����ڵ�ͼ�ڣ������õ������������ص��������»�ȡ��
      ͬʱÿ5��ʳ��ͳ���һ����ʱʳ��*/
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
            if((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y) )//big_x���Ȳ���
            {
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        x = tmp_x;//x,y��Ϊ�˼�¼���ֵ�food��λ�ã���Ϊ�����ڻ�����ʱʳ��ʱ��Ҫ������x,y�Ƚϣ�Ҳ���ǲ�ͬ�������ͨʳ���ظ���
        y = tmp_y;
        SetCursorPosition(x,y);
        //SetCursorPosition(tmp_x,tmp_y);
        SetColor(13);
        std::cout<<"��";//���ǵ���ɫ
        ++cnt;
        cnt%=5;
        if(cnt == 0)
        {
            //ÿ�Ե�5��ʳ��ͻ������ʱʳ��
            DrawBigFood(csnake);
        }
        break;
    }
}
void Food::DrawBigFood(Snake& csnake)//������ʱʳ��
{
    SetCursorPosition(5,0);
    SetColor(11);
    std::cout<<"------------------------------------------" ;//������
    progress_bar = 42;//�������ķ���
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
        std::cout << "��" ;
        big_flag = true;//����ʱʳ��
        flash_flag = true;//��ʱʳ����˸
        break;
    }
}

void Food::FlashBigFood()//��˸��ʱʳ��
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
        std::cout<<"��" ;
        flash_flag = true;
    }//���if,else,��������˸��
    SetCursorPosition(26,0);
    SetColor(11);
    for(int i=42;i>= progress_bar;--i)
        std::cout<<"\b\b";//��Ϊprogress_barһֱ�ڱ䣬������ʾ����������һֱ�ڶ�����������progress_bar�Ǹ�λ��
    --progress_bar;
    if(progress_bar == 0)
    {
        //ʱ�������ˣ����ÿո���Ǹ���ʱʳ�︲�ǵ�
        SetCursorPosition(big_x,big_y);
        std::cout<<"  ";
        SetCursorPosition(5,0);
        std::cout<<"                                          " ;//�ÿո�ȥ��������
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



