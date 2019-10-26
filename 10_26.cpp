#include<iostream>
#include<string>
using namespace std;
//class test
//{
//public:
//	~test()
//	{
//		delete this;  //无限递归，死循环
//		//调用析构，只要delete就调用析构
//	}
//private:
//	test()
//	{}
//};
//int main()
//{
//	return 0;
//}
//class date
//{
//public:
//	static date* get()  //对外提供接口，但是要想调用普通函数的话就得先有对象，所以把函数给成静态的
//	{
//		return new date;
//	}
//	//但是又有一个问题就是，创建对象，除了构造，还有拷贝构造
//	//C++11给的方法是
//	date(const date& p) = delete; //这种办法就避免了利用拷贝构造函数在堆上面创建对象
//	//也就是说C++11把delete的作用扩大了，除了释放空间之外，还可以删除默认的拷贝构造函数，当然也可以删除其他的构造函数
//private:
//	date()
//	{}
//};

//template<class T1>
//T1 add(T1 a, T1 b)
//{
//	return a + b;
//}
//int main()
//{
//	//对函数模板进行实例化
//	//我们在分步运行的时候看见的是运行到了我们所写的模板函数里面
//	//但是实际上不是那样的，因为在编译阶段，如果编译器检测到对某个函数模板进行了实例化，就会
//	//对实参的类型进行推演，根据推演结果，结合函数模板，确认模板函数中的参数的实际类型，
//	//然后生成具体的函数
//	add(1, 2);
//	add(1.0, 2.0);
//	add('a','b');
//	return 0;
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//template<class T1,class T2>
//T1 add(T1 a, T2 b)
//{
//	return a + b;
//}
//template<class T>
//class date
//{
//public:
//	void add();
//private:
//	T* p;
//};
//template<class T>
//void date<T>::add()
//{}
class date
{

private:
	int c;
};
int main()
{
	//add(1, 1.0);//调用函数模板
	return 0;
}