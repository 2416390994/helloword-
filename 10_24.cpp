//#include<iostream>
//using namespace std;
////void sort_1(int *a,int L,int mid,int R)
//{
//	int * p = new int[R - L];
//	int p1 = L;
//	int p2 = mid+1;
//	int i= 0;
//	while (p1 <= mid&&p2<=R)
//	{
//		p[i++] = a[p1] > a[p2] ? a[p1++] : a[p2++];
//	}
//	while (p1 <= mid)
//	{
//		p[i++] = a[p1++];
//	}
//	while (p2 <= R)
//	{
//		p[i++] = a[p2++];
//	}
//	int length = R - L+1;
//	for (int j = 0; j < length; ++j)
//	{
//		a[L + j] = p[j];
//	}
//}
//void func(int *a,int begin,int end)
//{
//	if (begin == end)
//		return;
//	int mid = begin + ((end - begin) >> 1);
//	func(a, begin, mid);
//	func(a, mid+1, end);
//	sort_1(a, begin, mid, end);
//}
//class time
//{
//public:
//	time()
//	{
//		cout << "132" << endl;
//	}
//	int a;
//
//};
//class Date
//{
//public:
//	Date()
//	{}
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void printDate()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	time a;
//};
//
//int main()
//{
//	
//	Date d;
//	d.SetDate(2019, 10, 24);
//	d.printDate();
//	/*int a[] = { 2, 5, 9, 7, 8, 6, 1, 4, 3, 0 };
//	func(a, 0, 9);
//	for (auto e : a)
//		cout << e << endl;*/
//	return 0;
//}
//typedef struct _stack
//{
//	int* first;
//	int size;
//}_stack;
//void init(_stack &s)
//{
//	s.first = new int[10];
//	s.size = 0;
//}
//void _pop(_stack & s)
//{
//	if (s.size != 0)
//		s.size--;
//}
//void _push(_stack& s,int c)
//{
//	if (c == -1)
//	{
//		if (s.size != 0)
//		{
//			_pop(s);
//			return;
//		}
//		return;
//	}
//	s.first[s.size] = c;
//	s.size++;
//	if (s.size == 10)
//		cout << "栈已满" << endl;
//}
//int main()
//{
//	_stack s;
//	init(s);
//	
//	return 0;
//}
/*
void string(char *  s = "")
{
	if(s == "")
	{
		s = "";
	}
	_str = new char[strlen(s)+1];
	strlen(_str,str);
}
*/
//template<class T>
//T& operator=(const T& s)
//{
//	if (this != &s)
//	{
//		//进行你想要进行的操作
//	}
//	return *this;
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//double add(double a, double b)
//{
//
//	return a + b;
//}
//template<class T>
//
//T& operator++()  //前置++  ，需要连加所以返回引用
//{
//	return *this;
//}
//template<class T>
//T operator++(int)//后置++  ,不需要连加，所以返回值
//{
//	//保存旧值
//	T temp(*this);
//	return temp;
//}
//int main()
//{
//	double c = add(1.0, 2.0);
//	return 0;
//}
//根据输入的日期判断，这个日期是今年的第多少天
//int Getday(int year, int mouth)
//{
//	int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return day[2] += 1;
//	}
//	return day[mouth];
//}
//bool isValidDay(int year, int mouth, int day)
//{
//	if (year > 0 && (mouth > 0 && mouth <= 12) && (day > 0 && day <= Getday(year, mouth)))
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	int year;
//	int mouth;
//	int day;
//	int result;
//	cin >> year >> mouth >> day;
//	if (isValidDay(year,mouth,day))
//	{
//		for (int i = 1; i < mouth; ++i)
//		{
//			result += Getday(year, i);
//		}
//		result += day;
//		cout << result << endl;
//	}
//	else
//	{
//		return -1;
//	}
//	return 0;
//}
//class a
//{
//public:
//	const int get()
//	{
//		cout << s << endl;
//	}
//	int s = 0;
//};
//int main()
//{
//	a b;
//	
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string s1;
	int a[500] = { 0 };
	while (cin >> s)
	{
		for (int i = 0; i<s.size(); ++i)
		{
			if (a[s[i]] == 0)
			{
				s1.push_back(s[i]);
				a[s[i]] = 1;
			}
		}
		for (int i = 0; i<s1.size(); ++i)
		{
			cout << s1[i];
		}
	}
	return 0;
}