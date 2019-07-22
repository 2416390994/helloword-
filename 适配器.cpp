#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>//1.添件头文件functional
#include<string>
using namespace std;
#if 0
class func
{
public:
	void operator()(int a)
	{
		cout << a+100 << endl;
	}

};
class func2 :public binary_function<int,int,void>//3.继承类binary_function<参数类型1，参数类型2，返回值>
{
public:
	void operator()(int a, int start)const         //4.加const修饰仿函数operaator
	{
		cout << a + start << endl;
	}

};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	for_each(v.begin(),v.end(),func()); //使用伪函数打印
	//如何调用适配器
	//1.添件头文件functional
	//2.利用bind2nd绑定数据
	//3.继承类binary_function<参数类型1，参数类型2，返回值>
	//4.加const修饰仿函数operaator
	cout << "请输入起始值：" << endl;
	int num;
	cin >> num;	
	for_each(v.begin(), v.end(), bind2nd(func2(), num));//2.利用bind2nd绑定数据
}
#endif
#if 0
class func :public unary_function<int,bool> //两个参数一个是bool operator()(int a)const 里面的int a的参数，一个是函数返回值参数
{
public:
	bool operator()(int a)const
	{
		return a > 5;
	}

};
//取反适配器
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	vector<int>::iterator it = find_if(v.begin(), v.end(), func());
	if (it != v.end())
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	//现在修改了需求不允许改变仿函数内部，让你寻找第一个小于5的数
	//就需要运用到取反适配器
	//1.添加取反适配器
	//2.继承关系
	//3.const
	//4.头文件
	it = find_if(v.begin(), v.end(), not1(func()));    //这三个参数的前面两个意思就是从v.begin(),到v.end()这个区间从头找
	if (it != v.end())
	{
		cout << "找到了" << *it << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
}
#endif
#if 0
//函数指针适配器
void func(int a,int num)
{
	cout << a + num << endl;
}
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	int num;
	cin >> num;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(func), num));//这次调用的是函数不是伪函数，ptr_fun(func)函数指针适配器
}
#endif
//成员函数适配器
class person         
{
public:
	person(string name, int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	void func()        //成员函数
	{
		cout << "姓名 :" << name << "年龄 :" << ages << endl;
	}
	string name;
	int ages;
};
void func(person & p)     //全局函数
{
	cout << "姓名 :" << p.name << "年龄 :" << p.ages<<endl;
}
void test04()
{
	vector<person>v;
	person p1("老1", 101);
	person p2("老2", 50);
	person p3("老3", 60);
	person p4("老4", 20);
	person p5("老5", 80);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for_each(v.begin(), v.end(), func); //第三个参数如果是回调函数不用加（），伪函数要加()，因为伪函数加（）的实际作用是声明一个匿名函数对象
	cout << "------------------------------------------------" << endl;
	//上面我们提供的回调函数是全局函数，假如把函数拿到类内部让函数成为成员函数，那么就会需要成员函数适配器
	for_each(v.begin(), v.end(), mem_fun_ref(&person:: func));   //调用全局函数
}
int main()
{
	test04();
	return 0;
}
#endif