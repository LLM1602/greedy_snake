#include "startinterface.h"
#include <windows.h>

void StartInterface::PrintFirst()//�ߴ���߳��ֵ���ȫ���ֵĹ���,
{
    //������
    for(auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);//sleep():��ʱ��ִ�й���һ��ʱ�䣬Ҳ���ǵȴ�һ��ʱ���ڼ���ִ�У���
        //�������������ƶ��˵�Ч������Ϊֱ�Ӵ�ӡ�㣬̫���ˣ�һ����ȫ��������ˣ�ͨ��Sleep()����ʱ��ӡ���ͺ����ڶ�
    }
}

//���漸������Ҫ�ú����
void StartInterface::PrintSecond()//�ߴ��������ƶ��Ĺ���
{
    //����
    for(int i=10;i!=40;++i)//��ͷ��Ҫ��10 �ƶ���40,��Ϊ��Ļ���þ���41*32,
    {
        /*������ͷ����һ��λ�ã�������ѹ��startsnake�У����Ƴ���������βȥ��*/
        int j = ( ((i-2)%8) < 4 ) ? (15 + (i-2)%8) : (21-(i-2)%8);
        //15+(i-2)%8 :���½�
        //21-(i-2)%8 :������
        startsnake.emplace_back(Point(i,j));//˫�˶��У�������еĺ��棬ʵ��������Ļ������ͷ��Ҳ�������ҷ�
        startsnake.back().Print();//���һ��Ԫ�ش�ӡ������Ҳ������ͷ��ӡ������
        startsnake.front().Clear();//Ȼ�������Ļ�ϵ�һ���㣬Ҳ������Ļ����ߵģ�����β
        startsnake.pop_front();//�Ӷ�����ɾ��������֤�ߵĳ��Ȳ���
        Sleep(speed);
    }
}

void StartInterface::PrintThird()////�ߴӽӴ��ұߵ���ʧ�Ĺ���
{
    //����
    while ( !startsnake.empty() || textsnake.back().GetX() < 33 ) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if ( !startsnake.empty() ) //����߻�û��ʧ�������ƶ�
        {
            startsnake.front().Clear();//�����Ļ����ߵģ�������ߵĳ���
            startsnake.pop_front();
        }
        ClearText();//����������֣�
        PrintText();//����SNAKE��ʼ��������
        //������ʵ���ǣ��Ȱ���ʾ�����֣�ֱ���ÿո������������ClearText()ʱ���Ѿ���ʾ�����ֻᱻ�ո���棬���һ���������������ƶ�һ��
        Sleep(speed);
    }
}
void StartInterface::PrintText()
{
    //����
    for (auto& point : textsnake)
    {
        if (point.GetX() >= 0)
            point.Print();//ֻ��ʾX����0��λ��
    }
}
void StartInterface::ClearText()
{
    //����
    for (auto& point : textsnake) //������Ļ����ʾ�����֣�SNAKEȫ�ÿո񸲸ǣ����Ǻ��ٰ����еĵ�������һ��
    {
        if (point.GetX() >= 0)
            point.Clear();//����Ѿ���ʾ�����֣�Ҳ����x>=0 ������
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}



