/*
#include<iostream>
using namespace std;
void MYprintf(int a[4][4],int x1,int y1,int x2,int y2)    //这个是我们的打印函数，我们用来打印，传入了四个点，代表的是两个顶点，一个是左上角，一个是右下角
{
	int COL_1 = x1;         //这里用了四个变量来记录四个顶点，在是正方形的矩阵的时候可以采用两个变量来记录，因为x，y是相等的
	int COL_2 = x2;         //但是这里我用了四个变量，是因为可以接受不是正方形的矩阵
	int ROW_1 = y1;
	int ROW_2 = y2;
	if (x1 > x2)    //这是一个判断，如果左顶点低于右顶点
		return;
	if (x1 == x2)       //如果相等那么就是说是一行，那么只需要把这一行打印出来就可以了
		for (int i = COL_1; COL_1 <= y2; ++i)
			cout << a[x1][i] << endl;
	else         //否则的话就是转圈打印，每次打印，打印到最后一个的时候停止不打印
	{
		while (ROW_1 != ROW_2){
			cout << a[COL_1][ROW_1] << endl;
			ROW_1++;
		}
		ROW_1 = x1;             //打印完之后再还原回去
		while (COL_1 != COL_2){
			cout << a[COL_1][ROW_2] << endl;
			COL_1++;
		}
		COL_1 = x1;            //打印完之后再还原回去
		while (ROW_2 != ROW_1){
			cout << a[COL_2][ROW_2] << endl;
			ROW_2--;
		}
		ROW_2 = y2;              //打印完之后再还原回去
		while (COL_2 != COL_1){
			cout << a[COL_2][ROW_1] << endl;
			COL_2--;
		}
		COL_2 = x2;        //打印完之后再还原回去
	}
	MYprintf(a,++x1, ++y1, --x2, --y2);      //完了之后再打内部的那一圈
}
int main()
{
	int a[4][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	MYprintf(a, 0, 0, 3, 3);
	return 0;
}
*/
#include<iostream>
using namespace std;
void printfs(int a[3][4], int ROW_1, int COL_1, int ROW_2, int COL_2,bool test)
{
	if (test)
	{
		while (ROW_1 <= ROW_2)
			cout << a[ROW_1++][COL_1--] << endl;
	}
	else
	{
		while (ROW_2 != ROW_1 - 1)
			cout << a[ROW_2--][COL_2++] << endl;
	}
}
void MYprintf(int a[3][4])
{
	int ROW_1 = 0;
	int COL_1 = 0;
	int ROW_2 = 0;
	int COL_2 = 0;
	int ENDR = 2;
	int ENDC = 3;
	bool test = false;
	while (ROW_1 != ENDR + 1)
	{
		printfs(a, ROW_1, COL_1, ROW_2, COL_2, test);
		ROW_1 = (COL_1 == ENDC) ? ROW_1 + 1 : ROW_1;
		COL_1 = (COL_1 == ENDC) ? COL_1 : COL_1 + 1;
		COL_2 = (ROW_2 == ENDR) ? COL_2 + 1 : COL_2;
		ROW_2 = (ROW_2 == ENDR) ? ROW_2 : ROW_2 + 1;
		test = !test;
	}
}
int main()
{
	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	MYprintf(a);
	return 0;
}





















