#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;

///√∞≈›≈≈–Ú
void func1(vector<int> vec)
{
	size_t size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

//≤Â»Î≈≈–Ú
void func2(vector<int> vec)
{
	size_t size = vec.size();
	for (int i = 1; i < size; ++i)
	{
		for (int j = i; j > 0 && vec[j] > vec[j - 1]; --j)
			swap(vec[j], vec[j - 1]);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

//—°‘Ò≈≈–Ú
void func3(vector<int> vec)
{
	size_t size = vec.size();
	int max = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

//œ£∂˚≈≈–Ú
void func4(vector<int>& vec)
{
	int ges = vec.size() / 2;
	while (ges >= 1)
	{
		for (int i = 1; i < vec.size(); i += ges)
		{
			for (int j = i; (j -ges) >= 0 && vec[j] > vec[j - ges]; j -= ges)
				swap(vec[j], vec[j - ges]);
		}
		ges = ges / 2;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

//∂—≈≈–Ú
void func5(vector<int> vec)
{
	//Ω®¥Û∂—
	for (int i = 1; i < vec.size(); ++i)
	{
		while (vec[i] > vec[(i - 1) / 2])
		{
			swap(vec[i] , vec[(i - 1) / 2]);
		}
	}

	//≈≈…˝–Ú
	size_t size = vec.size();
	while (size--)
	{
		swap(vec[0], vec[size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
			great = vec[index] > vec[great] ? index : great;
			if (great == index)
			{
				break;
			}
			swap(vec[great], vec[index]);
			index = great;
			left = index * 2 + 1;
		}
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}


void func6_2(vector<int>& vec, int L, int M, int R)
{
	int* p = new int[R - L + 1];
	int p1 = L;
	int p2 = M + 1;
	int i = 0;
	while (p1 <= M && p2 <= R)
	{
		p[i++] = vec[p1] >vec[p2] ? vec[p1++] : vec[p2++];
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

//πÈ≤¢≈≈–Ú
void func6(vector<int>& vec,int L,int R)
{
	if (L == R)
		return;
		int M = (R + L) / 2;
		func6(vec, L, M);
		func6(vec, M + 1, R);
		func6_2(vec, L, M, R);
}

int* func7_2(vector<int>& vec, int L, int R)
{
	int more = R;
	int less = L - 1;
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
		{
			L++;
		}
	}
	swap(vec[more], vec[R]);
	return new int[]{less,more + 1};
}

//øÏ≈≈
void func7(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		srand((unsigned int)time(NULL));
		swap(vec[L + rand() % (R - L) + 1], vec[R]);
		int* p = func7_2(vec, L, R);
		func7(vec, L, p[0]);
		func7(vec, p[1], R);
	}
}

	
int main()
{
	vector<int> vec{ 7, 4, 1, 8, 5, 2, 0, 9, 6, 3 };
	/*func1(vec);
	func2(vec);
	func3(vec);*/
	func4(vec);
	//func5(vec);
	//func6(vec, 0, 9);
	//func7(vec, 0, 9);
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	
	return  0;
}