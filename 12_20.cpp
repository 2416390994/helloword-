//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void func(int num)
//{
//	vector<int> vec;
//	vec.resize(num);
//	int i1 = 0, i2 = 0, i3 = 0;
//	vec[0] = 1;
//	int count = 1;
//	while (count < num)
//	{
//		vec[count] = min(min(vec[i1] * 2, vec[i2] * 3), vec[i3] * 5);
//		if (vec[count] == vec[i1] * 2)
//			++i1;
//		if (vec[count] == vec[i2] * 3)
//			++i2;
//		if (vec[count] == vec[i3] * 5)
//			++i3;
//		++count;
//	}
//	cout << vec[count - 1] << endl;;
//}
//int main()
//{
//	func(10);
//	return 0;
//}
//#include<iostream>
//#include<map>
//#include<string>
//#include<vector>
//using namespace std;
//void func(vector<string>& str)
//{
//	map<string, int> map1;
//	vector<vector<string>> vecvec;
//	int w = 0;
//	while (!str.empty())
//	{
//		vector<int> vec;
//		vec.resize(26);
//		int i = 0;
//		for (int j = 0; j < str[i].size(); ++j)
//		{
//			vec[str[i][j] - 'a']++;
//		}
//		string str1;
//		for (int k = 0; k < vec.size(); ++k)
//		{
//			str1 += to_string(vec[k]);
//		}
//		if (map1.find(str1) != map1.end())
//		{
//			auto it = map1.find(str1);
//			vecvec[(*it).second].push_back(str[i]);
//		}
//		else
//		{
//			map1.insert(make_pair(str1, w));
//			vector<string>* v = new vector<string>;
//			v->push_back(str[i]);
//			vecvec.push_back(*v);
//			w++;
//		}
//		++i;
//	}
//}
#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int process(vector<vector<int>> vec,int row,int col)
{
	int path = 1;
	if (col > 0 && vec[row][col - 1] > vec[row][col])  //向左
		path = max(path, process(vec, row, col - 1) + 1);
	if (row > 0 && vec[row - 1][col] > vec[row][col])  //向上
		path = max(path, process(vec, row - 1, col) + 1);
	if (row < vec.size() - 1 && vec[row + 1][col] > vec[row][col])  //向下
		path = max(path, process(vec, row + 1, col) + 1);
	if (col < vec[0].size() - 1 && vec[row][col + 1] > vec[row][col])  //向右
		path = max(path, process(vec, row, col + 1) + 1);
	return path;
}
int func(vector<vector<int>> vec)
{
	int maxsex = 0;
	for (int row = 0; row < vec.size(); ++row)
	{
		for (int col = 0; col < vec[0].size(); ++col)
		{
			maxsex = max(maxsex,process(vec, row, col));
		}
	}
	return maxsex;
}
int main()
{
	int c = 10;
	int *a = nullptr;
	int*& b = a;
	//int& d = c;
	//vector<vector<int>> vec;
	//vector<int> vec1 = { 9, 9, 8 };
	//vector<int> vec2 = { 7, 6, 7 };
	//vector<int> vec3 = { 2, 1, 1 };
	//vec.push_back(vec1);
	//vec.push_back(vec2);
	//vec.push_back(vec3);
	//cout << func(vec) << endl; // 返回5 [1,6,7,8,9]
	return 0;
}
#endif
#include<iostream>
#include<assert.h>
using namespace std;
struct Node
{
	int val;
	Node*  next;
	Node(int num)
	{
		val = num;
		next = nullptr;
	}
};
struct List
{
	Node* head = nullptr;
};
void init(List& list)
{
	assert(list.head == nullptr);
	list.head = new Node(0);
}
void push(List& list,int num)
{
	if (list.head->next == nullptr)
	{
		list.head->next = new Node(num);
	}
	else
	{
		Node* cur = list.head->next;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node(num);
	}
}
void func()
{
	List list;
	init(list);
	push(list, 1);
	push(list, 2);
	push(list, 3);
	push(list, 4);
	Node* cur = list.head->next;
	while (cur != nullptr)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
}
void push2(Node* node,int num)
{
	if (node->next = nullptr)
	{
		node->next = new Node(num);
	}
	else
	{
		Node* cur = node;
		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node(num);
	}
	Node* cur = node->next;
	while (cur != nullptr)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
}
void func2()
{
	Node* node = new Node(0);
	push2(node, 1);
	push2(node, 2);
	push2(node, 5);
	push2(node, 4);
}
int main()
{
	//func();
	func2();
	return 0;
}