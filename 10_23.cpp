//#include<iostream>
//#include<time.h>
//using namespace std;
//void swap(int& a,int&b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void test(int a)
//{
//	cout << "test(int a)" << endl;
//}
//void test(int *a)
//{
//	cout << "test(int* a)" << endl;
//}
//class student
//{
//	void stu(int _a);
//	int a;
//};
//void student::stu(int _a)
//{
//	a = _a;
//}
//#include <iostream>
//using namespace std;
//class IType { public:	void Show1() { 	} }; class IType2 { public:	void Show2() { 	} };    class MyClass : IType, IType2{ public:	void Show3() {} };   int main(){ int a = sizeof(&MyClass::Show3);	std::cout << sizeof(void *) << "," << a << std::endl;  return 0; }
//#include <stdio.h> class Test {	int  mi;  	void init(int i)	{		mi = i;	} public: 	Test(int i) 	{ 		printf("Test(int i)\n");		init(i);	} 		Test() 	{ 		printf("Test()\n");		init(0); 	}  	void print() 	{ 		printf("mi = %d\n", mi); 	} 	~Test()	{		printf("~Test()\n");	}};  int main() { 	Test();	Test(1); 	Test().print();  // ֱ�ӵ��ù��캯��	Test(10).print(); 	getchar(); 	return  0; } 


#include<iostream>

using namespace std;
//class Test
//{
//	int  mi;
//	void init(int i)
//	{
//		mi = i;
//	}
//public:
//	Test(int i)
//	{
//		printf("Test(int i)\n");
//		init(i);
//	}
//	Test()
//	{
//		printf("Test()\n");
//		init(0);
//	}
//	void print()
//	{
//		printf("mi = %d\n", mi);
//	}
//	~Test()
//	{
//		printf("~Test()\n");
//	}
//};
//int main()
//{
//	Test();
//	Test(1);
//	Test().print();  // ֱ�ӵ��ù��캯��
//	Test(10).print();
//	getchar();
//	return  0;
//}
//ֱ�ӵ��ù��캯��������������ʱ����
//��ʱ�������������ֻ�С�������ʱ��
//��ʱ�����������ֻ�ڡ��������
//��ʱ������C++��ֵ�þ���Ļ�ɫ�ش�
//int main()
//{
//	test(0);  //�������β���
//	test(NULL);  //�������Ͳ���������ʵ����������Ҫ�ľ���ָ�����ͣ�����C++11�ṩ��nullptr
//	test(nullptr);//����ָ������
//	//auto a[3] = { 1, 2, 3 };
//	/*int a = 10;
//	int* b = nullptr;*/
//	//swap(a, *b);
//	/*int a = 10;
//	int b = 20;
//	a = a + b;
//	b = a - b;
//	a = a - b;*/
//	/*clock_t a1;
//	clock_t a2;
//	a1 = clock();
//	const int a = 10;
//	int* b = (int*)&a;
//	*b = 100;
//	cout << a << endl;
//	cout << *b << endl;
//	for (int i = 0; i < 1000000000; ++i)
//	{
//	}
//	a2 = clock();
//	cout << a2 - a1 << endl;*/
//	return 0;
//}
class A
{
public:
	void show()
	{
		cout << this << endl;
		cout << "132456" << endl;
	}
	void printfA()
	{
		cout << this << endl;
		cout << this->_a << endl;  //�ڴ˴�������
		//����Ϊ�ǲ�û����ʵ��������Ҳ����˵pû��ָ��һ�������Ķ���Ҳ����û�пռ䣬����Ҳ���޷���ӡ���ݣ��Ƿ�����
		//����֮ǰ�����Ѿ�˵���ˣ����������ǿ��Դ���ָ��ģ�����show������������
	}
private:
	int _a;
};
int main()
{
	A* p = NULL;
	p->show();  //�˺���������������
	p->printfA();  //�˺���������
	return 0;
}