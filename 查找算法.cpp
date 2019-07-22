#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>//1.添件头文件functional
#include<string>
using namespace std;
#if 0
//首先查找一下简单的
void test01()
{
	vector<int>p2;
	for (int i = 0; i < 10; ++i)
	{
		p2.push_back(i);
	}
	vector<int>::iterator it = find(p2.begin(), p2.end(), 5);        //意思就是找5，返回值是一个迭代器
	if (it != p2.end())
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}
//查找自定义的类型
class person
{
public:
	person(string name,int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	bool operator == (const person& p)           //这里切记加上const，坑死了啊
	{
		if (this->ages == p.ages && this->name == p.name)
			return true;
		else
			return false;
	}
	int ages;
	string  name;
};
void test02()
{
	vector<person>v;
	person p1("老1", 10);
	person p2("老2", 9);
	person p3("老3", 8);
	person p4("老4", 7);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//find(v.begin(), v.end(),p2);直接这样查找肯定是不行的，必须要知道底层是怎样查找的  
	//if (*_First == _Val)我们看到这行代码就是底层的查找核心，用的是==
	//由于是自定义的数据类型所以我们必须对==进行重载
	vector<person>::iterator it = find(v.begin(), v.end(), p2);
	if (it != v.end())
	{
		cout << "找到了" << (*it).name<<" "<<(*it).ages << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}
#endif
#if 0
//用户定义查找
class person
{
public:
	person(string name, int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	int ages;
	string  name;
};
class func:public binary_function<person*,person*,bool>
{
public:
	bool operator()(const person* p1,const person* p2)const
	{
		if (p1->ages == p2->ages && p1->name == p2->name)
		{
			return true;
		}
		else
			return false;
	}
};
void test03()
{
	vector<person*>v;
	person p1("老1", 10);
	person p2("老2", 9);
	person p3("老3", 8);
	person p4("老4", 7);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	person* p5 = new person("老2", 9);
	vector<person*>::iterator it = find_if(v.begin(), v.end(),bind2nd(func(),p5));
	if (it != v.end())
	{
		cout << "找到了" << (*it)->name << " " << (*it)->ages << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}
#endif
#if 0
void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "找到了" << (*it)<< endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}
#endif
#if 0
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 4);
	if (ret)
		cout << "找到了" << endl;
	else
		cout << "没找到" << endl;
}
#endif
int func(int a)
{
	return a > 4;
}
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	int ret = count(v.begin(), v.end(), 3);     //按数值来进行查找
	cout << ret << endl;
	ret = count_if(v.begin(), v.end(), func);     //条件查找，利用回调函数
	cout << ret << endl;
}
int main()
{
	test06();
	return 0;
}