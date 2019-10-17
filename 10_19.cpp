#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> v;
	v.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		v[i].resize(10);
	}
	v[0][0] = 10;
	cout << v[0][0];

}
//struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

//class Solution {
//public:
//	string tree2str(TreeNode* t) {
//		if (t == nullptr)
//			return nullptr;
//		char c = t->val + '0';
//		s += c;
//		if (t->left == nullptr)
//			s += "()";
//		else
//		{
//			_1(t->left);
//		}
//		_1(t->right);
//		return s;
//	}
//	void _1(TreeNode* tree)
//	{
//		s += '(';
//		char c = (char)tree->val + '0';
//		s += c;
//		if (tree->left == nullptr)
//			s += "()";
//		else
//		{
//			_1(tree->left);
//		}
//		_1(tree->right);
//		s += ')';
//	}
//	string s;
//};
//void _1(int *a,int length)
//{
//	if (length == 0 || length == 1)
//		return;
//	int size = length;
//	for (int i = 0; i < size; ++i)
//	{
//		while (a[i] > a[(i - 1)/2])
//		{
//			swap(a[i], a[(i - 1)/2]);
//			i = (i - 1) / 2;
//		}
//	}
//	
//	while (size > 0)
//	{
//		swap(a[0], a[--size]);
//		int index = 0;
//		int left = index * 2 + 1;
//		while (left < size)
//		{
//			int larget = (left + 1) < size && a[left + 1]>a[left] ? left + 1 : left;
//			larget = a[larget] > a[index] ? larget : index;
//			if (larget == index)
//			{
//				break;
//			}
//			swap(a[index], a[larget]);
//			index = larget;
//			left = index * 2 + 1;
//		}
//	}
//}
//#include<time.h>
//struct A_B
//{
//	int a; 
//	int b;
//};
//A_B _2(int *a,int L,int R)
//{
//	int less = L - 1;
//	int more = R;
//	while (L < more)
//	{
//		if (a[L] < a[R])
//		{
//			swap(a[L++], a[++less]);
//		}
//		else if (a[L]>a[R])
//		{
//			swap(a[--more], a[L]);
//		}
//		else
//			L++;
//	}
//	swap(a[R], a[more]);
//	A_B c;
//	c.a = less;
//	c.b = more + 1;
//	return c;
//}
//void _1(int* a,int L,int R)
//{
//	srand((unsigned int)time(NULL));
//	if (L < R)
//	{
//		swap(a[R], a[L + rand() % (R-L)]);
//		A_B c = _2(a, L, R); 
//		_1(a, L, c.a);
//		_1(a, c.b, R);
//	}
//}
//void _sort(int *a, int L, int M, int R)
//{
//	int c = R - L + 1;
//	int *p = new int[c];
//	int p1 = L;
//	int p2 = M + 1;
//	int i = 0;
//	while (p1 <= M && p2 <= R)
//	{
//		p[i++] = a[p1] > a[p2] ? a[p1++] : a[p2++];
//	}
//	while (p1 <= M)
//	{
//		p[i++] = a[p1++];
//	}
//	while (p2 <= R)
//	{
//		p[i++] = a[p2++];
//	}
//	for (int j = 0; j < c; ++j)
//	{
//		a[L++] = p[j]; 
//	}
//	//delete[] p;
//	//p = nullptr;
//}
//void _5(int *a,int length,int root)
//{
//	while (1)
//	{
//		int left = root * 2 + 1;
//		if (left >= length)
//			return;
//		int right = root * 2 + 1;
//		int min = left;
//		if (right < length&&a[right] < a[left])
//			min = right;
//		if (a[root] <= a[min])
//			return;
//		swap(a[root], a[min]);
//		root = min;
//	}
//}
//TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p ,TreeNode* q)
//{
//	if (root == p || root == q || !root)return root;
//	struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
//	struct TreeNode* right = lowestCommonAncestor(root->right, p, q);
//	if (!left&&!right)return nullptr;
//	else if (left&&!right)return left;
//	else if (right&&!left)return right;
//	return root;
//}
////void _4(int *a, int L, int R)
////{
////	if (L == R)
////		return;
////	int M = L + ((R-L) >> 1);
////	
////	_4(a, L, M);
////	_4(a, M+1, R);
////	_sort(a, L, M, R);
////}
//int main()
//{
//
//	int a[] = { 5, 9, 1, 6, 4, 8, 7, 3, 2, 0 };
//	int length = sizeof(a) / sizeof(a[0]);
//	_5(a, length, 0);
//	for (auto e : a)
//		cout << e << endl;
//	return 0;
//}
//#include<stdio.h>
//void sort(int *a, int L, int M, int R)
//{
//	int *p = new int[R - L + 1];
//	int p1 = L;
//	int p2 = M + 1;
//	int i = 0;
//	while (p1 <= M && p2 <= R)
//	{
//		p[i++] = a[p1] > a[p2] ? a[p1++] : a[p2++];
//	}
//	while (p1 <= M)
//	{
//		p[i++] = a[p1++];
//	}
//	while (p2 <= R)
//	{
//		p[i++] = a[p2++];
//	}
//	for (i = 0; i < R - L + 1; ++i)
//	{
//		a[L + i] = p[i];
//	}
//}
//void func(int *a, int L, int R)
//{
//	if (L == R)
//		return;
//	int M = L + ((R - L) >> 1);
//	func(a, L, M);
//	func(a, M + 1, R);
//	sort(a, L, M, R);
//}
//int main()
//{
//	int a[] = { 5, 8, 9, 6, 3, 4, 7, 2, 1, 0 };
//	func(a, 0, 9);
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d\n", a[i]);
//	}
//	return 0;
//}
