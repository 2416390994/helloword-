#include<iostream>
using namespace std;
int getTotalCount(int month)
{
	int count = 0;
	if (month <= 2)
		return 1;
	return getTotalCount(month - 2) + getTotalCount(month - 1);
}
//int func(int month)
//{
//	for ()
//	getTotalCount(month)
//}
int main()
{
	int c;
	while (cin >> c)
	{
		cout << getTotalCount(c) << endl;
	}
	return 0;
}