#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
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
	while (gas >= 1)
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
void sort5(vector<int>& a)
{
	int size = a.size();
	if (size <= 0)
		return;
	for (int i = 1; i  <  size; ++i)
	{
		int left = i;
		while (left > 0)
		{
			if (a[left] > a[(left - 1) / 2])
				swap(a[left], a[(left - 1) / 2]);
			left = (left - 1) / 2;
		}
	}
	int size1 = a.size();
	while (size  > 0)
	{
		swap(a[0], a[--size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int length = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;
			length = a[index] > a[length] ? index : length;
			if (index == length)
				break;
			swap(a[index], a[length]);
			left = index * 2 + 1;
			index = length;
		}
	}
}
int* sort6(vector<int>& a,int L,int R)
{
	int right = R;
	int less = L - 1;
	while (L < right)
	{
		if (a[L] < a[R])
		{
			swap(a[L++], a[++less]);
		}
		else if (a[L] > a[R])
		{
			swap(a[--right], a[L]);
		}
		else
		{
			L++;
		}
	}
	swap(a[right], a[R]);
	
	return new int[]{ less, right + 1 };
}
void sort7(vector<int>& a,int L,int R)
{
	srand((unsigned int)time(NULL));
	if (L < R)
	{
		swap(a[L + rand() % (R - L) + 1], a[R]);
		int *b = sort6(a, L, R);
		sort7(a, L, b[0]);
		sort7(a, b[1], R);
	}
}
void sort8(vector<int>& a,int L,int M,int R)
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
	for (i = 0; i < R - L + 1; ++i)
	{
		a[L + i] = p[i];
	}
}
void sort9(vector<int>& a,int L,int R)
{
	if (L < R)
	{
		int M = L + ((R - L) >> 1);
		sort9(a, L, M);
		sort9(a, M + 1, R);
		sort8(a, L, M, R);
	}
}
int main()
{
	//vector<int> a = { 0, 5, 9, 7, 6, 4, 3, 1, 8, 2};
	vector<int> a = { 2, 5, 8, 9, 7, 4, 6, 3, 1, 5 };;
	sort9(a,0,a.size() -  1);
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;
	return 0;
}