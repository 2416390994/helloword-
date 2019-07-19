#if 0
#include<iostream>
using namespace std;
void test()
{
	int a = 0;
	int b = 0;
	int d = 0;
	int e = 0;
	char c;
	while ((c = cin.get())!= '\n')
	{
		if (c >= 'A' && c <= 'Z')
		{
			 a++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			b++;
		}
		else if (c >= '0' && c <= '9')
		{
			d++;
		}
		else
		{
			e++;
		}
	}
	cout << "大写字母" << a << endl << "小写字母" << b << endl << "数字" << e << endl << "其他" << d << endl;
}
void test2()
{
	int a = 0;
	int b = 0;
	int d = 0;
	int e = 0;
	int count = 0;
	while (1)
	{
		char c = cin.get();
		if (c == '\n')
		{
			if (++count == 3)
				break;
		}
		if (c >= 'A' && c <= 'Z')
		{
			a++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			b++;
		}
		else if (c >= '0' && c <= '9')
		{
			d++;
		}
		else
		{
			if (c == '\n')
			{}
			else
				e++;
		}
	}
	cout << "大写字母" << a << endl << "小写字母" << b << endl << "数字" << e << endl << "其他" << d << endl;
}
int main()
{
	test2();
	return 0;
}
#endif
//vector
#if 0
#include<iostream>
#include<vector>//容器头文件
using namespace std;
void test()
{
	vector<int>v;      //声明一个名为v的容器，这个容器存放int型数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//vector<int>::iterator itbegin = v.begin(); //定义向量迭代器指向容器的起始位置
	//vector<int>::iterator itend = v.end();      //这里的end（）指的是最后一个数的下一个位置
	//while (itbegin != itend)
	//{
	//	cout << *(itbegin++) << endl;
	//}
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
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
#include<vector>
using namespace std;
void test()
{
	vector<int>v;      //声明一个名为v的容器，这个容器存放int型数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	for (vector<int>::iterator it = v.begin(); it != v.end; ++it)
	{
		cout << it << endl;
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
#include<vector>//容器头文件
#include<algorithm>//算法头文件
using namespace std;
void myprintf(int v)
{
	cout << v << endl;
}
void test()
{
	vector<int>v;      //声明一个名为v的容器，这个容器存放int型数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	for_each(v.begin(), v.end(), myprintf);//myprintf自定义的一个回调函数，具体步骤可查看源码
}

int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class person
{
public:
	person(string name ,int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	int ages;
	string name;
};
void test()
{
	person p1("大头儿子", 10);
	person p2("小头爸爸", 50);
	person p3("围裙妈妈", 25);
	person p4("隔壁老王", 28);
	vector<person*>v;   //<>内的类型就是你容器内所存放的数据类型
	v.push_back(&p1);  //容器内存放的是自定义类型的指针那么这里就要改成地址
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	//那么*it也跟着改变，这个时候*it就相当于指向自定义数据类型对象的指针。一句话*it就是< >内的类型
	for (vector<person*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->name << " " << (*(*it)).ages << endl;   //这里用两种表现形式来展示
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
//容器的嵌套
#include<iostream>
using namespace std;
#include<vector>
void test()
{
	//先定义一个嵌套的容器，可以类比教学楼里面的教室
	vector<vector<int>>v;
	//在定义内层的容器，我们这里定义三个就可以了
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	//先对最内层容器赋值
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i);
		v2.push_back(10 + i);
		v3.push_back(100 + i);
	}
	//接着拿小容器给大容器赋值
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	//接着我们尝试打印一下容器里面的数据
	//打印也是从小容器开始打印的
	for (vector<vector<int>>::iterator it1 = v.begin(); it1 < v.end(); ++it1)
	{
		for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
		{
			cout << (*it2) << " ";
		}
		cout << endl;
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
class person
{
public:
	static int man;
};
int person::man = 10;
int main()
{
	cout << person::man << endl;
	return 0;
}
#endif