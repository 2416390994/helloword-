#if 0
//cin.get()一次只能读取一个字符
//cin.get(一个参数)读一个字符
//cin.get(两个参数)可以读字符串
//cin.getline()
//cin.ignore()
//cin.peek()
//cin.putback()
#include<iostream>
using namespace std;
void test()
{
	char c = cin.get();
	cout << "c =" << c << endl;
	c = cin.get();
	cout << "c =" << c << endl;
	c = cin.get();
	cout << "c =" << c << endl;
	c = cin.get();
	cout << "c =" << c << endl;
}
//cin.get(两个参数)不会把缓冲区中的换行符拿走，也就是说换行符还在缓冲区之中
void test2()
{
	char buf[1024];
	cin.get(buf, 1024);         //等待输入一个字符串
	cout << buf << endl;
	//关于换行符是否还在缓冲区之中我们来读取一下
	char c = cin.get();   //如果缓冲区中有数据就从缓冲区中读取一个字符
	if (c == '\n')
	{
		cout << "换行符还在缓冲区\n";
	}
}
//一个参数
void test3()
{
	char ch;
	cin.get(ch);
	cout << ch;
	cin.get(ch);
	cout << ch;
}
void test4()
{
	char buf[1024];
	cin.getline(buf,1024); //cin系列函数的意思都是从缓冲区读取多大长度的字符，只是读取，你没让输出的话不会输出
	char c;
	c = cin.get();
	if (c == '\n')
	{

		cout << "换行符还在缓冲区\n";
	}
}
void test5()
{
	cin.ignore();
	char c = cin.get();
	cout << c << endl;
}
void test6()
{
	char c = cin.peek();     //偷窥，从缓冲区偷窥一个字符但不拿出来
	cout << c << endl;
	char b = cin.get();
	cout << b << endl;
}
void test7()
{
	char c = cin.get();
	cout << c << endl;
	cin.putback(c);
	char buf[1024];
	cin.get(buf, 1024);
	cout << buf << endl;
}
int main()
{
	test7();
	return 0;
}
#endif