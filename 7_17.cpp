#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<memory>
using namespace std;
int w[6] = { 0, 1, 2, 3, 4, 5 };
int v[6] = { 0, 1, 2, 3, 4, 5 };
int vec[6][21] = { 0 };

void func()
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (w[i] > j)
			{
				vec[i][j] = vec[i - 1][j];
			}
			else
			{
				int val1 = vec[i - 1][j];
				int val2 = vec[i - 1][j - w[i]] + v[i];
				vec[i][j] = val1 > val2 ? val1 : val2;
			}
		}
	}
}

//øÏ≈≈
vector<int> func2(vector<int>& vec,int L,int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (vec[L] < vec[R])
		{
			swap(vec[L++], vec[++less]);
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
	swap(vec[more], vec[R]);;
	vector<int> vec1;
	vec1.push_back(less);
	vec1.push_back(more + 1);

	return vec1;
}


void func1(vector<int>& vec, int L, int R)
{
	if (L < R)
	{
		swap(vec[R], vec[L + rand() % (R - L) + 1]);
		vector<int> vec1 = func2(vec, L, R);
		func1(vec, L, vec1[0]);
		func1(vec, vec1[1], R);
	}
}

//πÈ≤¢≈≈–Ú
void func4(vector<int>& vec,int L,int M,int R)
{
	int i = 0;
	int p1 = L;
	int p2 = M + 1;
	int* p = new int[R - L + 1];
	while (p1 <= M && p2 <= R)
	{
		p[i++] = vec[p1] < vec[p2] ? vec[p1++] : vec[p2++];
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


void func3(vector<int>& vec,int L,int R)
{
	if (L < R)
	{
		int M = (R + L) / 2;
		func3(vec,L, M);
		func3(vec,M + 1, R);
		func4(vec, L, M, R);
	}
}

void func(TreeNode* tree)
{
	stack<TreeNode*> std;
	TreeNode* p = tree;
	TreeNode* r = nullptr;
	while (p || !std.empty())
	{
		if (p)
		{
			std.push(p);
			p = p->left;
		}
		else
		{
			p = std.top();
			if (p->right && p->right != r)
			{
				p = p->right;
			}
			else
			{

			}
		}
	}

}





















int main()
{
	srand((unsigned int)time(NULL));
	vector<int> vec = { 7, 4, 1, 8, 5, 2, 0, 9, 6, 3 };
	func3(vec, 0, 9);



	for (auto e : vec)
	{
		cout << e << " ";
	}
	
	shared_ptr<int> sts(new int(1));


	return 0;
}