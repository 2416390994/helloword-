#include<iostream>
#include<string>
using namespace std;
//class time
//{
//	friend class date;
//private:
//	int hour;
//	int minute;
//	int second;
//};
//class date
//{
//	friend ostream& operator<<(ostream& _cout,  date& p);
//	//注意：
//	//1.必须重载为全局函数
//	//2.第一个参数必须是ostream&,第二个参数必须是类对象的引用
//	//3.必须要有返回值--连续输出
//	//4.尽量在<<重载中不要有格式化输出，让用户自己在外面进行格式化
//	//5.将输出匀速那夫设置为类的友元类
//public:
//	date(int _year,int _mouth,int _day)
//		:year(_year)
//		, mouth(_mouth)
//		, day(_day)
//	{}
//	void gete()
//	{
//		t.hour = 1;
//		t.minute = 1;
//		t.second = 1;
//	}
//private:
//	int year;
//	int mouth;
//	int day;
//	time t;
//};
//ostream& operator<<(ostream& _cout,  date& p)
//{
//	p.day = 20;
//	_cout << p.year << " " << p.mouth << " " << p.day;
//	
//	return _cout;
//}

//class A
//{
//public:
//	A()
//	{
//		a = 20;
//	}
//	class B  //内部类
//	{
//		B()
//		{
//			b = 10;
//			A c;
//			c.a;
//			//内部类中可以访问外部类
//			//中的私有成员变量
//		}
//	private:
//		int b;
//	};
//private:
//	int a;
//};
//int main()
//{
//	A a;
//	cout << sizeof(A) << endl;
//	/*date s(2019, 10, 25);
//	cout << s << endl;*/
//	return 0;
//}
#if 0
class date
{
public:
	date()  //默认构造函数是设置为我的生日
	{
		_year = 1999;
		_month = 8;
		_day = 14;
	}
	date(int year,int month,int day)  //有参构造函数
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (_year > 0 &&
			_month > 0 && _month<13 &&
			_day>0 &&_day <= Getday(_year, _month))
		{}
		else
		{
			//假如输入的日期非法就设置为默认的日期，我的生日
			_year = 1999;
			_month = 8;
			_day = 14;
		}
	}
	date(date& p) //拷贝构造函数
	{
		_year = p._year;
		_month = p._month;
		_day = p._day;
	}
	date& operator=(date& p)
	{
		if (&p != this) //检测是不是自己给自己赋值
		{
			_year = p._year;
			_month = p._month;
			_day = p._day;
		}
		return *this;
	}
	//+号不会改变左右操作数中的内容，想一想cout<<a+b
	//并没有改变左右操作数中的内容，只是将相加后的值返回
	//所以返回的时候，只能按照值的方式返回
	date operator+(int days) //再过多少天是几月几号
	{
		date temp(*this);
		temp._day += days;
		int count = 0;
		while (temp._day > (count = temp.Getday(temp._year,temp._month))) //为的就是少一次函数调用
		{
			temp._day -= count;
			temp._month++;  //注意这里的写法
			if (temp._month > 12)
			{
				temp._year++;
				temp._month = 1;
			}
		}
		return temp;
	}
	date operator-(int days) //前多少天是几月几号
	{
		date temp(*this);
		temp._day -= days;
		while (temp._day <= 0) //为的就是少一次函数调用
		{
			
			temp._month--;  //注意这里的写法
			if (temp._month <= 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += temp.Getday(temp._year, temp._month);
		}
		return temp;
	}
	int operator-(date& p) //两个日期之间差了多少天
	{
		date max(*this);
		date min(p);
		if (p > *this)
		{
			swap(max, min);
		}
		int count = 0;
		while (max != min)
		{
			min++;
			count++;
		}
		return count;
	}
	bool operator>(const date& p)  //两个日期之间比大小
	{
		if (_year > p._year ||
			_year == p._year&&_month > p._month ||
			_year == p._year&&_month == p._month&&_day > p._day)
			return true;
		else
			return  false;
	}
	bool operator==(const date& p)
	{
		if (_year == p._year&&_month == p._month&&_day == p._day)
			return true;
		else
			return false;
	}
	bool operator!=(const date& p)
	{
		return !(*this == p);
	}
	bool operator<(const date& p)
	{
		if (_year < p._year ||
			_year == p._year && _month < p._month ||
			_year == p._year && _month == p._month && _day < p._day)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& _cout, date& p)  
	{
		_cout << p._year << "-" << p._month << "-" << p._day;
		return _cout;
	}
	date& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	date operator++(int)
	{
		date temp(*this);  //这里使用的是拷贝构造函数
		*this = *this + 1;
		return temp;
	}
	date& operator--()
	{
		*this = *this - 1;
		return *this;
	}
	date operator--(int)
	{
		date temp(*this); 
		*this = *this - 1;
		return temp;
	}
private:
	int Getday(int year, int month)  //判断这个月有多少天
	{
		int a[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //月份枚举
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				return a[2]+1;  //判断是不是闰年，如果是二月，然后又是闰年那么就给二月加一天
		}
			return a[month];
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	date d(2019,10,25);
	date d2(2019, 10, 25);
	cout << (d-d2) << endl;
	return 0;
}
#endif
/* memset example */
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	memcpy(str2, str1, strlen(str1)+ 1);//不会自动拷贝最后的\0需要加1
	//strcpy会自动拷贝最后的\0
	memcpy(str3, "copy successful", 16);
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}
//


