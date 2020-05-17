#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"
class Food;
class Snake
{
public:
    enum Direction{UP,DOWN,LEFT,RIGHT};//enum :����ö�ٱ���
    Snake(){
        //�ʼ�ߵĴ�С�Լ�����
        snake.emplace_back(14,8);
        snake.emplace_back(15,8);
        snake.emplace_back(16,8);
        direction = Direction::DOWN;//��ʼѡ������һ������ɣ�direction���ǣ�down
    }
    void InitSnake();//��ʼ����
    void Move();//�߳Ե�ʳ�����
    void NormalMove();//��û�Ե�ʳ��ʱ�������ƶ�
    bool OverEdge();//�ж����Ƿ�ײ���߽�
    bool HitItself();//�ж��Ƿ�ײ���Լ�
    bool ChangeDirection();//�ı䷽�������жϷ����Ƿ�ı䣬����direction��ֵ�ı䣬
    bool GetFood(const Food& food);//�Ե�ʳ��
    bool GetBigFood(Food& food);//�Ե���ʱʳ��
private:
    std::deque<Point>snake;//˫�˶���,������vector�Ĺ���
    Direction direction;
    friend class Food;//��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
};
#endif // SNAKE_H

