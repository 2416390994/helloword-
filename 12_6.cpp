#include<iostream>  
#include<algorithm>  
#include<string.h>  
using namespace std;
//int mark[5005], fa[5005];
//int get(int x)
//{
//	if (fa[x] == x)
//		return x;
//	return fa[x] = get(fa[x]);
//}
//int main()
//{
//	int n, m, p;
//	cin >> n >> m >> p;
//	int a, b;
//	memset(mark, 0, sizeof(mark));
//	for (int i = 1; i <= n; i++)
//		fa[i] = i;
//	while (m--)
//	{
//		cin >> a >> b;
//		a = get(a);
//		b = get(b);
//		if (a != b)
//		{
//			fa[a] = b;
//		}
//	}
//	for (int i = 1; i <= p; i++)
//	{
//		cin >> a >> b;
//		a = get(a);
//		b = get(b);
//		if (a == b)
//			mark[i] = 1;
//	}
//	for (int i = 1; i <= p; i++)
//	{
//		if (mark[i])
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}
//前缀树节点的构建
class TrieNode
{
public:
	TrieNode()
		:pass(0)
		, end(0)
	{
		*next = new TrieNode[26];
	}
	int pass;
	int end;
	TrieNode** next = nullptr;   //这里真的是太恶心了，找了半天的错误
};
TrieNode* p = nullptr;
class Trie
{
public:
	Trie()
		:root(new TrieNode())  //先构造一个前缀树的根节点
	{}
	void Insert(string str)  //准备将字符串str插入前缀树
	{
		if (str.empty())
			return;
		TrieNode* Node = root;  //一个指针指向头结点，开始根据字符串往下遍历
		int index = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			index = str[i] - 'a';  
			//拿到索引值，加入第一个字符是'b',减'a'之后就等于1，
			//那么就说明要找root节点中的那个26个指针的数组中的1号索引是否被创建，
			//创建了的话就直接沿着创建好的节点走，没有的话就创建
			if (Node->next[index] == nullptr)  //就代表此时还没有这个结点
			{
				Node->next[index] = new TrieNode;
			}
			Node = Node->next[index];//跑到这个结点继续往下找看存不存在接下来元素的节点
			Node->pass++;
		}
		Node->end++;
	}
	int Search(string str)  //查找
	{
		if (str.empty())
			return 0;
		TrieNode* Node = root;
		int index = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			index = str[i] - 'a';
			if (Node->next[index] == nullptr)
				return 0;
			Node = Node->next[index];
		}
		return Node->end;
	}
	void Delete(string str)  //删除一个str，假如存在多个str的话，这个函数的功能就是删除一个str
	{
		if (Search(str) == 0)  //如果根本就不存在这个字符串那么久不用删除了
			return;
		TrieNode* Node = root;
		//Node->pass--;
		int index = 0;
		int i;
		for (i = 0; i < str.size(); ++i)  //下面这一大坨自己写的，我感觉主要就是因为C++的new出来的内存需要手动释放引起的
		{
			index = str[i] - 'a';
			if (--Node->next[index]->pass == 0)
			{
				TrieNode* cur = Node->next[index];
				Node->next[index] = nullptr;
				Node = cur;
				i++;
				break;
			}
		}
		while (i < str.size())
		{
			TrieNode* cur = Node->next[index];
			delete Node;
			Node = cur;
			++i;
		}
		Node->end--;
	}
private:
	TrieNode* root;
};
int main()
{

	return 0;
}
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int size;
//	while (cin >> size)
//	{
//		vector<int> vec;
//		int c;
//		for (int i = 0; i < size; ++i)
//		{
//			cin >> c;
//			vec.push_back(c);
//		}
//		int count = vec[0];
//		int maxsize = count;
//		int s = 0;
//		for (int i = 1; i < size; ++i)
//		{
//			s = vec[i];
//			count += vec[i];
//			if (count < 0)
//				count = s;
//			if (maxsize < count)
//				maxsize = count;
//		}
//		cout << maxsize << endl;
//	}
//	return 0;
//}
