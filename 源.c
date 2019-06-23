#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class mystring
{	
public:
	friend ostream& operator <<(ostream& cout,mystring & p);  //初始化<<运算符
	friend istream& operator >>(istream& cin, mystring & p);  //初始化>>运算符
	mystring();//默认初始化
	mystring(char *a);//有参初始化
	mystring(const mystring &p);//拷贝构造
	mystring& operator=(char *a);//=重载，这个是针对字符数组的重载
	mystring& operator= (mystring &p);//=重载，这个是针对对象的重载
	char& operator[](int a);//重载[]
	mystring operator+(mystring &p); //+运算符重载
	mystring operator+(char *a);
	~mystring();//析构函数
private:
	char *mystr;     //定义字符串变量
	int mysize;        //定义字符串长度
};
mystring::mystring(char *a) //有参构造函数的实现
{
	this->mystr = new char[strlen(a) + 1];
	strcpy(this->mystr, a);
	this->mysize = strlen(a);
}
mystring::mystring(const mystring &p)//拷贝构造函数
{
	this->mystr = new char[strlen(p.mystr) + 1];
	strcpy(this->mystr, p.mystr);
	this->mysize = p.mysize;
}
mystring::~mystring() //析构函数
{
	if (this->mystr != NULL)
	{
		delete[] this->mystr;
		this->mystr = NULL;
	}
}
ostream& operator <<(ostream& cout,mystring & pp)//左移重载不需要在函数内部声明，拿全局函数即可，但记得要友元化
{
	cout << pp.mystr << endl;
	return cout;
}
istream& operator >>(istream& cin,mystring & p)
{
	if (p.mysize != NULL)     //首先删除原有空间内容
	{
		delete[] p.mystr;
		p.mystr = NULL;
	}
	char buf[1024];              //定义一个缓冲区作为中间存储区
	cin >> buf;                     //输入内容
	p.mystr = new char[strlen(buf) + 1];  //重新申请新的空间
	strcpy(p.mystr, buf);
	p.mysize = strlen(buf);
	return cin;
}
mystring& mystring::operator=(char *a)
{
	if (this->mystr != NULL)
	{
		delete[] this->mystr;
		this->mystr = NULL;
	}
	this->mystr = new char[strlen(a) + 1];
	strcpy(this->mystr, a);
	this->mysize = strlen(a);
	return *this;
}
mystring& mystring::operator=(mystring &p)
{
	if (this->mystr != NULL)
	{
		delete[] this->mystr;
		this->mystr = NULL;
	}
	this->mystr = new char[strlen(p.mystr) + 1];
	strcpy(this->mystr, p.mystr);
	this->mysize = p.mysize;
	return *this;
}
char& mystring::operator[](int a)
{
	return this->mystr[a];
}
mystring mystring::operator+(mystring &p)
{
	int newsize = this->mysize + p.mysize + 1;
	char *pp = new char[newsize];
	memset(pp, 0, newsize);
	strcat(pp, this->mystr);
	strcat(pp, p.mystr);
	mystring newstr(pp);
	delete[] pp;
	return newstr;
}
mystring mystring::operator+(char *a)
{
	int newsize = this->mysize + strlen(a) + 1;
	char *pp = new char[newsize];
	memset(pp, 0, newsize);
	strcat(pp, this->mystr);
	strcat(pp, a);
	mystring newstr(pp);
	delete[] pp;
	return newstr;
}
void test()                      //测试函数1
{
	mystring p1("大鸡巴");
	mystring p2 = "lajio";
	cout << p2;
	cout << p1;
	cout << "请输入新内容" << endl;
	cin >> p1;
	cout << p1;
} 
void test2()                           //测试函数2 
{
	mystring p1("狗腿子");
	mystring p2="csdlkcs3123";  //在这里mystring p2="csdlkcs3123";就等于mystring p2(csdlkcs3123),所以调用的是有参构造函数      
	p2 = p1;                    //用对象进行赋值，对=进行重载，如果不重载就只是进行简单的值拷贝，类中存在在堆上的值则需要我们进行重载	
	p2 = "1321654chuaih";       //在这里p2="1321654chuaih"不等同于上面的拷贝构造所以在这里要想实现这个就要对=号进行拷贝构造
	cout << p2;
	p2[0] = 'w';                       //对某个字符进行替换
	cout << p2[0] << endl;             //再实现一个根据索引求元素的操作
}
void test3()
{
	mystring p11("雷柏");
	mystring p22("无线键盘鼠标");
	mystring p33=" ";
	p33 = p22 + p11;//重载加号运算符
	cout << p33;
}
int main()
{
	//test();
	//test2();
	test3();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class gonggong
{
public:
	void laji()
	{
	
	}
	int s;
};

class news: public gonggong
{
public:
	void lajilaji()
	{
		cout << s;
	}

};

class musuy :public news
{
public:
	void lallala()
	{
		cout << s;
    }
};
void test()
{
	news a;
	a.laji;
}


int main()
{

}
#endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	father()
	{
		this->b = 100;
	}
	void fun()
	{
		cout << "我是父类fun" << endl;
	}
	void fun(int a)
	{
		cout << "我是父类函数重载" << endl;
	}
	int b;
};
class son:public father
{
public:
	son()
	{
		this->b = 200;
	}
	void fun()
	{
		cout << "我是子类fun函数" << endl;
	}
	int b;
};
void test()
{
	son p;
	cout << p.b << endl;  //打印结果是200，因为子类与父类同名那么就会有就近原则
	//如果要调用父类中的值，那么就必须加上作用域,调用同名函数也是这样的操作
	cout << p.father::b << endl;
	//接着再说一种情况就是
	p.father::fun(10);
	// p.fun(10);        //这样是无法访问的，结论是如果父类与子类含有同名的函数，那么父类中其他的同名函数，就例如这个重载的函数就会被覆盖掉，要访问就要加上作用域
	p.father::fun();
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
class father
{
public:
	static int a;
};
int father::a = 10;
class son:public father
{
public:
	static int a;
};
int son::a = 20;
void test()
{
	son p;
	cout << p.a << endl;
	cout << p.father::a<<endl;
	//静成员变量子类可以继承下来
	cout << son::a << endl;    //访问子类a
	cout << father::a << endl;   //访问父类a
}
int main()
{
	test();
	return 0;
}
# endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	father()
	{
		cout << "我是父类构造函数" << endl;
	}
	~father()
	{
		cout << "我是父类析构函数" << endl;
	}
	int a;
};
class son :public father
{
public:
	son()
	{
		cout << "我是子类构造函数" << endl;
	}
	~son()
	{
		cout << "我是子类的析构函数" << endl;
	}
	int b;
};
int main()
{
	son a;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	virtual void funa()     //这里加上关键字使得函数变成虚函数
	{
		cout << "动物在说话" << endl;
	}
	virtual void funb()
	{
		cout << "出来吧，卡布达" << endl;
	}
};
class son :public father
{
public:
	void funa()
	{
		cout << "小猫在说话" << endl;
	}
	void funb()
	{
		cout << "吃屎吧你" << endl;
	}
};
//因为父子类函数中都有funa函数，如果父类中的funa前面不加关键词变为虚函数的话
//那么在运行going函数的时候，地址就早绑定了，在编译阶段就确定好了地址
//将父类函数变成虚函数之后，那么就会在运行的时候再去确定函数地址，运行时绑定
//我发现如果这个时候想去调用父类中的funa则需要加作用域father：：
void going(father & a)      //在这里我们定义的函数参数时是父类对象，而传参传的是子类对象               
{                           // 也就是说父类的只指针或者引用指向了子类的对象 ，也就是多态的定义
	a.father::funb();
}
void test()
{
	son p;         //这里定义的是子类的对象而上面函数传递的参数是父类，这个说明了在发生继承关系的时候编译器允许进行类型转换
	going(p);
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
class jisuanqi
{
public:
	//虚函数 virtual int jieguo(){return 0;}
	virtual int jieguo() = 0;       //纯虚函数
	void seta(int aa,int bb)         //如果父类有了纯虚函数那么子类继承了父类，那么就必须实现父类中的虚函数
	{                              //有了纯虚函数那么父类就不能再实例化对象了，无论是堆上还是栈上都不被允许
		this->a = aa;              //纯虚函数又称为抽象函数
		this->b = bb;
	}
	int a;
	int b;
};
class jiafa : public jisuanqi
{
public:
	int jieguo()
	{
		return a + b;
	}
};
class jianfa :public jisuanqi
{
public:
	int jieguo()
	{
		return a - b;
	}
};
void test()
{
	jisuanqi *abc =new jiafa;
	abc->seta(10, 10);
	cout << abc->jieguo() << endl;
	
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class father
{
public:
	virtual	void sleep()
	{
		cout << "爸爸在睡觉" << endl;
	}
	/* virtual ~father()
	{
		cout << "父类的析构" << endl;
	}*/
	//类内声明,类外实现
	virtual ~father()=0;
};
father::~father()
{
	cout << "父类的析构" << endl;
}
class son :public father
{
public:
	 void sleep()
	{
		cout << "儿子在睡觉" << endl;
	}
	son(const  char * a)
	{
		this->name = new char[strlen(a) + 1];
		//在这里我有一点要说明的就是在调试的过程中char（strlen（a）+1）与char[strlen(a)+1]
		//这两个表达式只有括号的区别但是用前者会在delete的时候崩溃
		//我猜测肯能和delete[]后面是[]有关吧!所以在以后还是尽量写[],规范书写
		strcpy(this->name, a);
	}
	~son()             //普通的析构不会调用子类的析构 ，会导致析构不干净
	{                  //可以利用虚析构来调用子类析构，虚析构和虚函数加的关键字一样virtual在父类析构函数
		cout << "子类的析构" << endl;
		if (this->name != NULL)
		{
			delete[]this->name;
			this->name = NULL;
		}
	}
	char *name;
};
void test()
{
	father *p = new son("吃西瓜");
	/*father a;
	father *pp = new father;*/
	//p->father::sleep();
	p->sleep();
	delete p;       //在这里的析构释放的是父类的空间，却无法在子类中利用析构函数释放子类空间
}
int main()
{
	test();
	return 0;
}
#endif
#include<stdio.h>
#include<string.h>
int main()
{
	char a[20]="lajilaji";
	printf("%d\n", sizeof(a));
	int aa=strlen(a);
	printf("%d\n", aa);
	return 0;
}














