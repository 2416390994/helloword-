#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
namespace sort
{
	void func1(vector<int>& vec)
	{
		for (int i = 0; i < vec.size() - 1; ++i)
		{
			for (int j = 0; j < vec.size() - 1; ++j)
			{
				if (vec[j] > vec[j + 1])
				{
					swap(vec[j], vec[j + 1]);
				}
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
				if (vec[j] > vec[max])
				{
					max = j;
				}
			}
			swap(vec[max], vec[i]);
		}
	}
	void func3(vector<int>& vec)
	{
		for (int i = 1; i < vec.size(); ++i)
		{
			for (int j = i - 1; j >0 && vec[j] > vec[j - 1]; --j)
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
				for (int j = i - ges; j >0 && vec[j] > vec[j - ges]; j = j - ges)
				{
					swap(vec[j], vec[j - ges]);
				}
			}
			ges = ges >> 1;
		}
	}

	/*void func5(vector<int>& vec)
	{

		for (int i = 0; i < vec.size(); ++i)
		{
			while (vec[i] > vec[(i - 1) / 2])
			{
				swap(vec[i], vec[(i - 1) / 2]);
				i = (i - 1) / 2;
			}
		}
		int size = vec.size();
		while (size > 0)
		{
			swap(vec[--size], vec[0]);
			int index = 0;
			int left = (index * 2) + 1;
			while (left < size)
			{
				int greap = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
				greap = vec[index] > vec[greap] ? index : greap;
				if (index == greap)
					break;
				swap(vec[index], vec[greap]);
				index = greap;
				left = (index * 2) + 1;
			}
		}
	}*/
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
		int size = vec.size();
		while (size > 0)
		{
			swap(vec[--size], vec[0]);
			int index = 0;
			int left = (index * 2) + 1;
			while (left < size)
			{
				int greap = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
				greap = vec[index] > vec[greap] ? index : greap;
				if (index  == greap )
					break;
				swap(vec[index], vec[greap]);
				index = greap;
				left = (index * 2) + 1;
			}
		}
	}
	void ss(vector<int>& vec, int L,int M, int R)
	{
		int *p = new int[R - L + 1];
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
	void func6(vector<int>& vec,int L,int R)
	{
		if (L == R)
			return;
		int M = (R + L) / 2;
		func6(vec, L, M);
		func6(vec, M + 1, R);
		ss(vec, L, M, R);
	}
	int*  ww(vector<int>& vec,int L,int R)
	{
		int less = L - 1;
		int mose = R;
		while (L <mose)
		{
			if (vec[L] < vec[R])
			{
				swap(vec[L++], vec[++less]);
			}
			else if (vec[L] > vec[R])
			{
				swap(vec[L], vec[--mose]);
			}
			else
			{
				L++;
			}
		}
		swap(vec[L], vec[R]);
		return new int[] {less,mose + 1};
	}
	void func7(vector<int>& vec,int L,int R)
	{
		if (L < R)
		{
			swap(vec[L + rand() % (R - L) + 1], vec[R]);
			int* p = ww(vec, L, R);
			func7(vec, L, p[0]);
			func7(vec, p[1], R);
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<int> vec{ 2, 5, 8, 9, 6, 3,3, 1, 4, 7, 0 };
	//sort::func1(vec);
	//sort::func2(vec);
	//sort::func3(vec);
	//sort::func4(vec);
	//sort::func5(vec);
	//sort::func6(vec, 0, 9);
	sort::func7(vec, 0, 9);
	for (auto e : vec)
		cout << e << endl;

	return 0;
}