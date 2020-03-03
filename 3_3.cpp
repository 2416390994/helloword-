#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
#define sun(a,b)  a+b
//void func(vector<int>& vec)
//{
//	for (auto e : vec)
//		cout << e << endl;
//
//}
int* func2(vector<int>& vec,int L,int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (vec[L] < vec[R])
		{
			swap(vec[L++], vec[++less]);
		}
		else if (vec[R] < vec[L])
		{
			swap(vec[L], vec[--more]);
		}
		else
			L++;
	}
	swap(vec[R], vec[more]);
	return new int[2]{less, more + 1};
}
void func(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		swap(vec[R], vec[L + rand() % (R - L) + 1]);
		int * p = func2(vec, L, R);
		func(vec, L, p[0]);
		func(vec, p[1], R);
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<int> vec{ 7, 4, 1, 0, 2, 5, 8, 9, 6, 3 };
	func(vec, 0, 9);
	for (auto e : vec)
		cout << e << endl;

	/*const int a = 10;
	int s1 = 10;
	int s2 = 10;
	cout << sun(s1, s2) << endl;*/
	return 0;
}