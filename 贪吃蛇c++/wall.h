#ifndef _WALL_H_
#define _WALL_H_
#include<iostream>
using namespace std;
class WALL
{
public:
	enum {LONG = 26,WIND = 26};
	void initWall();          //初始化墙
	void drawWall();          //打印墙壁
	void setWall(int a, int b, char c);           //对外提供接口设置蛇的位置
	char getWALL(int a, int b);           //打印蛇的位置
private:
	char wall[LONG][WIND];
};

#endif