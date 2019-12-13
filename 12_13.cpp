#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class TreeNode   //这个是二叉树的结点
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
		//主要思路：设定整数点（如1、10、100等等）作为位置点i（对应n的各位、十位、百位等等），分别对每个数位上有多少包含1的点进行分析
		//根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i
		//当i表示百位，且百位对应的数>=2,如n=31456,i=100，则a=314,b=56，此时百位为1的次数有a/10+1=32（最高两位0~31），每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1
		//当i表示百位，且百位对应的数为1，如n=31156,i=100，则a=311,b=56，此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311），本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1
		//当i表示百位，且百位对应的数为0,如n=31056,i=100，则a=310,b=56，此时百位为1的次数有a/10=31（最高两位0~30）
		//综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10==1)，需要增加局部点b+1
		//之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			//i表示当前分析的是哪一个数位
			int a = n / i, b = n%i;
			count = count + (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
		}
		return count;
	}
};
*/
struct ret  //以及返回值的封装，我们要拿到两个返回值就封装了一种类型
{
	TreeNode* root; //当前构建的节点
	int used;  //构建过程中用掉的val个数
};
ret CreateTree(char * s, int size)   //主干函数
{
	if (size == 0)   //特殊情况，当size减为0的时候
	{
		ret result;
		result.root = nullptr;
		result.used = 0;
		return result;
	}
	char rootVal = s[0];
	if (rootVal == '#')  //特殊情况，对标志位进行判断
	{
		ret result;
		result.root = nullptr;
		result.used = 1;
		return result;
	}
	//根
	TreeNode* tree = new TreeNode(s[0]); //新建结点并进行构造
	ret left_result = CreateTree(s + 1, size - 1);  //然后进行左子树的构造，传的参数-1是因为根节点已经用掉了一个
	ret right_result = CreateTree(s + 1 + left_result.used, size - 1 - left_result.used); //右子树的构建要 减去根节点的长度，以及左子树的长度
	tree->left = left_result.root;   //然后让根节点的左
	tree->right = right_result.root;  //根节点的右
	ret p;     
	p.root = tree;    //包含本层所建立的根然后返回让上一级结点指向这个结点
	p.used = 1 + left_result.used + right_result.used;
	return p;
}
void InorderTraversal(TreeNode* p)   //中序遍历最后打印出树
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