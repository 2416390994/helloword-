#include<iostream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
void func1(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - i - 1; ++j)
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
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
}

void func3(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j > 0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
}

void func4(vector<int>& vec)
{
	int ges = vec.size() / 2;
	while (ges >= 1)
	{
		for (int i = ges; i < vec.size(); i += ges)
		{
			for (int j = i; j > 0 && vec[j] > vec[j - ges]; j -= ges)
				swap(vec[j], vec[j - ges]);
		}
		ges = ges / 3;
	}
}

void func5(vector<int>& vec)
{
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		int j = i;
		while (vec[j] > vec[(j - 1) / 2])
		{
			swap(vec[j], vec[(j - 1) / 2]); 
			j = (j - 1) / 2;
		}
	}
	while (--size)
	{
		swap(vec[0], vec[size]);
		int index = 0;
		int left = index * 2 + 1;
		while (left < size)
		{
			int great = left + 1 < size && vec[left + 1] > vec[left] ? left + 1 : left;
			great = index > great ? index : great;
			if (great == index)
				break;
			swap(vec[index], vec[great]);
			
			index = great;
			left = index * 2 + 1;
		}
	}
}

//归并排序
void func7(vector<int>& vec,int L,int M,int R)
{
	int* p = new int[R - L + 1];
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
void func6(vector<int>& vec, int L, int R)
{
	if (L < R)
	{
		int M = (R + L) / 2;
		func6(vec, L, M);
		func6(vec, M + 1, R);
		func7(vec, L, M, R);
	}
}

//快排
int* func9(vector<int>& vec,int L,int R)
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
			swap(vec[--more], vec[L]);
		}
		else
			L++;
	}
	swap(vec[R], vec[more]);
	return new int[]{less, more + 1};
}

void func8(vector<int>& vec, int L, int R)
{
	if (L < R)
	{
		srand((unsigned int)time(NULL));
		swap(vec[R], vec[L + rand() % (R - L) + 1]);
		int* p = func9(vec, L, R);
		func8(vec, L, p[0]);
		func8(vec, p[1], R);
	}
}
struct Node
{
	Node* next;
	int val;
};

//判断一个链表是否带环
bool func10(Node* list)
{


}





int main()
{
	vector<int> vec{ 4, 5, 6, 7, 8, 9, 1, 2, 3, 0 };
	//func1(vec);
	//func2(vec);
	//func3(vec);
	//func4(vec);
	//func5(vec);
	//func6(vec,0,9);
	func8(vec,0,9);



	for (auto e : vec)
		cout << e << endl;
	return 0;
}