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
//ǰ׺���ڵ�Ĺ���
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
	TrieNode** next = nullptr;   //���������̫�����ˣ����˰���Ĵ���
};
TrieNode* p = nullptr;
class Trie
{
public:
	Trie()
		:root(new TrieNode())  //�ȹ���һ��ǰ׺���ĸ��ڵ�
	{}
	void Insert(string str)  //׼�����ַ���str����ǰ׺��
	{
		if (str.empty())
			return;
		TrieNode* Node = root;  //һ��ָ��ָ��ͷ��㣬��ʼ�����ַ������±���
		int index = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			index = str[i] - 'a';  
			//�õ�����ֵ�������һ���ַ���'b',��'a'֮��͵���1��
			//��ô��˵��Ҫ��root�ڵ��е��Ǹ�26��ָ��������е�1�������Ƿ񱻴�����
			//�����˵Ļ���ֱ�����Ŵ����õĽڵ��ߣ�û�еĻ��ʹ���
			if (Node->next[index] == nullptr)  //�ʹ����ʱ��û��������
			{
				Node->next[index] = new TrieNode;
			}
			Node = Node->next[index];//�ܵ���������������ҿ��治���ڽ�����Ԫ�صĽڵ�
			Node->pass++;
		}
		Node->end++;
	}
	int Search(string str)  //����
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
	void Delete(string str)  //ɾ��һ��str��������ڶ��str�Ļ�����������Ĺ��ܾ���ɾ��һ��str
	{
		if (Search(str) == 0)  //��������Ͳ���������ַ�����ô�ò���ɾ����
			return;
		TrieNode* Node = root;
		//Node->pass--;
		int index = 0;
		int i;
		for (i = 0; i < str.size(); ++i)  //������һ�����Լ�д�ģ��Ҹо���Ҫ������ΪC++��new�������ڴ���Ҫ�ֶ��ͷ������
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
