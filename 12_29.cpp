#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>& a,int L,int M,int R)
{
	int* p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = a[p1] > a[p2] ? a[p1++] : a[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = a[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = a[p2++];
	}
	for (int j = 0; j < i; ++j)
	{
		a[L + j] = p[j];
	}
}
void func(vector<int>& vec, int L, int R)
{
	if (L == R)
		return;
	int M = L + ((R - L) / 2);
	func(vec, L, M);
	func(vec, M + 1, R);
	sort(vec, L, M, R);
}
int main()
{
	vector<int> vec = { 2, 5, 3, 0, 9, 8, 7, 4, 1, 3, 6 };
	func(vec, 0, vec.size() - 1);
	for (int i = 0;i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	return 0;
}