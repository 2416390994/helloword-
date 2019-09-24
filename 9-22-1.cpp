#include<iostream>
using namespace std;
int main()
{
	char* str = "123456789";
	char* p = str;
	while (*(++p) != '\0')
	{}
	while (--p >= str)
		cout << *p << endl;
	return 0;
}