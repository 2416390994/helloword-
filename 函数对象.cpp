#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#if 0
class person
{
public:
	void operator()(int num)
	{
		cout << num << endl;
	}
	
};
void printfs(set<int>& p)
{
	for (set<int>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it <<" ";
	}
	cout << endl;
}
class oper
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
void printfs2( set<int,oper>& p)
{
	for (set<int,oper>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it <<" ";
	}
	cout << endl;
}
bool func(int a, int b)
{
	return a > b;
}
void test01()
{
	person a;
	a(111);
}
void test02()
{
	set<int>v;
	v.insert(10);
	v.insert(18);
	v.insert(9);
	v.insert(15);
	printfs(v);
	set<int,oper>v1;    //利用仿函数
	v1.insert(10);
	v1.insert(18);
	v1.insert(9);
	v1.insert(15);
	printfs2(v1); 
}
int main()
{	
	test01();
	test02();
	return 0;
}
#endif
#if 0
#include<algorithm>

class func20
{
public:
	//一元谓词的使用，一元体现在了bool 谓词体现在了（int a）
	bool operator()(int a)
	{
		return a > 5;
	}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	//第三个参数要是一个函数对象
	//func20 p;
	//find_if(v.begin(), v.end(), p); 
	//如果不愿意定义一个对象那么就可以用匿名对象func20()
	//find_if最后返回一个迭代器
	vector<int>::iterator it = find_if(v.begin(), v.end(), func20());   
	if (it!=v.end())
	{
		cout << "找到了第一个大于5的数：" << *it << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}


}
//二元谓词的使用
void printfs(vector<int>& p)
{
	for (vector<int>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
class func
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
bool func2(int a, int b)
{
	return a > b;
}
void test2()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	sort(v.begin(), v.end());
	printfs(v);         //排完序之后结构便发生了改变
	sort(v.begin(), v.end(), func());  //仿函数排序
	printfs(v);
	sort(v.begin(), v.end(), func2);    //利用回调函数
	//来点高端的方式打印一下
	//lambda表达式[](){}  //匿名函数
	for_each(v.begin(), v.end(), [](int val){cout << val << " " << endl;});
}
#endif
void test04()
{
	//telplate<class T>T negate<T>      取反
	negate<int>n;
	cout << n(10) << endl;
	//telplate<class T>T plus<T> 加法
	plus<int>p;
	cout << p(1,1) << endl;

}
void test05()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	//template<class T>T greater<T>大于
	sort(v.begin(), v.end(), greater<int>());//使用内建的大于函数排序，内部实现和我们自己写的其实一样
	for_each(v.begin(), v.end(), [](int val){cout << val << " " ; });
}
int main()
{
	test04();
	test05();
	return 0;
}