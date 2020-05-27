#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct INT
{
	double f;
	char a;
	char b;
	char c;
	char d;
};
int main()
{
	cout << sizeof(INT) << endl;
	/*int a;
	cin >> a;
	vector<int> vec;
	for (int i = 0; i < a; ++i)
	{
		int b;
		cin >> b;
		vec.push_back(b);
	}
	int k;
	cin >> k;
	sort(vec.begin(), vec.end());
	int count = 1;
	int x = vec[0];
	for (int i = 0; i < vec.size(); ++i)
	{
		if (count == k && (vec[i] != x))
		{
			cout << vec[i] << endl;
			return 0;
		}
		if (i == 0)
		{
			x = vec[i];
		}
		else
		{
			if (x == vec[i])
			{
			}
			else
			{
				count++;
				x = vec[i];
			}
			if (count == k)
			{
				cout << vec[i] << endl;
				return 0;
			}
		}
	}*/



	return 0;
}