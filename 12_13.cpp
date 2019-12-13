#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class TreeNode   //����Ƕ������Ľ��
{
public:
	TreeNode* left;
	TreeNode* right;
	char c;
	TreeNode(char x)
		:c(x)
		, left(nullptr)
		, right(nullptr)
	{}
};

string PrintMinNumber(vector<int> numbers)
{
	vector<string> vec;
	int size = numbers.size();
	for (int i = 0; i < size; ++i)
	{
		vec.push_back(to_string(numbers[i]));
	}
	string max = vec[0];
	for (int i = 0; i < size; ++i)
	{
		if (vec[i].size() > max.size())
			max = vec[i];
	}
	int size_t = max.size();
	for (int j = 0; j < size_t; ++j)
	{
		int count = 9;
		int flag = 0;
		for (int i = 0; i < size; ++i)
		{
			if (vec[i].size() > j && vec[i] != "0")
			{

				if (vec[i][j] - '0' < count)
				{
					count = vec[i][j] - '0';
					flag = i;
				}
			}
		}
		cout << vec[flag];
		vec[flag] = "0";
	}
	return 0;
}
class Solution {
public:
	static bool cmp(int a, int b){
		string A = "";
		string B = "";
		A += to_string(a);
		A += to_string(b);
		B += to_string(b);
		B += to_string(a);
		return A<B;
	}
	string PrintMinNumber(vector<int> numbers) {
		string  answer = "";
		sort(numbers.begin(), numbers.end(), cmp);
		for (int i = 0; i<numbers.size(); i++){
			answer += to_string(numbers[i]);
		}
		cout << answer << endl;
		return answer;
	}
};
/*
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		//��Ҫ˼·���趨�����㣨��1��10��100�ȵȣ���Ϊλ�õ�i����Ӧn�ĸ�λ��ʮλ����λ�ȵȣ����ֱ��ÿ����λ���ж��ٰ���1�ĵ���з���
		//�����趨������λ�ã���n���зָ��Ϊ�����֣���λn/i����λn%i
		//��i��ʾ��λ���Ұ�λ��Ӧ����>=2,��n=31456,i=100����a=314,b=56����ʱ��λΪ1�Ĵ�����a/10+1=32�������λ0~31����ÿһ�ζ�����100�������ĵ㣬������(a%10+1)*100����İ�λΪ1
		//��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ1����n=31156,i=100����a=311,b=56����ʱ��λ��Ӧ�ľ���1������a%10(�����λ0-30)���ǰ���100�������㣬�������λΪ31����a=311��������ֻ��Ӧ�ֲ���00~56����b+1�Σ����е���������У�a%10*100��+(b+1)����Щ���λ��ӦΪ1
		//��i��ʾ��λ���Ұ�λ��Ӧ����Ϊ0,��n=31056,i=100����a=310,b=56����ʱ��λΪ1�Ĵ�����a/10=31�������λ0~30��
		//�ۺ������������������λ��Ӧ0��>=2ʱ����(a+8)/10�ΰ�������100���㣬���е���λΪ1(a%10==1)����Ҫ���Ӿֲ���b+1
		//֮���Բ�8������Ϊ����λΪ0����a/10==(a+8)/10������λ>=2����8�������λλ��Ч����ͬ��(a/10+1)
		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			//i��ʾ��ǰ����������һ����λ
			int a = n / i, b = n%i;
			count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
		}
		return count;
	}
};
*/
struct ret  //�Լ�����ֵ�ķ�װ������Ҫ�õ���������ֵ�ͷ�װ��һ������
{
	TreeNode* root; //��ǰ�����Ľڵ�
	int used;  //�����������õ���val����
};
ret CreateTree(char * s, int size)   //���ɺ���
{
	if (size == 0)   //�����������size��Ϊ0��ʱ��
	{
		ret result;
		result.root = nullptr;
		result.used = 0;
		return result;
	}
	char rootVal = s[0];
	if (rootVal == '#')  //����������Ա�־λ�����ж�
	{
		ret result;
		result.root = nullptr;
		result.used = 1;
		return result;
	}
	//��
	TreeNode* tree = new TreeNode(s[0]); //�½���㲢���й���
	ret left_result = CreateTree(s + 1, size - 1);  //Ȼ������������Ĺ��죬���Ĳ���-1����Ϊ���ڵ��Ѿ��õ���һ��
	ret right_result = CreateTree(s + 1 + left_result.used, size - 1 - left_result.used); //�������Ĺ���Ҫ ��ȥ���ڵ�ĳ��ȣ��Լ��������ĳ���
	tree->left = left_result.root;   //Ȼ���ø��ڵ����
	tree->right = right_result.root;  //���ڵ����
	ret p;     
	p.root = tree;    //���������������ĸ�Ȼ�󷵻�����һ�����ָ��������
	p.used = 1 + left_result.used + right_result.used;
	return p;
}
void InorderTraversal(TreeNode* p)   //�����������ӡ����
{
	if (p == nullptr)
		return;
	InorderTraversal(p->left);
	cout << p->c << " ";
	InorderTraversal(p->right);
}
void Test()
{
	char s[200];
	cin >> s;
	int size = strlen(s);
	ret result = CreateTree(s, size);
	InorderTraversal(result.root);
}
int main()
{
	//Test();
	Solution s;
	
	vector<int> vec{ 3, 23, 321 };
	s.PrintMinNumber(vec);
	return 0;
}
/*

class Solution {
public:
bool func(TreeNode *pRoot1,TreeNode *pRoot2)
{
if(pRoot1 == nullptr && pRoot2 == nullptr)
return true;
if(pRoot1 == nullptr || pRoot2 == nullptr)
return false;
return pRoot1->val == pRoot2->val && func(pRoot1->left,pRoot2->right) && func(pRoot1->right,pRoot2->left);
}
bool isSymmetrical(TreeNode *pRoot) {
if(pRoot == nullptr)
return false;
return func(pRoot->left,pRoot->right);
}
};

*/