#pragma once
#include<iostream>
#include"wall.h"
using namespace std;
class food
{
public:
	food(WALL& wall);
	void setfood();

	int foodX;
	int foodY;
	WALL& wall;
};