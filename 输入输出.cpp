#if 0
//cin.get()һ��ֻ�ܶ�ȡһ���ַ�
//cin.get(һ������)��һ���ַ�
//cin.get(��������)���Զ��ַ���
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
//cin.get(��������)����ѻ������еĻ��з����ߣ�Ҳ����˵���з����ڻ�����֮��
void test2()
{
	char buf[1024];
	cin.get(buf, 1024);         //�ȴ�����һ���ַ���
	cout << buf << endl;
	//���ڻ��з��Ƿ��ڻ�����֮����������ȡһ��
	char c = cin.get();   //����������������ݾʹӻ������ж�ȡһ���ַ�
	if (c == '\n')
	{
		cout << "���з����ڻ�����\n";
	}
}
//һ������
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
	cin.getline(buf,1024); //cinϵ�к�������˼���Ǵӻ�������ȡ��󳤶ȵ��ַ���ֻ�Ƕ�ȡ����û������Ļ��������
	char c;
	c = cin.get();
	if (c == '\n')
	{

		cout << "���з����ڻ�����\n";
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
	char c = cin.peek();     //͵�����ӻ�����͵��һ���ַ������ó���
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