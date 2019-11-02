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
//ģ����ػ�
//template<>
//char*& MAX<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 1)  ///strcmp���ڷ���1��С�ڷ���-1
//		return left;
//	return right;
//}
//template<>
//const char*& MAX<char*const &>(char*const & left, const char*& right)
//{
//	if (strcmp(left, right) == 1)  ///strcmp���ڷ���1��С�ڷ���-1
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
//void func(const T& p)    //��ô���ճ������Ʋ����const int*& p ,Ҳ����˵const���ε���p��ֻ��Ŀռ���������ݲ����޸�
//{
//	*p = 100;  //���������޸���
//}
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	func(p);   //���ﴫ����int* ����
//	cout << a << endl;  //�������ⲿ������������ӡ��100
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
	cout << MAX(a, b) << endl;   //�������Ϳ���ֱ�ӱȽ�
	cout << MAX(b, a) << endl;
	Date d1(2019, 10, 22);   //�Զ���������Ҫ�����н��ȽϷ�ʽ��������ô�Ϳ���ʹ��MAX���������бȽ���
	Date d2(2019, 10, 23);
	/*cout << MAX(d1, d2) << endl;
	cout << MAX(d2, d1) << endl;*/
	//�����е����Ͳ��ܴ������ߴ���������Ǵ���
	//ͨ������¿���ʹ��ģ��ʵ��һЩ�������޹صĴ��룬���Ƕ���һЩ�������͵õ��ľ��Ǵ�������
	char* p1 = "world";
	char* p2 = "hello";
	cout << MAX(p1, p2) << endl;   //��ӡ�������
	cout << MAX(p2, p1) << endl;  
	int w = 10;
	const int *ww = &w;
	cc(&ww);
	cout << w << endl;
	return 0;
}







