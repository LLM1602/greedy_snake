#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines)//���ô��ڴ�С
{
    //����
    system("title ̰����");//���ô��ڱ��⣬�ڿ����Ͻǻ���ʾ̰����,�̶��ġ�title+....."
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    system(cmd);//system(mode con cols=88 lines=88)�����ô��ڿ�Ⱥ͸߶�,�̶��Ŀ⺯���Լ�д��
}

void SetCursorPosition(const int x, const int y)//���ù��λ��,�൱���Ǹ��ӿڣ���Ҫ����windows�� �ĺ�����SetConsoleCursorPosition
{
    //����
    COORD position;//COORD:�̶��Ľṹ���������������ԱX,Y
    position.X = x * 2 ;//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    //��ֱ�Ӽ�ס���ɡ�
    //GetStdHandle(STD_OUTPUT_HANDLE)����׼�������ľ��
    //SetConsoleCursorPosition:��д�����֮ǰ������ƶ�������λ�ã���(x,y)��λ��m
}

void SetColor(int colorID)//�����ı���ɫ
{
    //����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
    //GetStdHandle(STD_OUTPUT_HANDLE)���̶�������
    //
}

void SetBackColor()//�����ı�����ɫ
{
    //����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
}

