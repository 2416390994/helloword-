#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int num)
		:left(nullptr)
		, right(nullptr)
		, val(num)
	{}
};

bool func1(TreeNode* head1,TreeNode* head2)
{
	if (head1 == nullptr && head2 == nullptr)
		return true;
	if (head1 == nullptr || head2 == nullptr)
		return false;
	return head1->val == head2->val && func1(head1->left, head2->left) && func1(head1->right, head2->right);
}
bool func2(TreeNode* head1,TreeNode* head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return false;
	if (head1->val == head2->val && func1(head1, head2))
	{
		return false;
	}
	bool left = func2(head1->left, head2);
	if (left == true)
		return left;
	bool right = func2(head1->right, head2);
	    return right;
}
struct ret
{
	int used;
	TreeNode* s;
};
ret func3(char* s,int size)
{
	if (size == 0)
	{
		ret r;
		r.s = nullptr;
		r.used = 0;
		return r;
	}
	char s1 = s[0];
	if (s1 == '#')
	{
		ret r;
		r.s = nullptr;
		r.used = 1;
		return r;
	}
	TreeNode* tree = new TreeNode(s[0]);
	ret left = func3(s + 1, size - 1);
	ret right = func3(s + 1 + left.used, size - 1 - left.used);
	tree->left = left.s;
	tree->right = right.s;
	ret p;
	p.s = tree;
	p.used = 1 + left.used + right.used;
	return p;
}

int func4(TreeNode* head)
{
	if (head == nullptr)
		return 0;
	if (head->left == nullptr && head->right == nullptr)
		return 1;
	return func4(head->left) + func4(head->right);
}

class MIN_stack
{
public:
	void push(int num)
	{
		if (stack1.empty() && num < stack2.top())
		{
			stack1.push(num);
			stack2.push(num);
		}
		else
		{
			stack1.push(num);
			stack2.push(stack2.top());
		}
	}
	void pop()
	{
		stack1.pop();
		stack2.pop();
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};
void func6(TreeNode* head)
{
	queue<TreeNode*> que;
	if (head == nullptr)
		return;
	que.push(head);
	while (!que.empty())
	{
		cout << que.front()->val;
		if (que.front()->left)
			que.push(que.front()->left);
		if (que.front()->right)
			que.push(que.front()->right);
		que.pop();
	}
}

void func5(TreeNode* head)
{
	queue<TreeNode*> que;
	vector<vector<int>> vec1;
	if (head == nullptr)
		return;
	que.push(head);
	int sl = 1;
	int s2 = 0;
	while (!que.empty())
	{
		vector<int> vec2;
		while (sl--)
		{
			cout << que.front()->val;
			if (que.front()->left)
			{
				que.push(que.front()->left);
				sl++;
			}
			if (que.front()->right)
			{
				que.push(que.front()->right);
				sl++;
			}
			vec2.push_back(que.front()->val);
			que.pop();
		}
		vec1.push_back(vec2);
	}
}

bool func7(TreeNode* head)
{
	queue<TreeNode*> que;
	if (head == nullptr)
		return;
	que.push(head);
	while (que.front() != nullptr)
	{
		TreeNode* p = que.front();
		que.push(p->left);
		que.push(p->right);
		que.pop();
	}
	while (!que.empty())
	{
		if (que.front() != nullptr)
			return false;
		que.pop();
	}
	return true;
}
void func8(TreeNode* head)
{
	if (head == nullptr)
		return;
	stack<TreeNode*> sta;
	TreeNode* cur = head;
	while(head || !sta.empty())
	{
		while (cur)
		{
			cout << cur->val << endl;
			sta.push(cur);
			cur = cur->left;
		}
		if (!sta.empty())
		{
			cur = sta.top();
			sta.pop();
			cur = cur->right;
		}
	}
}
void func9(TreeNode* head)
{
	if (head == nullptr)
		return;
	stack<TreeNode*> sta;
	TreeNode* cur = head;
	while (head || !sta.empty())
	{
		while (cur)
		{
			sta.push(cur);
			cur = cur->left;
		}
		if (!sta.empty())
		{
			cur = sta.top();
			cout << cur->val << endl;
			sta.pop();
			cur = cur->right;
		}
	}
}

int func10(TreeNode* head)
{
	if (head == nullptr)
		return;
	int left = func10(head->left);
	int right = func10(head->right);
	return left > right ? left : right + 1;
}

bool func11(TreeNode* head)
{
	if (head == nullptr)
		return false;
	int left = func10(head->left);
	int right = func10(head->right);
	int def = left - right;
	if (def > 1 || def < -1)
		return false;
	else
		return true;
}
void func12(TreeNode* head)
{
	if (head == nullptr)
		return;
	TreeNode* p = nullptr;
	TreeNode* cur = head;
	stack<TreeNode*> sta;
	while (cur || !sta.empty())
	{
		if (cur)
		{
			sta.push(cur);
			cur = cur->left;
		}
		else
		{
			cur = sta.top();
			if(cur->right && cur->right != p)
				cur = cur->right;
			else
			{
				cur = sta.top();
				cout << cur->val;
				sta.pop();
				p = cur;
				cur = nullptr;
			}
		}
	}
}
TreeNode* func13(TreeNode* head,TreeNode* p1,TreeNode* p2)
{
	if (p1 == head || p2 == head || head == nullptr)
		return head;
	TreeNode* left = func13(head->left, p1, p2);
	TreeNode* right = func13(head->right, p1, p2);
	if (left == nullptr && right != nullptr)
		return right;
	else if (left != nullptr && right == nullptr)
		return left;
	else if (left != nullptr && right != nullptr)
		return nullptr;
	else
		return head;
}

int main()
{


	return 0;
}