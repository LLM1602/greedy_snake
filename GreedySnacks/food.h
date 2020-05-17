#ifndef FOOD_H
#define FOOD_H
#include "snake.h"
class Snake;
class Food
{

private:
    int cnt;//��¼�����Ե����ٴ�ʳ���ˣ����˵���ξͳ�����ʱʳ�������0
    bool flash_flag;//��˸���
    bool big_flag;//�Ƿ�����ʱʳ����
    int x,y;//ʳ���λ��
    int big_x,big_y;//��ʱʳ�������
    int progress_bar;//��ʱʳ����������������ƼӶ��ٷֵ�
    friend class Snake;//������Ԫ�����Է���˽��Ԫ��
public:
    Food():cnt(0),flash_flag(false),big_flag(false),x(0),y(0),big_x(0),big_y(0),progress_bar(0){}
    void DrawFood(Snake& snake);//����Ĳ��������ݵ���Snake�Ķ���
    void DrawBigFood(Snake& snake);//����Ĳ��������ݵ���Snake�Ķ���
    void FlashBigFood();//��˸��ʱʳ��
    bool GetBigFlag();//�Ƿ�����ʱʳ�����
    int GetProgressBar();//���سԵ���ʱʳ��Ӧ�õķ���
};
#endif // FOOD_H
