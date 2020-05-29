#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
	vector<int> vec = { 8, 5, 2, 1, 4, 7, 9, 6, 3, 0 };
	sort(vec.begin(), vec.end());
	for (auto e : vec)
		cout << e << " ";
	
	sort(vec.begin(), vec.end(),greater<int>());

	for (auto e : vec)
		cout << e << " ";

	return 0;
}