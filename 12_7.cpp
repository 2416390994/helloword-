#include<iostream>
#include<vector>
using namespace std;
void sort1(vector<int>& vec)
{
	int size = vec.size() - 1;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i; ++j)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}
void sort2(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		int max = i;
		for (int j = i; j < size; ++j)
		{
			if (vec[max] > vec[j])
				max = j;
		}
		swap(vec[max], vec[i]);
	}
}
void sort3(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j > 0 && vec[j] < vec[j - 1]; --j)
			swap(vec[j], vec[j - 1]);
	}
}
void sort4(vector<int>& vec)
{
	for (int gas = vec.size() >> 1; gas > 0;gas = gas >>1)
	{
		for (int i = gas; i < vec.size(); i = i + gas)
		{
			for (int j = i; j > 0 && vec[j] < vec[j - 1];j = j -gas)
				swap(vec[j], vec[j - gas]);
		}
	}
}
void func(vector<int>& vec, int L, int M, int R)
{
	int * p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M&&p2 <= R)
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
void sort5(vector<int>& vec,int L,int R)
{
	if (R == L)
		return;
	int M = L + ((R - L) / 2);
	sort5(vec, L, M);
	sort5(vec, M + 1, R);
	func(vec, L, M, R);
}
void jiandui(vector<int>&  vec, int i)
{
	while (vec[i] > vec[(i - 1) / 2])
	{
		swap(vec[i], vec[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}
void paixu(vector<int>& vec,int index,int size)
{
	int L = index * 2 + 1;
	while (L < size)
	{
		int large = L + 1 < size && vec[L + 1] > vec[L] ? L + 1 : L;
		large = vec[large] > vec[index] ? large : index;
		if (large == index)
			break;
		swap(vec[large], vec[index]);
		index = large;
		L = index * 2 + 1;
	}
}
void sort6(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		jiandui(vec, i);
	}
	int size = vec.size();
	while (size > 0)
	{
		swap(vec[0], vec[--size]);
		paixu(vec,0,size);
	}
}
void sort7(vector<int>& vec)	
{

}
int main()
{
	vector<int> vec{ 2, 5, 9, 7, 8, 6, 4, 3, 1, 0 };
	//sort1(vec);
	//sort2(vec);
	//sort3(vec);
	//sort4(vec);
	//sort5(vec, 0, vec.size() - 1);
	//sort6(vec);
	sort7(vec);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	return 0;
}