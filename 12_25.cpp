#include<iostream>
#include<vector>
using namespace std;
void sort1(vector<int>& a)
{
	int size = a.size();
	for (int i = 0; i < size- 1; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void sort2(vector<int>& a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; ++i)
	{
		int max = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (a[j] > a[max])
				max = j;
		}
		swap(a[max], a[i]);
	}
}
void sort3(vector<int>& a)
{
	int size = a.size();
	for (int i = 1; i < size; ++i)
	{
		for (int j = i; j > 0 && a[j] > a[j - 1]; --j)
			swap(a[j], a[j - 1]);
	}
}
void sort4(vector<int>& a)
{
	int gas = a.size() / 2;
	while (gas > 1)
	{
		int size = a.size();
		for (int i = gas ; i < size; i = i + gas)
		{
			for (int j = i; j > 0 && a[j] > a[j - gas]; j = j - gas)
				swap(a[j], a[j - gas]);
		}
		gas = gas >> 1;
	}
}
int main()
{
	vector<int> a = { 0, 5, 9, 7, 6, 4, 3, 1, 8, 2};
	sort4(a);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;
	return 0;
}