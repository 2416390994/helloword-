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
//#include <stdio.h> class Test {	int  mi;  	void init(int i)	{		mi = i;	} public: 	Test(int i) 	{ 		printf("Test(int i)\n");		init(i);	} 		Test() 	{ 		printf("Test()\n");		init(0); 	}  	void print() 	{ 		printf("mi = %d\n", mi); 	} 	~Test()	{		printf("~Test()\n");	}};  int main() { 	Test();	Test(1); 	Test().print();  // 直接调用构造函数	Test(10).print(); 	getchar(); 	return  0; } 


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
//	Test().print();  // 直接调用构造函数
//	Test(10).print();
//	getchar();
//	return  0;
//}
//直接调用构造函数将产生—个临时对象
//临时对象的生命周期只有—条语句的时间
//临时对象的作用域只在—条语句中
//临时对象是C++中值得警惕的灰色地带
//int main()
//{
//	test(0);  //调用整形参数
//	test(NULL);  //调用整型参数，但是实际上我们想要的就是指针类型，所以C++11提供了nullptr
//	test(nullptr);//调用指针类型
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
		cout << this->_a << endl;  //在此处将崩溃
		//我认为是并没有是实例化对象，也就是说p没有指向一个正常的对象，也就是没有空间，所以也就无法打印内容，非法访问
		//但是之前我们已经说过了，函数传参是可以传空指针的，所以show可以正常运行
	}
private:
	int _a;
};
int main()
{
	A* p = NULL;
	p->show();  //此函数可以正常运行
	p->printfA();  //此函数不可以
	return 0;
}