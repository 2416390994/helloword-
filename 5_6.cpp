#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
void func()
{
	int a = 10;
	int& b = a;
	int c = 20;
	b = c;
	cout << a << endl;
}
bool func2(vector<int> push_V,vector<int> pop_V)
{
	int i = 0;
	int j = 0;
	stack<int> sta;
	while (i < push_V.size() || j < pop_V.size())
	{
		if (sta.empty())
		{
			sta.push(push_V[i++]);
		}
		if (sta.top() != pop_V[i])
		{
			sta.push(push_V[i++]);
		}
		else
		{
			sta.pop();
			j++;
		}
	}
	if (i == push_V.size() && j == pop_V.size())
	{
		return true;
	}
	else
		return false;
}
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node()
		:left(nullptr)
		, right(nullptr)
	{}
};

void func3(Node* tree)
{
	if (tree == nullptr)
		return;
	queue<Node*> que;

	que.push(tree);
	while (!que.empty())
	{
		Node* p = que.front();
		cout << que.front() << endl;
		if (p->left)
			que.push(p->left);
		if (p->right)
			que.push(p->right);
		que.pop();
	}
}
void func4(Node* tree)
{
	vector<vector<int>> vec;
	queue<Node*> que;

	que.push(tree);
	while (!que.empty())
	{
		vector<int> vec;
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			Node* cur = que.front();
			if (cur->left)
				que.push(cur->left);
			if (cur->left)
				que.push(cur->left);

			vec.push_back(cur->val);
			que.pop();
		}
	}

}



int main()
{
	//priority_queue<int, vector<int>, less<int>> que;
	priority_queue<int, vector<int>, greater<int>> que;

	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	make_heap(vec.begin(), vec.end());
	/*for (auto e : vec)
		cout << e << endl;*/

	vector<int> vec1 = { 11, 21, 31, 41, 51, 61, 71, 8, 9 };
	push_heap(vec1.begin(), vec1.end());
	for (auto e : vec)
		cout << e << endl;
	//func();
	//func3();
	
	return 0;

}