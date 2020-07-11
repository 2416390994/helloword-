#include<iostream>
#include<vector>
#include<string>
#include<time.h>
using namespace std;

void printf_(vector<int>& vec)
{
	for (auto e : vec)
		cout << e << "";
	cout << endl;

}
//冒泡排序
//时间复杂度o(n^2),空间复杂度o(1)
//稳定
void maopao(vector<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 1; j < vec.size() - i; ++j)
		{
			if (vec[j] > vec[j - 1])
				swap(vec[j], vec[j - 1]);
		}
	}
	printf_(vec);
}
//插入排序
//时间复杂度o(n^2),空间复杂度o(1)
//稳定
void charu(vector<int> vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j - 1 >= 0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
	printf_(vec);
}
//选择排序
//时间复杂度o(n^2),空间复杂度o(1)
//不稳定
void xuanzepaixu(vector<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int max = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
	printf_(vec);
}
//希尔排序
//时间复杂度o(n^2),空间复杂度o(1)
//不稳定
void xierpaixu(vector<int> vec)
{
	int ges = vec.size() / 3;
	while (ges >= 1)
	{
		for (int i = ges; i < vec.size(); i += ges)
		{
			for (int j = i; j - ges >= 0 && vec[j] > vec[j - ges]; j -= ges)
			{
				swap(vec[j], vec[j - ges]);
			}
		}
		ges >>= 1;
	}
	printf_(vec);
}

//堆排序
//时间复杂度o(nlogn),空间复杂度o(1),建堆操作o(nlogn)
//不稳定
void duipaixu(vector<int> vec)
{

	//建堆
	for (int i = 0; i < vec.size(); ++i)
	{
		int j = i;
		while (vec[j] > vec[(j - 1) / 2])
		{
			swap(vec[j], vec[(j - 1) / 2]);
			j = (j - 1) / 2;
		}
	}


	//排序
	int size = vec.size();
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
				break;
			swap(vec[index], vec[great]);
			index = great;
			left = index * 2 + 1;
		}
	}
	printf_(vec);
}

//归并排序
//时间复杂度o(nlogn),空间复杂度o(n)
//稳定
void guibingpaixu2(vector<int>& vec, int L, int M, int R)
{
	int p1 = L;
	int p2 = M + 1;
	vector<int> p;
	p.resize(R - L + 1);
	int i = 0;
	while (p1 <= M && p2 <=R)
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

void func(vector<int>& vec, int L, int R)
{
	if (L < R)
	{
		int M = L + (R - L) / 2;
		func(vec, L, M);
		func(vec, M + 1, R);
		guibingpaixu2(vec, L, M, R);
	}
}

void guibingpaixu(vector<int> vec, int L, int R)
{
	func(vec, L, R);
	printf_(vec);
}

//快排
//时间复杂度o(nlogn),空间复杂度o(logn)
//不稳定
vector<int> kuaipai2(vector<int>& vec, int L, int R)
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
		{
			L++;
		}
	}
	swap(vec[more], vec[R]);
	vector<int> p;
	p.push_back(less);
	p.push_back(more + 1);
	return p;
}


void kuaipai(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		swap(vec[R], vec[L + rand() % (R - L) + 1]);
		vector<int> p = kuaipai2(vec, L, R);
		kuaipai(vec, L, p[0]);
		kuaipai(vec, p[1], R);
	}
}











int main()
{
	srand((unsigned int)time(NULL));
	vector<int> vec = { 7, 4, 1, 8, 5, 2, 0, 9, 6, 3 };
	/*maopao(vec);
	charu(vec);
	xuanzepaixu(vec);
	xierpaixu(vec);
	duipaixu(vec);
	guibingpaixu(vec, 0, 9);*/
	kuaipai(vec,0,9);
	printf_(vec);


	return 0;
}