#include"wall.h"
void WALL::initWall()
{
	for (int i = 0; i < LONG; ++i)
	{
		for (int j = 0; j < WIND; ++j)
		{
			if (i == 0 || j == 0 || i == LONG - 1 || j == WIND - 1)
				wall[i][j] = '*';
			else
				wall[i][j] = ' ';
		}
	}
}
void WALL::drawWall()          //打印墙壁
{
	for (int i = 0; i < LONG; ++i)
	{
		for (int j = 0; j < WIND; ++j)
		{
			cout << wall[i][j] << ' ';
		}
		cout << endl;
	}
}
void WALL::setWall(int a,int b,char c)           //对外提供接口设置蛇的位置
{
	wall[a][b] = c;
}
char WALL::getWALL(int a,int b)           //打印蛇的位置
{
	return wall[a][b];
}