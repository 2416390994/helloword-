#pragma once
#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;
class snake
{
public:
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
	snake(WALL& temp,food& temp2);
	struct point
	{
		int x;
		int y;
		point* next;
	};
	point* head ;
	//��ʼ����
	void initSnake();
	//ɾ�����
	void destroySnake();
	//��ӽ��
	void addSnake(int x,int y);

	//���ߵ��ƶ�������ɾ��β���
	void delpoint();
	//���ƶ�
	bool move(char key);
	int getSleepTime();
	int countList();
	int getscore();
	WALL& wall;
	food& food1;
	bool isrool;
};