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
//	//ע�⣺
//	//1.��������Ϊȫ�ֺ���
//	//2.��һ������������ostream&,�ڶ�����������������������
//	//3.����Ҫ�з���ֵ--�������
//	//4.������<<�����в�Ҫ�и�ʽ����������û��Լ���������и�ʽ��
//	//5.����������Ƿ�����Ϊ�����Ԫ��
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
//	class B  //�ڲ���
//	{
//		B()
//		{
//			b = 10;
//			A c;
//			c.a;
//			//�ڲ����п��Է����ⲿ��
//			//�е�˽�г�Ա����
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
	date()  //Ĭ�Ϲ��캯��������Ϊ�ҵ�����
	{
		_year = 1999;
		_month = 8;
		_day = 14;
	}
	date(int year,int month,int day)  //�вι��캯��
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
			//������������ڷǷ�������ΪĬ�ϵ����ڣ��ҵ�����
			_year = 1999;
			_month = 8;
			_day = 14;
		}
	}
	date(date& p) //�������캯��
	{
		_year = p._year;
		_month = p._month;
		_day = p._day;
	}
	date& operator=(date& p)
	{
		if (&p != this) //����ǲ����Լ����Լ���ֵ
		{
			_year = p._year;
			_month = p._month;
			_day = p._day;
		}
		return *this;
	}
	//+�Ų���ı����Ҳ������е����ݣ���һ��cout<<a+b
	//��û�иı����Ҳ������е����ݣ�ֻ�ǽ���Ӻ��ֵ����
	//���Է��ص�ʱ��ֻ�ܰ���ֵ�ķ�ʽ����
	date operator+(int days) //�ٹ��������Ǽ��¼���
	{
		date temp(*this);
		temp._day += days;
		int count = 0;
		while (temp._day > (count = temp.Getday(temp._year,temp._month))) //Ϊ�ľ�����һ�κ�������
		{
			temp._day -= count;
			temp._month++;  //ע�������д��
			if (temp._month > 12)
			{
				temp._year++;
				temp._month = 1;
			}
		}
		return temp;
	}
	date operator-(int days) //ǰ�������Ǽ��¼���
	{
		date temp(*this);
		temp._day -= days;
		while (temp._day <= 0) //Ϊ�ľ�����һ�κ�������
		{
			
			temp._month--;  //ע�������д��
			if (temp._month <= 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += temp.Getday(temp._year, temp._month);
		}
		return temp;
	}
	int operator-(date& p) //��������֮����˶�����
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
	bool operator>(const date& p)  //��������֮��ȴ�С
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
		date temp(*this);  //����ʹ�õ��ǿ������캯��
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
	int Getday(int year, int month)  //�ж�������ж�����
	{
		int a[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //�·�ö��
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				return a[2]+1;  //�ж��ǲ������꣬����Ƕ��£�Ȼ������������ô�͸����¼�һ��
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
	memcpy(str2, str1, strlen(str1)+ 1);//�����Զ���������\0��Ҫ��1
	//strcpy���Զ���������\0
	memcpy(str3, "copy successful", 16);
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}
//


