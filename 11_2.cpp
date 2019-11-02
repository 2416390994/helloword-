#include<iostream>
using namespace std;
//template<class T>
//T& MAX(T& left,T& right)
//{
//	return left > right ? left : right;
//}

template<class T>
const T& MAX(const T& left,const T& right)
{
	return left > right ? left : right;
}
//模板的特化
//template<>
//char*& MAX<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 1)  ///strcmp大于返回1，小于返回-1
//		return left;
//	return right;
//}
//template<>
//const char*& MAX<char*const &>(char*const & left, const char*& right)
//{
//	if (strcmp(left, right) == 1)  ///strcmp大于返回1，小于返回-1
//		return left;
//	return right;
//}

class Date
{
	friend ostream& operator<<(ostream& _cout, Date& p);
public:
	Date(int year,int month,int day)
	:_year(year)
	, _month(month)
	, _day(day)
	{}
	bool operator>(Date& p)
	{
		if (_year > p._year || _year == p._year && _month > p._month || _year == p._year && _month == p._month&&_day > p._day)
			return true;
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, Date& p)
{
	_cout << p._year << " " << p._month << " " << p._day << " ";
	return _cout;
}
//template<class T>
//void func(const T& p)    //那么按照常理来推测就是const int*& p ,也就是说const修饰的是p所只想的空间里面的内容不能修改
//{
//	*p = 100;  //但是这里修改了
//}
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	func(p);   //这里传的是int* 类型
//	cout << a << endl;  //并且在外部还可以正常打印出100
//	return 0;
//}
template<class T>
void cc(T**const  c)
{
	
	//**c = 20;
	int b = 10;
	*c = &b;
}
int main()
{
	int a = 10;
	int b = 20;
	cout << MAX(a, b) << endl;   //内置类型可以直接比较
	cout << MAX(b, a) << endl;
	Date d1(2019, 10, 22);   //自定义类型需要在类中将比较方式给出，那么就可以使用MAX函数来进行比较了
	Date d2(2019, 10, 23);
	/*cout << MAX(d1, d2) << endl;
	cout << MAX(d2, d1) << endl;*/
	//但是有的类型不能处理，或者处理出来就是错误
	//通常情况下可以使用模板实现一些与类型无关的代码，但是对于一些特殊类型得到的就是错误的情况
	char* p1 = "world";
	char* p2 = "hello";
	cout << MAX(p1, p2) << endl;   //打印结果出错
	cout << MAX(p2, p1) << endl;  
	int w = 10;
	const int *ww = &w;
	cc(&ww);
	cout << w << endl;
	return 0;
}







