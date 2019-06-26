#include<algorithm>
#include<vector>
#include<iostream>
using  namespace std;
int main()
{
	int sum = 0;
	int n;
	cin >> n;
	vector<int>v;
	v.resize(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> v[i];
	}
	std::sort(v.begin(), v.end());
	for (int i = n; i <= 3 * n - 2; i += 2)
	{
		sum += v[i];
	}
	cout << sum ;
	return 0;
}