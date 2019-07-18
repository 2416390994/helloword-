//#include<iostream>
//using namespace std;
//int main()
//{
//	char a = 'c';
//	double b = static_cast<double>(a);
//	cout << b << endl;
//	return 0;
//}
//发生多态：父类有一个和子类函数名相同的虚函数。
//父类的指针指向子类的对象
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	virtual void func(){}         //虚函数
};
class child : public father
{
public:
	void func(){}
};
void test()
{
	father *p = new child;          //父类的指针指向子类的对象
	child *b = dynamic_cast<child*>(p);   //由父类转为子类是不安全的，但是这里发生了多态，所有就可以使用动态的类型转换
}
void test2()
{
	int* a =NULL;
	const int* b = NULL;
	//去掉const
	int* c = const_cast<int*>(b);
	//加上const
	const int* d = const_cast<const int*>(a);
	int e;
	int& f = e;
	const int& h = e;
	//加上const
	const int& g = const_cast<const int&>(f);
	//去掉const
	int& L = const_cast<int&>(h);

}

int main()
{
	test2();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
void func(int a,int b)
{
	if (b == 0)
	{
		throw - 1;//抛出异常
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try
	{
		func(a, b);
	}
	catch (int)  //捕获int异常
	{
		cout << "异常已经被捕获\n";
	}
	catch (...)    //捕获任意类型异常
	{
		cout << "其他异常被捕获\n";
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
void func(int a, int b)
{
	if (b == 0)
	{
		throw - 1;//抛出异常
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try
	{
		func(a, b);
	}
	catch (int)  //捕获int异常
	{
		throw;
		cout << "test函数捕获异常\n";
	}
}
//main函数包含test()函数，test函数包含func()函数，并且每一层包含下一层的异常捕获 。
//然后main函数开始执行，调用test函数，然后test函数调用func函数，function函数抛出异常，先返回并且被test函数捕获处理
//这时候main函数里面的异常捕获并没有发挥作用
int main()
{
	try
	{
		test();
	}
	catch (int)
	{
		cout << "main函数捕获int异常\n";
	}
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class person{};
void func(int a,int b)
{
	if (b == 0)
		throw person();//类名（）表示匿名对象
}
void test()
{
	int a = 10;
	int b = 0;
	try      //尝试执行这个函数
	{
		func(a,b);
	}
	catch (person)
	{
		cout << "自定义类型异常\n";
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father{};  //用来抛出异常的自定义类型
class person     //用来查看栈解旋的类
{
public:
	person()
	{
		cout << "构造函数\n";
	}
	~person()
	{
		cout << "析构函数\n";
	}
};
void func(int a, int b)
{
	if (b == 0)
	{
		person p1;
		person p2;
		throw father();//类名（）表示匿名对象，出现错误就抛出father类型对象
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try      //尝试执行这个函数
	{
		func(a, b);
	}
	catch (father)        ///捕获father类型的异常
	{
		cout << "自定义类型异常\n";
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father    //父类
{
public:
	virtual void FUNC()
	{}
}; 
class child1 :public father
{
public:
	virtual void FUNC()
	{
		cout << "壹号异常\n";
	}
};
class child2 :public father
{
public:
	virtual void FUNC()
	{
		cout << "贰号异常\n";
	}
};
void func(int a, int b)
{
	if (b == 0)
	{
		
		throw child1();          //这里抛出的是派生类异常
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try                              //尝试执行这个函数
	{
		func(a, b);
	}
	catch (father& e)          //这里捕获的是父类的对象，用父类的指针或者引用指向子类的对象 ，已经发生了多态
	{
		e.FUNC();             //既然已经发生了多态就是晚绑定，运行时绑定，那么就会调用类同名函数（FUNC）
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<stdexcept>           //包含头文件
using namespace std;
class person
{
public:
	person(string a,int b)
	{
		this->ages = b;
		this->name = a;
		if (b > 200 || b < 0)
		{
			throw out_of_range("年龄越界了\n");
		}
	}
	string name;
	int ages;
};

void test()
{
	try      
	{
		person p("刘老师", 1000);
	}
	catch (out_of_range& e)          //这里推荐传引用，out_of_range其实也是一个类类型
	{ 
		cout <<e.what();             //每个错误类都包含一个what()
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
//_EXCEPTION_INLINE virtual __CLR_OR_THIS_CALL ~exception() _NOEXCEPT;
//_EXCEPTION_INLINE virtual const char * __CLR_OR_THIS_CALL what() const;
//c++中所有的系统自定义异常都是继承exception类，基类中有很多函数，我们要进行重写只需要对用到的函数进行重写就可以了
class perro:public exception          //点击F12可以查看基类，现在对上面的两个函数进行重写，因为不会继承到构造函数所以自己写
{
public:
	perro(string error)
	{
		this->error = error;
	}
	virtual ~perro()         //因为也没有在堆上创建对象所以这个析构也就不自己实现了
	{

	}
	virtual const char * what() const
	{
		return this->error.c_str();     //以为基类的what函数返回值是char* 类所以我们要对string类型进行强转
	}
	string error;
};
class person
{
public:
	person(string name, int ages)
	{
		this->name = name;
		if (ages<0 || ages>200)
		{
			throw perro("年龄太大了");
		}
		else
			this->ages = ages;
	}
	string name;
	int ages;
};
void test()
{
	try
	{
		person p("猪八戒", 300);
	}
	catch (perro & p1)
	{
		cout << p1.what() << endl;
	}
}
int main()
{
	test();
	return 0;
}
#endif






