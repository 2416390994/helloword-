#ifndef _WALL_H_
#define _WALL_H_
#include<iostream>
using namespace std;
class WALL
{
public:
	enum {LONG = 26,WIND = 26};
	void initWall();          //��ʼ��ǽ
	void drawWall();          //��ӡǽ��
	void setWall(int a, int b, char c);           //�����ṩ�ӿ������ߵ�λ��
	char getWALL(int a, int b);           //��ӡ�ߵ�λ��
private:
	char wall[LONG][WIND];
};

#endif