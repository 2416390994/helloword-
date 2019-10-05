//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	friend ostream& operator<<(ostream& _cout,A s )
//	{
//		_cout << s.a;
//		return _cout;
//	}
//	int funx()
//	{}
//private:
//	int a = 10;
//};
//int main()
//{
//	A s;
//	s.funx();
//	cout << s << endl;
//	return 0;
//}
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "almost every programmer should know memset!";
	memset(str, 65, 6);
	puts(str);
	return 0;
}


















