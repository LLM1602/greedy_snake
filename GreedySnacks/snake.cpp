#include "snake.h"
#include <conio.h>
#include "tools.h"
#include <iostream>
using namespace std;
void Snake::InitSnake()//��ʼ����
{
    //��ӡ�ʼ����
    for(auto& point : snake)
        point.PrintCircular();
}

void Snake::Move()//������
{
    //����
    //cout<<"move "<<direction<<endl;
    switch(direction)//�ǶԵģ�back()��ͷ��
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
    snake.back().PrintCircular();//�����µ��ߵ�ͷ��
}

void Snake::NormalMove()//�������ƶ���ͷ������β����
{
    //cout<<"normalmove "<<direction<<endl;
    Move();//
    snake.front().Clear();//front()��Ӧ����β��
    snake.pop_front();//

}
bool Snake::OverEdge()//�����߽�
{
    //����
    //snack.back()�����ߵ�ͷ��
    return snake.back().GetX() <30 &&snake.back().GetY() <30 &&
           snake.back().GetX() >1  &&snake.back().GetY() >1;
}
bool Snake::HitItself()//ײ���Լ�
{
    std::deque<Point>::size_type cnt = 1;
    Point *head = new Point(snake.back().GetX(),snake.back().GetY());//?�ⲻ��β��Ԫ���𰡣�-��������ͷ
    for(auto& point:snake)//????���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������
    {
        if(!(point == *head))
            cnt++;
        else
            break;
    }
    delete head;
    if(cnt == snake.size())//Ӧ����size()-1
        return true;
    else
        return false;

}
bool Snake::ChangeDirection()//�ı䷽��
{
    //�����ߵķ��򣬶���
    //char ch;
    //cout<<"changeDirction "<<direction<<endl;
    int ch;
    if(kbhit())//kbhit():����Ƿ��м�������,�з��ط�0���޷���0
    {
        ch = getch();//getch():���û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س�
        //����getch��������ͷ�ļ�conio.h������������Ҽ��ļ�ֵʱ��������˫��ֵ���᷵�ظ߰�λ�͵Ͱ�λ��int����ֵ��
        //����getch():�ȶ�ǰ8λ���������ҵ�ǰ8λ��ֵ�� �޷���ֵ224����Ӧ�з���ֵ��-32����int :��һ�ξ���224���ڶ��ξ��ǣ�72����char :ֻ��8λ�������з��ţ�-32
        //�����������ȥ��
//        char ch;
//        while((ch=getch())!=0x1B) /* ESC to quit */
//        {
//            printf("%d \n", ch);
//        }
        switch(ch)
        {

        case 224://
            ch = getch();//�����ٶ�ȡ���λ��
            //printf("22 %d\n",ch);
            switch(ch)
            {
            case 72://up
                if(direction != Direction::DOWN)//�ж���Ҫ�ƶ�������ԭ���˶������Ƿ��෴���෴����Ч
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
        case 27://esc:����esc:0x1B->Ҳ����27
            return false;
        default:
            return true;
        }
    }
    return true;
}
bool Snake::GetFood(const Food& cfood)
{
    //����
    if(snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
        return true;
    else
        return false;
}
bool Snake::GetBigFood(Food& cfood)//�Ե���ʱʳ��
{
    if(snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
    {
        cfood.big_flag = false;//��ʱʳ����Ϊfalse
        cfood.big_x = 0;
        cfood.big_y = 0;//��ԭ
        SetCursorPosition(1, 0);//�Դ��ˣ�ҲҪ�ѽ��������
        std::cout << "                                                            " ;//���������
        return true;
    }
    else
        return false;
}




































