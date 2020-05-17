#ifndef CONTROLLER_H
#define CONTROLLER_H


class Controller
{
public:
    Controller() : speed(1), key(1), score(0) {}
    void Start();//游戏开始界面
    void Select();//选择不同难度，对应就会有不同key值，不同key值就会对应有不同speed(蛇移动速度)
    void DrawGame();//绘制游戏界面
    int PlayGame();//玩游戏
    void UpdateScore(const int& score);//更新分数
    void RewriteScore();//将更新完的分数输入到屏幕上，注意右对齐的格式
    int Menu();//按下ESC键后是菜单选项
    void Game();//整个游戏入口
    int GameOver();//绘制游戏结束的界面
private:
    int speed;//蛇移动速度
    int key;//对应选择难度
    int score;//获得分数
};
#endif // CONTROLLER_H
