/*
#include<iostream>
using namespace std;
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int a, b, c, d;
	int(*p)(int, int);
	p = max;
	cin >> a >> b >> c;
	d = (*p)((*p)(a, b), c);
	cout << d << endl;
	return 0;
}
*/
/*
#include<stdio.h>
#include<iostream>
int main()
{
	int a[5] = { 2, 5, 4, 7, 5 };
	int * p = a;
	printf("%d\n", (a + 1));
	printf("%d\n", (p + 1));
	printf("%d\n", (++p));
	printf("%d\n", a);
	//printf("%d\n", a++);´íÎó

	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
	int *a = nullptr;
	int *b = nullptr;
	int *c = nullptr;
	int *d = nullptr;
	int *e = nullptr;
	int _1 = 1;
	int _2 = 2;
	int _3 = 3;
	int _4 = 4;
	int _5 = 5;
	int* p[5];
	/*int *a = &_1;
	int *b = &_2;
	int *c = &_3;
	int *d = &_4;
	int *e = &_5;*/
	/*
	a = &_1;
	b = &_2;
	c = &_3;
	d = &_4;
	e = &_5;
	
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;
	p[4] = e;
	cout << *p[0] << *p[1] << *p[2] << *p[3] << *p[4] << endl;
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
	int *a[2];
	int *p1, *p2;
	int b = 1, c = 2;
	p2 = &c;
	a[0] = &b;
	a[1] = p2;
	cout << *a[0] << *a[1] << endl;
	cout << *p2;
	return 0;
}
*/
/*
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int(*A)[3],(*B)[3];
	int p = 5, p2 = 6;
	int text[2][3] = { { 1, 2, 3 },{ 4, 5, 6 } };
	int text2[3] = { 1, 2, 3 };
	A = &text[1];
	B = &text2;
	cout << (*A)[0] << (*A)[1] << (*A)[2] << endl;
	cout << (*A) << endl;
	cout << (A[0]) << endl;
	cout << (*B)[2] << endl;
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main()
{
	unsigned short *p = new unsigned short;
	*p = 10;
	delete p;
	p = nullptr;
	long *plong = new long;
	*plong = 90000;
	cout << *plong << endl;
	*p = 20;
	cout << *p << endl;
	cout << *plong << endl;
	//delete p;
	return 0;
}
*/
















