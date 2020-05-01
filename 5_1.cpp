#include<iostream>
#include<string>
#include<vector>
using namespace std;



//explicit   防止函数的默认转换
class data
{
	friend ostream& operator<<(ostream& _count, data& s);
public:
	static void func()
	{
		cout << "hello" << endl;
	}
	int a = 22;
private:
	int e = 20;
	static int b;
};
ostream& operator<<(ostream& _cout, data& s)
{
	_cout << s.e;
	return _cout;
}

int data::b = 20;
void func()
{
	data A;
	A.func();
	data::func();
	cout << sizeof(data) << endl;
	cout << A << endl;
	data* p = (data*)malloc(sizeof(data));
	new(p)data();

	cout << (*p).a << endl;
}



int main()
{

	func();
	//decltype();

	return 0;
}