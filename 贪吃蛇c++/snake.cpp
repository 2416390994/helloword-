#include"snake.h"
#include"food.h"
#include<windows.h>

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
void gotoxy1(HANDLE hOut1, int x, int y)//����x��y������������෴�ģ�ע������
{	COORD pos;
	pos.X = x;             //������	
	pos.Y = y;            //������	
	SetConsoleCursorPosition(hOut1, pos);
}//��궨λ����


snake::snake(WALL& temp, food& temp2) :wall(temp), food1(temp2)
{
	head = NULL;
	isrool = false;
}
void snake::initSnake()
{
	destroySnake();
	addSnake(5,3);
	addSnake(5,4);
	addSnake(5,5);
}
void snake::destroySnake()
{
	point* cur = head;
	while (head != NULL)
	{
		cur = head->next;
		delete head;
		head = cur;
	}
}
void snake::addSnake(int x, int y)
{
	point* newpoint = new point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;
	if (head != NULL)
	{
		wall.setWall(head->x,head->y, '=');
		gotoxy1(hOut1, head->y * 2, head->x);
		cout << "=";
	}
	newpoint->next = head;
	head = newpoint;
	wall.setWall(head->x, head->y, '@');
	gotoxy1(hOut1, head->y * 2, head->x);
	cout << "@";
}
void snake::delpoint()
{
	if (head == NULL || head->next == NULL )
		return;
	
	point* pcur = head->next;
	point* cur = head;
	while (pcur->next != NULL)
	{
		cur = cur->next;
		pcur = pcur->next;
	}
	wall.setWall(pcur->x, pcur->y, ' ');
	gotoxy1(hOut1, pcur->y * 2, pcur->x);
	cout << " ";
	delete pcur;
	pcur = NULL;
	cur->next = NULL;

}
bool snake::move(char key)
{
	int x = head->x;
	int y = head->y;
	switch (key)
	{
	case UP:
		x--;
		break;
	case LEFT:
		y--;
		break;
	case DOWN:
		x++;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	//�ж������һ����������β�ͣ�ĩ�ң���Ӧ������
	point* pcur = head->next;
	point* cur = head;
	while (pcur->next != NULL)
	{
		cur = cur->next;
		pcur = pcur->next;
	}
	if (pcur->x == x && pcur->y == y)
	{
		isrool = true;
	}
	else
	{
		//�ж��û��ƶ��Ƿ�ɹ�
		if (wall.getWALL(x, y) == '*' || wall.getWALL(x, y) == '=')
		{
			addSnake(x, y);
			delpoint();
			system("cls");
			wall.drawWall();
			cout << "�÷֣�" << getscore() << endl;
			cout << "GAME OVER!" << endl;
			return false;
		}
	}

	
	//�ж��û��Ƿ�Ե�ʳ��
	if (wall.getWALL(x, y) == '#')
	{
		addSnake(x, y);
		//��������ʳ��
		food1.setfood();
	}
	else
	{
		addSnake(x,y);
		delpoint();
		if (isrool == true)
		{
			wall.setWall(x, y, '@');
			gotoxy1(hOut1, y * 2, x);
			cout << "@";
		}
	}
	return true;
}
int snake::getSleepTime()
{
	int sleeptime = 0;
	int size = countList();
	if (size < 5)
	{
		sleeptime = 300;
	}
	else if (size >=5 && size <= 10)
	{
		sleeptime = 200;
	}
	else
	{
		sleeptime = 100;
	}
	return sleeptime;
}
int snake::countList()
{
	int count = 0;
	point* cur = head;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return  count;
}
int snake::getscore()
{
	int size = countList();
	int score = (size - 3) * 100;
	return score;
}