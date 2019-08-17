/*
#include<iostream>
using namespace std;
void MYprintf(int a[4][4],int x1,int y1,int x2,int y2)    //��������ǵĴ�ӡ����������������ӡ���������ĸ��㣬��������������㣬һ�������Ͻǣ�һ�������½�
{
	int COL_1 = x1;         //���������ĸ���������¼�ĸ����㣬���������εľ����ʱ����Բ���������������¼����Ϊx��y����ȵ�
	int COL_2 = x2;         //���������������ĸ�����������Ϊ���Խ��ܲ��������εľ���
	int ROW_1 = y1;
	int ROW_2 = y2;
	if (x1 > x2)    //����һ���жϣ�����󶥵�����Ҷ���
		return;
	if (x1 == x2)       //��������ô����˵��һ�У���ôֻ��Ҫ����һ�д�ӡ�����Ϳ�����
		for (int i = COL_1; COL_1 <= y2; ++i)
			cout << a[x1][i] << endl;
	else         //����Ļ�����תȦ��ӡ��ÿ�δ�ӡ����ӡ�����һ����ʱ��ֹͣ����ӡ
	{
		while (ROW_1 != ROW_2){
			cout << a[COL_1][ROW_1] << endl;
			ROW_1++;
		}
		ROW_1 = x1;             //��ӡ��֮���ٻ�ԭ��ȥ
		while (COL_1 != COL_2){
			cout << a[COL_1][ROW_2] << endl;
			COL_1++;
		}
		COL_1 = x1;            //��ӡ��֮���ٻ�ԭ��ȥ
		while (ROW_2 != ROW_1){
			cout << a[COL_2][ROW_2] << endl;
			ROW_2--;
		}
		ROW_2 = y2;              //��ӡ��֮���ٻ�ԭ��ȥ
		while (COL_2 != COL_1){
			cout << a[COL_2][ROW_1] << endl;
			COL_2--;
		}
		COL_2 = x2;        //��ӡ��֮���ٻ�ԭ��ȥ
	}
	MYprintf(a,++x1, ++y1, --x2, --y2);      //����֮���ٴ��ڲ�����һȦ
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





















