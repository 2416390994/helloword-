#include<iostream>
using namespace std;
//int func()
//{
//	return 0;
//}
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48    ������   ������Ԫ�صĵ�ַ����sizeof��������������������Ԫ�أ����������������Ԫ�� 
//	printf("%d\n", sizeof(a[0][0]));//4��  a[0][0]��ֵ 
//	printf("%d\n", sizeof(a[0]));//16       һά������   �����0�е�Ԫ�� 
//	printf("%d\n", sizeof(a[0] + 1));//4           .a[0][1]�ĵ�ַ 
//	printf("%d\n", sizeof(a + 1));//4.          ��2�еĵ�ַ 
//	printf("%d\n", sizeof(&a[0] + 1));//4     ��2�еĵ�ַ 
//	printf("%d\n", sizeof(*a));//16.      a����������Ԫ�صĵ�ַ������һ�еĵ�ַ�������ֵΪ��һ�е�Ԫ�ش�С 
//	printf("%d\n", sizeof(a[3]));//16 
//	return 0;
//}

int x;
int y;
int addtwonum()
{
	// �������������� x �� y Ϊ�ⲿ����
	//extern int x;
	//extern int y;
	//int x;
	//int y;
	// ���ⲿ������ȫ�ֱ�����x �� y ��ֵ
	x = 1;
	y = 2;
	cout << x << endl;
	cout << y << endl;
	return x + y;
}

int main()
{
	
	int result;
	// ���ú��� addtwonum
	result = addtwonum();
	cout << ::x << endl;
	cout << ::y << endl;
	printf("result Ϊ: %d", result);
	return 0;
}

