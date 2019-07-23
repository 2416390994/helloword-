#include"food.h"
#include<windows.h>
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
void gotoxy2(HANDLE hOut2, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标	
	pos.Y = y;            //纵坐标	
	SetConsoleCursorPosition(hOut2, pos);
}//光标定位函数
void food::setfood()
{
	while (1)
	{
		foodX = rand() % (WALL::LONG - 2) + 1;
		foodY = rand() % (WALL::WIND - 2) + 1;
		if (wall.getWALL(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			gotoxy2(hOut2, foodY * 2, foodX);
			cout << "#";
			break;
		}			
	}
}
food::food(WALL& temp) :wall(temp)
{}
