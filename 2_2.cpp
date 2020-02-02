#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
void func1(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - 1; ++j)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}
void func2(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		int max = i;
		for (int j = i; j < vec.size(); ++j)
		{
			if (vec[max] > vec[j])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
}
void func3(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j >0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
}
void func4(vector<int>& vec)
{
	int ges = vec.size() / 3;
	while (ges >= 1)
	{
		for (int i = ges; i < vec.size(); i = i + ges)
		{
			for (int j = i; j >0 && vec[j] > vec[j - ges]; j = j - ges)
				swap(vec[j], vec[j - ges]);
		}
		ges = ges / 2;
	}
}

void func5(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		while (vec[i] > vec[(i - 1) / 2])
		{
			swap(vec[i], vec[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
	size_t size = vec.size();
	while (size)
	{
		swap(vec[--size], vec[0]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
			great = vec[index] > vec[great] ? index : great;
			if (great == index)
				break;
			swap(vec[index], vec[great]);
			index = great;
			left = index * 2 + 1;
		}
	}
}

void func6_1(vector<int>& vec,int L,int M, int R)
{
	int * p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = vec[p1] > vec[p2] ? vec[p1++] : vec[p2++];
	}
	while (p1 <= M)
	{
		p[i++] = vec[p1++];
	}
	while (p2 <= R)
	{
		p[i++] = vec[p2++];
	}
	for (int i = 0; i < R - L + 1; ++i)
	{
		vec[L + i] = p[i];
	}
}
void func6(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		int M = (R + L) / 2;
		func6(vec, L, M);
		func6(vec, M + 1, R);
		func6_1(vec, L, M + 1, R);
	}
}
int* func7_1(vector<int>& vec,int L,int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (vec[L] < vec[R])
		{
			swap(vec[++less], vec[L]);
		}
		else if (vec[L] > vec[R])
		{
			swap(vec[--R], vec[L++]);
		}
		else
			L++;

	}
	swap(vec[R], vec[more]);
	return new int[] {less, more - 1};
}

void func7(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		srand((unsigned int)int(NULL));
		swap(vec[R], vec[L + rand() % (R - L) + 1]);
		int* p = func7_1(vec, L, R);
		func7(vec, L, p[0]);
		func7(vec, p[1], R);
	}
}


int main()
{
	vector<int> vec{ 8, 5, 2, 0, 7, 4, 1, 9, 6, 3 };

	return 0;
}