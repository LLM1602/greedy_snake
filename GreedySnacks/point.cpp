#include "point.h"
#include "tools.h"
#include <iostream>


void Point::Print()//�������
{
    //����
    SetCursorPosition(x,y);
    std::cout<<"��" ;//Alt+41462��һ������ռ2���ֽڣ�
}

void Point::PrintCircular()//���ͼ��
{
    //��������ӡ��
    SetCursorPosition(x,y);
    std::cout<<"��";//��
}
void Point::Clear()//������
{
    //���ˣ�
    SetCursorPosition(x,y);//���(x,y)����㣬���������������ͨ�����ǣ��ÿո�������ԭ���ĵ�
    std::cout<<"  ";//�˴��������ո���Ϊ����ռ��2���ֽڵ�
}
void Point::ChangePosition(const int x,const int y)//�ı�����
{
    //����
    this->x = x;
    this->y = y;
}


