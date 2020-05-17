#ifndef CONTROLLER_H
#define CONTROLLER_H


class Controller
{
public:
    Controller() : speed(1), key(1), score(0) {}
    void Start();//��Ϸ��ʼ����
    void Select();//ѡ��ͬ�Ѷȣ���Ӧ�ͻ��в�ͬkeyֵ����ͬkeyֵ�ͻ��Ӧ�в�ͬspeed(���ƶ��ٶ�)
    void DrawGame();//������Ϸ����
    int PlayGame();//����Ϸ
    void UpdateScore(const int& score);//���·���
    void RewriteScore();//��������ķ������뵽��Ļ�ϣ�ע���Ҷ���ĸ�ʽ
    int Menu();//����ESC�����ǲ˵�ѡ��
    void Game();//������Ϸ���
    int GameOver();//������Ϸ�����Ľ���
private:
    int speed;//���ƶ��ٶ�
    int key;//��Ӧѡ���Ѷ�
    int score;//��÷���
};
#endif // CONTROLLER_H
