#include<iostream>
#include<vector>
using namespace std;
#define INT 100;
#define SUN(a , b) a + b;
typedef   int uns;
void func(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - 1 - i; ++j)
		{
			if (vec[j] < vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}

void func1(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		int max = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[j] > vec[max])
				max = j;
		}
		swap(vec[i], vec[max]);
	}
}
void func2(vector<int>& vec)
{
	for (int i = 1; i < vec.size(); ++i)
	{
		for (int j = i; j > 0 && vec[j] > vec[j - 1]; --j)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
}
void func3(vector<int>& vec)
{
	int ges = vec.size() / 3;
	while (ges >= 1)
	{
		for (int i = ges; i < vec.size(); i += ges)
		{
			for (int j = i; j > 0 && vec[j] > vec[j - ges]; j-= ges)
			{
				swap(vec[j], vec[j - ges]);
			}
		}
		ges = ges / 3;
	}

}
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val)
		:val(_val)
		, left(nullptr)
		, right(nullptr)
	{
	}
};

bool func5(TreeNode* tree)
{
	if (tree == nullptr)
		return false; 
}

void func6(vector<int>& vec)
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
			great = vec[great] > vec[index] ? great : index;
			if (great == index)
			{
				break;
			}
			swap(vec[great], vec[index]);
			index = left;
			left = index * 2 + 1;
		}
	}
}
void func7(vector<int>& vec,int R)
{




}



int main()
{
	vector<int> vec{ 0, 2, 5, 8, 7, 4, 1, 3, 6, 9 };
	//func(vec);
	//func1(vec);
	//func2(vec);
	//func3(vec);
	//func6(vec);
	func7(vec,9);



	/*int g_a = 10;
	int a = 3, b = 4;
	auto fs = [=, &g_a]{return a + 3; };
	*/
	for (auto e : vec)
		cout << e << endl;
	return 0;
}