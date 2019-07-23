#include<iostream>
using namespace std;
#include<time.h>
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<conio.h>
#include<windows.h>
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标	
	SetConsoleCursorPosition(hOut, pos);
}//光标定位函数
//游戏入口
int main()
{
	

	bool isdead = false;
	char poor = NULL;
	srand((unsigned int)time(NULL));
	WALL p;
	p.initWall();     //画墙
	p.drawWall();     //打印
	food v(p);
	v.setfood();
	snake s(p,v);
	s.initSnake();

	gotoxy(hOut, 0, WALL::LONG);
	cout << "得分：" << s.getscore() << endl;
	while (!false)
	{
		char key = _getch();
		if (poor ==NULL && key == s.LEFT)
		{
			continue;
		}
		
		do
		{
			if (key == s.LEFT || key == s.UP || key == s.RIGHT || key == s.DOWN)
			{
				if ((key == s.LEFT &&poor == s.RIGHT) ||
					(key == s.UP &&poor == s.DOWN) ||
					(key == s.RIGHT &&poor == s.LEFT) ||
					(key == s.DOWN &&poor == s.UP))
				{
					key = poor;
				}
				poor = key;
				if (s.move(key) == true)
				{
					//system("cls");
					//p.drawWall();
					gotoxy(hOut, 0,WALL::LONG);
					cout << "得分：" << s.getscore() << endl;
					Sleep(s.getSleepTime());
				}
				else
				{
					isdead = true;
					break;
				}
			}
			else
			{
				key = poor;
			}
			
		} while (!_kbhit());
	}
	return 0;
}