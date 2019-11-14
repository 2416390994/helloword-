#include<iostream>
using namespace std;
int main()
{
	int c;
	int d;
	cin >> c;
	cin >> d;
	if (c < d)
	{
		swap(c, d);
	}
	int flag = 0;
	for (int i = 2; i <= d; ++i)
	{
		if (c % i == 0 && d % i == 0)
		{
			d = d / i;
			flag = 1;
		}
		if (flag == 1)
		{
			i = 2;
			flag = 0;
		}
	}
	cout << c*d;
	return 0;
}