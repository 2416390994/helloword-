#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;
int func4(int num)
{
	if (num <= 0)
		return 0;
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;
	return func4(num - 1) + func4(num - 2);
}

void maopaopaixu(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - 1 - i; ++j)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}

void xuanzepaixu(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		int max = i;
		for (int j = i; j < vec.size(); ++j)
		{
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[max], vec[i]);
	}
}

void charupaixu(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j > 0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
}

void xierpaixu(vector<int>& vec)
{
	int ges = vec.size();
	while (ges >= 1)
	{
		for (int i = ges; i < vec.size(); i += ges)
		{
			for (int j = i; j >0 && vec[j] > vec[j - ges]; j -= ges)
			{
				swap(vec[j], vec[j - ges]);
			}
		}
		ges >>= 1;
	}
}

void duipaixu(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int j = i;
		while (vec[j] > vec[(j - 1) / 2])
		{
			swap(vec[j], vec[(j - 1) / 2]);
			j = (j - 1) / 2;
		}
	}
	int size = vec.size();
	while (--size)
	{
		swap(vec[0], vec[size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
			great = vec[index] > vec[great] ? index : great;
			if (index == great)
				break;
			swap(vec[index], vec[great]);
			index = great;
			left = index * 2 + 1;
		}
	}
}
int* func1(vector<int>& vec, int L, int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (vec[L] < vec[R])
		{
			swap(vec[++less], vec[L++]);
		}
		else if (vec[L] > vec[R])
		{
			swap(vec[L], vec[--more]);
		}
		else
			L++;
	}
	swap(vec[R], vec[more]);
	return new int[]{less, more + 1};
}


void kuaipai(vector<int>& vec, int L, int R)
{
	if (L < R)
	{
		srand((unsigned int)time(NULL));
		swap(vec[L], vec[L + rand() % (R - L) + 1]);
		int* p = func1(vec, L, R);
		kuaipai(vec, L, p[0]);
		kuaipai(vec, p[1], R);
	}
}

void func2(vector<int>& vec,int L,int M,int R)
{
	int* p = new int[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
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

void guibingpaixu(vector<int>& vec, int L, int R)
{
	if (L < R)
	{
		int M = (R + L) / 2;
		guibingpaixu(vec, L, M);
		guibingpaixu(vec, M + 1, R);
		func2(vec, L, M, R);
	}
}

void erfenchazhao(vector<int>& vec,int num)
{
	int L = 0;
	int R = vec.size();
	int M = 0;
	while (L < R)
	{
		M = (R + L) / 2;
		if (num < vec[M])
		{
			R = M;
		}
		else if (num > vec[M])
		{
			L = M + 1;
		}
		else
		{
			cout << M << endl;
			break;
		}
	}
}






int main()
{
	vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//maopaopaixu(vec);
	//xuanzepaixu(vec);
	//charupaixu(vec);
	//xierpaixu(vec);
	//duipaixu(vec);
	//kuaipai(vec, 0, 9);
	//guibingpaixu(vec, 0,9);

	erfenchazhao(vec,10);

	/*for (auto e : vec)
		cout << e << endl;
*/

	//func4(100);
	return 0;
}