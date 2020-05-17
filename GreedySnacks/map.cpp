#include "map.h"
#include <windows.h>

void Map::PrintInitmap()//绘制初始地图
{
    //懂啦，构造四面的地图
    for (auto& point : initmap)
    {
        point.Print();
        Sleep(10);//调用Sleep函数可营造动画效果
    }
}
