#include"food.h"
#include<windows.h>
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
void gotoxy2(HANDLE hOut2, int x, int y)//����x��y������������෴�ģ�ע������
{
	COORD pos;
	pos.X = x;             //������	
	pos.Y = y;            //������	
	SetConsoleCursorPosition(hOut2, pos);
}//��궨λ����
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
