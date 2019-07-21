#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;
#if 0
//关联式容器，只要插入数据就自动排序
void printfs(set<int>& p)
{
	for (set<int>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	set<int>v;
	v.insert(1); //插入数据只能用insert
	v.insert(7);
	v.insert(3);
	v.insert(9);
	v.insert(5);
	printfs(v);          //1 3 5 7 9 默认从小到大进行排序
	v.erase(++v.begin());    //不支持随机访问迭代器  1 5 7 9 
	v.erase(7);          //可以直接通过实值进行删除 1 5 9
	printfs(v);
}
void test1()
{
	set<int>v;
	v.insert(1); 
	v.insert(7);
	v.insert(3);
	v.insert(9);
	v.insert(5);
	set<int>::iterator pos = v.find(3);
	if (pos != v.end())
		cout << "找到了" << endl;
	else
		cout << "没找到" << endl;
	//因为set容器下没有重复的值所以count要么是0，要么是1
	int counts = v.count(5);
	cout << "v.count(5)的个数就是" << counts << endl;
	set<int>::iterator s = v.lower_bound(10);
	//lower_bound（set）返回第一个 >=set的数的迭代器，找不到的话就返回v.set()(也就是容器最后一个元素的下一个位置)
	if (s != v.end())
		cout << "找到了" << *s << endl;
	else
		cout << "没找到" << endl;
	//upper_bound（set）返回第一个 >set的数的迭代器，找不到的话就返回v.set()
	set<int>::iterator s1 = v.upper_bound(5);    
	if (s1 != v.end())
		cout << "找到了" << *s1 << endl;
	else
		cout << "没找到" << endl;
	//equal_range（set）会返回两个返回值(迭代器)，set的上限和下限也就是lower_bound（set），upper_bound（set）
	//这时候就需要深入底层去看看怎样接受两个返回值，对组pair<iterator, iterator>
	//pair<iterator, iterator>这个是一种类型
	pair<set<int>::iterator , set<int>::iterator> L = v.equal_range(3);
	//这样就相当于定义好了变量L用来获取返回值 
	if (L.first != v.end())
		cout << "找到了 lower_bound（set）= " << *(L.first) << endl;
	else
		cout << "没找到" << endl;
	if (L.second != v.end())
		cout << "找到了 upper_bound（set）= " << *(L.second) << endl;
	else
		cout << "没找到" << endl;
}
void test2()
{
	///第一种创建对组的方式
	pair<string, int> p("王者", 10);
	cout << p.first << " " << p.second << endl;
	///第二种创建对组的方式
	pair<string, int> p1 = make_pair("王者", 10);
	cout << p1.first << " " << p1.second << endl;
}
void test3()
{
	//关于insert不允许插入重复键值的深究
	set<int>v;
	v.insert(1);
	v.insert(1);
	printfs(v);        //可以运行成功但是只打印一个1
	//首先深入底层查看insert函数返回值原型
	///_Pairib insert(value_type&& _Val)
	//typedef typename _Mybase::_Pairib _Pairib;
	//typedef pair<iterator, bool> _Pairib;   //返回值原函数，第二个参数是对是否插入成功的检测
	//可知返回值是对组类型，我们进行检测一下
	pair<set<int>::iterator, bool>  _Pairib;
	_Pairib = v.insert(10);
	if (_Pairib.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}
	_Pairib = v.insert(10);
	if (_Pairib.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}
}
//从大到小排序set容器
//由于默认是从小到大，但是插入数据之后就不会再被允许修改，所以要想从大到小排序就必须在插入数据前就指定好排序规则（利用仿函数）
class person
{
public:
	int operator() (int a, int b)       //重载()不要问为什么因为我也不知道
	{
		return a > b;
	}

};
void printfs2(set<int, person>& p)
{
	for (set<int, person>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test4()
{
	set<int>v;
	v.insert(1);
	v.insert(7);
	v.insert(3);
	v.insert(9);
	v.insert(5);
	printfs(v);   //默认是从小到大打印
	set<int, person>v1;
	v1.insert(1);
	v1.insert(7);
	v1.insert(3);
	v1.insert(9);
	v1.insert(5);
	printfs2(v1);
}
#endif
#if 0
//自定义数据类型做插入
class person
{
public:
	person(string name, int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	string name;
	int ages;
};
class sorts           //伪函数必须重新写一个类
{
public:
	bool operator() (const person& a, const person& b)       //重载()不要问为什么因为我也不知道
	{
		return a.ages > b.ages;
	}
};
void printfs(set<person,sorts>& p)
{
	cout << "-----------------" << endl;
	for (set<person,sorts>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << "|  "<< it->name <<"\t"<< "|  " << (*it).ages <<"\t"<< "| " << endl;
		cout << "-----------------" << endl;
	}
}
void test5()
{
	set<person,sorts>v;
	person p1("大娃", 100);
	person p2("2娃", 90);
	person p3("3娃", 80);
	person p4("4娃", 70);
	person p5("5娃", 60);
	person p6("6娃", 50);
	person p7("7娃", 40);
	person p8("爷爷", 30);
	v.insert(p1);
	v.insert(p2);
	v.insert(p3);
	v.insert(p4);
	v.insert(p5);
	v.insert(p6);
	v.insert(p7);
	v.insert(p8);
	printfs(v);
}
int main()
{
	test5();
	return 0;
}
#endif
int main()
{
	vector<int>v;
	int a = 1;
	v.push_back(a);
	v.push_back(a);
	v.push_back(a);
	v.push_back(a);
	v.push_back(a);
	cout << v.size() << endl;
}