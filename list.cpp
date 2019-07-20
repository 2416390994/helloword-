#if 0
void test()
{
	list<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	list<int>::_Nodeptr it = v._Myhead->_Next;
	for (int i = 0; i < v._Mysize*2; ++i)
	{
		cout << it->_Myval;
		it = it->_Next;
		if (it == v._Myhead)
		{
			it = it->_Next;
			cout << endl;
		}
	}
}
void printfs(list<int>& q)                      //打印list
{
	for (list<int>::iterator it = q.begin(); it != q.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void printfs2(list<int>& q)                      //打印list
{
	for (list<int>::reverse_iterator it = q.rbegin(); it != q.rend(); ++it)      //reverse_iterator逆向打印迭代器
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	list<int>v;   //模板默认构造
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	list<int>v1(v.begin(), v.end());       //提供区间构造
 	list<int>v2(10, 20);       //值构造
	printfs(v);       //正向打印           
	list<int>v3(v1);      //拷贝构造
	printfs2(v3);             //逆向打印
}
void test2()
{
	//remove（elem）删除容器中所有与elem相同的数据
	list<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(2);
	v.remove(2);
	printfs(v);
}
bool func(int a,int b)
{
	return  a > b;
}
bool func2(int a, int b)
{
	return  a < b;
}
void test3()
{
	list<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	printfs(v);
	v.reverse();     //反转
	printfs(v);
	//sort(v.begin(), v.end());   这样直接排序是会报错的，因为所有不支持随机访问的迭代器无法使用这种排序
	v.sort();         //可以使用这种排序，这是由类内部提供的一种排序
	printfs(v);
	v.sort(func);     //还有就是继续使用提供的算法的话那么就要使用回调函数
	printfs(v);
}
#endif
#include<iostream>
#include<list>
#include<string>
using namespace std;
void printfs(list<int>& q)                      //打印list
{
	for (list<int>::iterator it = q.begin(); it != q.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
class person
{
public:
	person(string name, int ages, int tall)
	{
		this->ages = ages;
		this->myname = name;
		this->tall = tall;
	}
	bool operator==(person p)             //关于返回值为什么是bool类型，由remove底层函数可以看出if (*_First == _Val)
	{                                      //这里既然是对==的重载那么就必然返回等号所需要知道的东西，那就是两个对象相等或者不等
		if (this->ages == p.ages&&this->myname == p.myname&&this->tall == p.tall)
		{
			return true;
		}
		else
			return false;
	}
	string myname;
	int ages;
	int tall;
};
bool func(person& a, person& b)        //类比于int型数据，这里的参数是   类型+对象
{
	if (a.ages == b.ages)
	{
		return a.tall > b.tall;       //如果两个对象的年龄相当就按谁的个子高谁在前面排序
	}
	return a.ages > b.ages;            //否则就按年龄大的在前面
}
void printfs(list<person>&v)
{
	for (list<person>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it).myname << "\t" << (*it).ages << "\t" << it->tall << endl;
	}
}

void test4()
{
	
	list<person>v;
	person p1("高渐离", 18,180);
	person p2("阿珂", 22,120);
	person p3("嬴政", 34,130);
	person p4("白起", 28,150);
	person p5("明世隐", 16,187);
	person p6("安琪拉", 10, 155);
	person p7("黄忠", 10, 185);
	person p8("橘子", 10, 142);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	v.push_back(p8);
	//a按照年龄大小对元素进行输出
	v.sort(func);       //对于自定义的书记类型必须使用自己写的回调函数
	printfs(v);
	v.remove(p6);
	v.remove(p5);
	v.remove(p4);
	v.remove(p2);
	v.remove(p8);
	//假如我们要使用remove来删除p6,这个肯定是错误的，这个就要查看remove的底层定义了
	//void remove(const _Ty& _Val)
	//{	// erase each element matching _Val
	//	iterator _Val_it = end();

	//	for (iterator _First = begin(); _First != end();)
	//	if (*_First == _Val)
	//	if (_STD addressof(*_First) == _STD addressof(_Val))
	//		_Val_it = _First++;
	//我们会发现在底层有这么一句话if (*_First == _Val)，用你的自定义类型和v.begin()比较，
	//两者都是对象（要是基本类型就可以这样比较），但是自定义类型系统不知道如何比较，
	//所以如果要使用remove删除自定义数据类型，就必须重写 ==
	cout << "===============================================" << endl;
	printfs(v);
}

int main()
{
	test4();
	return 0;
}