#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "map.h"
#include "snake.h"
#include "food.h"

using namespace std;

void Controller::Start()//��ʼ����
{

    SetWindowSize(41, 32);//���ô��ڴ�С
    SetColor(2);//���ÿ�ʼ������ɫ��2��Ӧ�ߵ���ɫ��Ҳ������ɫ
    StartInterface *start = new StartInterface();//��̬����һ��StartInterface��start,
    //new StartInterface() : ��Ϳ�ʼ�������
    start->Action();//��ʼ����
    delete start;//�ͷ��ڴ�ռ�

    /*���ùر�λ�ã��������ʾ��ȴ�������������*/
    //���� "�밴���������"   ��system("pause")����Ч��
    SetCursorPosition(13, 26);
    std::cout << "Press any key to start... " ;//
    SetCursorPosition(13, 27);
    system("pause");//��ͣ���ڣ����û��������û�������Start()�����ͽ�����-��Select()����
}

void Controller::Select()//ѡ�����
{

    //��ʼ������ѡ��->>>>>>> ����
    SetColor(3);//������ɫ
    SetCursorPosition(13, 26);
    std::cout << "                          " ;
    SetCursorPosition(13, 27);
    std::cout << "                          " ;//��SNAKE ������,����Ϊ�˸��ǵ���ʼ�����"�밴���������"����������
    SetCursorPosition(6, 21);
    std::cout << "��ѡ����Ϸ�Ѷȣ�" ;
    SetCursorPosition(6, 22);
    std::cout << "(���¼�ѡ��,�س�ȷ��)" ;

    SetCursorPosition(27, 22);
    SetBackColor();//��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
    std::cout << "��ģʽ" ;

    SetCursorPosition(27, 24);
    SetColor(3);//SetColor(3)���Թ������������ı���ɫ
    std::cout << "��ͨģʽ" ;
    SetCursorPosition(27, 26);
    std::cout << "����ģʽ" ;
    SetCursorPosition(27, 28);
    std::cout << "����ģʽ" ;
    SetCursorPosition(0, 31);
    score = 0;

    //���·����ѡ��ģ��
    int ch;//��¼����ֵ
    key = 1;//��¼ѡ�����ʼѡ���һ��
    bool flag = false;//��¼�Ƿ����Enter����ǣ���ʼ��Ϊ��
    while ((ch = getch()))
    {
        switch (ch)//��������
        {
        case 72://UP�Ϸ����
            if (key > 1)//����ʱѡ����Ϊ��һ��ʱ��UP�Ϸ������Ч
            {
                switch (key)
                {
                case 2:
                    //cout<<"case 22 "<<key<<endl;
                    //��2��ʱ��up������1��Ҳ����ѡ�С���ģʽ��
                    //����ͬ��
                    SetCursorPosition(27, 22);//����ѡ�������ñ���ɫ
                    SetBackColor();
                    std::cout << "��ģʽ" ;

                    SetCursorPosition(27, 24);//����ѡ����ȡ���ұ���ɫ
                    SetColor(3);
                    std::cout << "��ͨģʽ" ;

                    --key;
                    break;
                case 3:
                    //cout<<"case 33 "<<key<<endl;
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "��ͨģʽ" ;

                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "����ģʽ" ;

                    --key;
                    break;
                case 4:
                    //cout<<"case 44 "<<key<<endl;
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "����ģʽ" ;

                    SetCursorPosition(27, 28);
                    SetColor(3);
                    std::cout << "����ģʽ" ;

                    --key;
                    break;
                }
            }
            break;

        case 80://DOWN�·����
            if (key < 4)
            {
                //cout<<key<<endl;
                switch (key)
                {
                case 1:
                    //��ʵ�������»��ƣ��Ѽ�ģʽ��ԭSetColor(3),����ͨģʽѡ��,SetBackColor()
                    //��key = 1 ��ʱ�򣬰�down, �Żᵽ����ͨģʽ������˽���ͨģʽ ��Ϊѡ��
                    //���½�ͬ��
                    SetCursorPosition(27, 24);
                    SetBackColor();
                    std::cout << "��ͨģʽ" ;
                    SetCursorPosition(27, 22);
                    SetColor(3);
                    std::cout << "��ģʽ" ;

                    ++key;
                    break;
                case 2:
                    //cout<<"case 2 "<<key<<endl;
                    SetCursorPosition(27, 26);
                    SetBackColor();
                    std::cout << "����ģʽ" ;
                    SetCursorPosition(27, 24);
                    SetColor(3);
                    std::cout << "��ͨģʽ" ;

                    ++key;
                    break;
                case 3:
                    //cout<<"case 3 "<<key<<endl;
                    SetCursorPosition(27, 28);
                    SetBackColor();
                    std::cout << "����ģʽ" ;
                    SetCursorPosition(27, 26);
                    SetColor(3);
                    std::cout << "����ģʽ" ;

                    ++key;
                    break;
                }
            }
            break;

        case 13://Enter�س���
            flag = true;
            break;
        default://��Ч����,�ͼ����ж��µ����밴��
            break;

        }//switch ����
        if (flag) break;//����Enter�س���ȷ�ϣ��˳��������ѭ��

        SetCursorPosition(0, 31);//������������½ǣ�����ر���˸Ӱ����Ϸ����
    }//while������Ҳ����ѡ���Ѷ�ģʽ��up,down ����

    //������ѡ�Ѷȣ����Ӧһ��key,����key��ֵ��ѡ����Ӧ�Ѷȵ��ٶ�
    switch (key)//������ѡѡ�������ߵ��ƶ��ٶȣ�speedֵԽС���ٶ�Խ��
    {
    case 1:
        speed = 135;
        break;
    case 2:
        speed = 100;
        break;
    case 3:
        speed = 60;
        break;
    case 4:
        speed = 30;
        break;
    default:
        break;
    }
    //����ѡ��-��>>>>> DrawGame();
}

void Controller::DrawGame()//������Ϸ����
{
    //����
    system("cls");//����

    //���Ƶ�ͼ-������
    SetColor(3);
    Map *init_map = new Map();
    init_map->PrintInitmap();
    delete init_map;

    //���Ʋ�������ұ�-������������
    SetColor(3);
    SetCursorPosition(33, 1);
    std::cout << "Greedy Snake" ;
    SetCursorPosition(34, 2);
    std::cout << "̰����" ;
    SetCursorPosition(31, 4);
    std::cout << "�Ѷȣ�" ;
    SetCursorPosition(36, 5);
    switch (key)
    {
    case 1:
        std::cout << "��ģʽ" ;
        break;
    case 2:
        std::cout << "��ͨģʽ" ;
        break;
    case 3:
        std::cout << "����ģʽ" ;
        break;
    case 4:
        std::cout << "����ģʽ" ;
        break;
    default:
        break;
    }
    SetCursorPosition(31, 7);
    std::cout << "�÷֣�" ;
    SetCursorPosition(37, 8);
    std::cout << "     0" ;//��ʼΪ0
    SetCursorPosition(33, 13);
    std::cout << " ������ƶ�" ;
    SetCursorPosition(33, 15);
    std::cout << " ESC����ͣ" ;
}

int Controller::PlayGame()//��Ϸ����ѭ��
{
    /*��ʼ���ߺ�ʳ��*/
    Snake *csnake = new Snake();
    Food *cfood = new Food();
    SetColor(6);
    csnake->InitSnake();//��ӡ��ʼ����
    srand((unsigned)time(NULL));//������������ӣ����û�� ʳ��ĳ���λ�ý���̶�
    cfood->DrawFood(*csnake);//�������food������ָ����Ķ���

    /*��Ϸѭ��*/

    while (csnake->OverEdge() && csnake->HitItself()) //�ж��Ƿ�ײǽ��ײ���������Ƿ�������
    {
        //����ѡ��˵�->>>����

        if (!csnake->ChangeDirection()) //��Esc��ʱ
        {
            int tmp = Menu();//���Ʋ˵������õ�����ֵtmp�ķ���ֵ:1,2,3
            switch (tmp)
            {
            case 1://������Ϸ
                break;

            case 2://���¿�ʼ
                delete csnake;
                delete cfood;
                return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ

            case 3://�˳���Ϸ
                delete csnake;
                delete cfood;
                return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ

            default:
                break;
            }
        }

        //��Ȼһ��ʼ�ǳԲ���ʳ��ģ�����-��NormalMove(),Ҳ�ͽ����ߵ��ƶ�
        if (csnake->GetFood(*cfood)) //�Ե�ʳ�����ָ����Ķ���
        {
            //����
            csnake->Move();//������
            UpdateScore(1);//���·�����1Ϊ����Ȩ�أ�ÿ�μ���key*10,key�Ƕ�Ӧ�Ѷ�
            RewriteScore();//���»��Ʒ���
            cfood->DrawFood(*csnake);//������ʳ��
        }
        else
        {
            //û����ʳ���Ǿ��ǣ�normalmove
            csnake->NormalMove();//�������ƶ�
        }

        if (csnake->GetBigFood(*cfood)) //�Ե���ʱʳ��
        {
            csnake->Move();
            UpdateScore(cfood->GetProgressBar()/5);//����������ʱʳ�������ȷ��
            RewriteScore();
        }

        if (cfood->GetBigFlag()) //�����ʱ����ʱʳ���˸��
        {
            cfood->FlashBigFood();
        }

        Sleep(speed);//�����ߵ��ƶ�Ч���������ߵĿ���
    }

    /*������*/
    delete csnake;//�ͷŷ�����ڴ�ռ�
    delete cfood;
    int tmp = GameOver();//������Ϸ�������棬��������ѡ��
    switch (tmp)
    {
    case 1:
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
    default:
        return 2;
    }
}

void Controller::UpdateScore(const int& tmp)//���·���
{
    //����
    score += key * 10 * tmp;//���÷���������Ϸ�Ѷȼ����˵Ĳ���tmpȷ��
}

void Controller::RewriteScore()//�ػ����
{
    /*Ϊ���ַ���β�����룬������������Ϊ6λ�����㵱ǰ����λ������ʣ��λ���ÿո�ȫ�����������*/
    //����
    SetCursorPosition(37, 8);
    SetColor(11);
    int bit = 0;
    int tmp = score;
    while (tmp != 0)
    {
        ++bit;
        tmp /= 10;
    }
    for (int i = 0; i < (6 - bit); ++i)
    {
        std::cout << " " ;
    }
    std::cout << score ;
}

int Controller::Menu()//ѡ��˵�
{
    //��������
    /*���Ʋ˵�*///����
    SetColor(11);
    SetCursorPosition(32, 19);
    std::cout << "�˵���" ;
    Sleep(100);//������ʾ��̬Ч��
    SetCursorPosition(34, 21);
    SetBackColor();
    std::cout << "������Ϸ" ;
    Sleep(100);
    SetCursorPosition(34, 23);
    SetColor(11);
    std::cout << "���¿�ʼ" ;
    Sleep(100);
    SetCursorPosition(34, 25);
    std::cout << "�˳���Ϸ" ;
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = getch()))
    {
        //cout<<ch<<endl;
        //�������ɻ�����θ�ֵ����ch������������д����while������ÿ��һ�μ���ʵ��while���������Σ���һ��ֱ��defalut,�ڶ��β�����Ӧ��ѡ��
        //ch = getch();������д��ch = getch()��ʵ�����ã���Ϊ������enter�͵ð�������
        //cout<<ch<<endl;
        switch (ch)
        {
        case 72://UP
            if (tmp_key > 1)
            {
                switch (tmp_key)
                {
                case 2:
                    SetCursorPosition(34, 21);
                    SetBackColor();
                    std::cout << "������Ϸ" ;
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "���¿�ʼ" ;

                    --tmp_key;
                    break;
                case 3:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "���¿�ʼ" ;
                    SetCursorPosition(34, 25);
                    SetColor(11);
                    std::cout << "�˳���Ϸ" ;

                    --tmp_key;
                    break;
                }
            }
            break;

        case 80://DOWN
            if (tmp_key < 3)
            {
                switch (tmp_key)
                {
                case 1:
                    SetCursorPosition(34, 23);
                    SetBackColor();
                    std::cout << "���¿�ʼ" ;
                    SetCursorPosition(34, 21);
                    SetColor(11);
                    std::cout << "������Ϸ" ;

                    ++tmp_key;
                    break;
                case 2:
                    SetCursorPosition(34, 25);
                    SetBackColor();
                    std::cout << "�˳���Ϸ" ;
                    SetCursorPosition(34, 23);
                    SetColor(11);
                    std::cout << "���¿�ʼ" ;

                    ++tmp_key;
                    break;
                }
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }//switch����

        if (flag)
        {
            break;
        }
        SetCursorPosition(0, 31);
    }//while����

    if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
    {
        SetCursorPosition(32, 19);
        std::cout << "      " ;
        SetCursorPosition(34, 21);
        std::cout << "        ";
        SetCursorPosition(34, 23);
        std::cout << "        ";
        SetCursorPosition(34, 25);
        std::cout << "        ";
    }
    return tmp_key;
}

void Controller::Game()//��Ϸһ��ѭ��
{

    Start();//��ʼ����
    while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
    {

        Select();//ѡ�����
        DrawGame();//������Ϸ����
        int tmp = PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp:1,2
        if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
        {
            system("cls");
            continue;
        }
        else//ֻҪ�������¿�ʼ���Ϳ���break�ˣ�������
        {
            break;
        }
    }
}

int Controller::GameOver()//��Ϸ��������
{
    /*������Ϸ��������*/
    Sleep(500);
    SetColor(11);
    SetCursorPosition(10, 8);
    std::cout << "����������������������������������������������������������������������������������������" ;
    Sleep(30);
    SetCursorPosition(9, 9);
    std::cout << " ��               Game Over !!!              ��" ;
    Sleep(30);
    SetCursorPosition(9, 10);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(9, 11);
    std::cout << " ��              ���ź��������              ��" ;
    Sleep(30);
    SetCursorPosition(9, 12);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(9, 13);
    std::cout << " ��             ��ķ���Ϊ��                 ��" ;
    SetCursorPosition(24, 13);
    std::cout << score ;
    Sleep(30);
    SetCursorPosition(9, 14);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(9, 15);
    std::cout << " ��   �Ƿ�����һ�֣�                         ��" ;
    Sleep(30);
    SetCursorPosition(9, 16);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(9, 17);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(9, 18);
    std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��" ;
    Sleep(30);
    SetCursorPosition(9, 19);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(9, 20);
    std::cout << " ��                                          ��" ;
    Sleep(30);
    SetCursorPosition(10, 21);
    std::cout << "��������������������������������������������" ;

    Sleep(100);
    SetCursorPosition(12, 18);
    SetBackColor();
    std::cout << "�ţ��õ�" ;//Ĭ��ѡ�У����ţ��õġ�
    SetCursorPosition(0, 31);

    /*ѡ�񲿷�*/
    int ch;
    int tmp_key = 1;
    bool flag = false;
    while ((ch = getch()))
    {
        switch (ch)
        {
        case 75://LEFT
            if (tmp_key > 1)
            {
                SetCursorPosition(12, 18);
                SetBackColor();
                std::cout << "�ţ��õ�" ;
                SetCursorPosition(20, 18);
                SetColor(11);
                std::cout << "���ˣ�����ѧϰ����˼" ;
                --tmp_key;
            }
            break;

        case 77://RIGHT
            if (tmp_key < 2)
            {
                SetCursorPosition(20, 18);
                SetBackColor();
                std::cout << "���ˣ�����ѧϰ����˼" ;
                SetCursorPosition(12, 18);
                SetColor(11);
                std::cout << "�ţ��õ�" ;
                ++tmp_key;
            }
            break;

        case 13://Enter
            flag = true;
            break;

        default:
            break;
        }//switch����

        SetCursorPosition(0, 31);
        if (flag) {
            break;
        }
    }//while����

    SetColor(11);
    switch (tmp_key)//�ж����¿�ʼ�����ǽ���
    {
    case 1:
        return 1;//���¿�ʼ��Ҳ���ǣ����ţ��õġ�
    case 2:
        return 2;//�˳���Ϸ��Ҳ���ǡ����ˣ�����ѧϰ����˼��
    default:
        return 1;
    }
}


