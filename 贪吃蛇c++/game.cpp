#include<iostream>
using namespace std;
#include<time.h>
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<conio.h>
#include<windows.h>
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
void gotoxy(HANDLE hOut, int x, int y)//����x��y������������෴�ģ�ע������
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������	
	SetConsoleCursorPosition(hOut, pos);
}//��궨λ����
//��Ϸ���
int main()
{
	

	bool isdead = false;
	char poor = NULL;
	srand((unsigned int)time(NULL));
	WALL p;
	p.initWall();     //��ǽ
	p.drawWall();     //��ӡ
	food v(p);
	v.setfood();
	snake s(p,v);
	s.initSnake();

	gotoxy(hOut, 0, WALL::LONG);
	cout << "�÷֣�" << s.getscore() << endl;
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
					cout << "�÷֣�" << s.getscore() << endl;
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