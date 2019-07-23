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
	//初始化蛇
	void initSnake();
	//删除结点
	void destroySnake();
	//添加结点
	void addSnake(int x,int y);

	//在蛇的移动过程中删除尾结点
	void delpoint();
	//蛇移动
	bool move(char key);
	int getSleepTime();
	int countList();
	int getscore();
	WALL& wall;
	food& food1;
	bool isrool;
};