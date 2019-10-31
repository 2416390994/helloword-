#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//
//	int i = 0;
//	int j = 0;
//	stack<int> sta;
//	while (i < (int)pushV.size()||j < popV.size())
//	{
//		if (sta.empty())
//			sta.push(pushV[i++]);
//		if (sta.top() != popV[j])
//			sta.push(pushV[i++]);
//		else
//		{
//			j++;
//			sta.pop();
//		}
//	}
//	if (i == pushV.size()&&j == popV.size())
//		return true;
//	return false;
//}
//bool IsPopOrder(vector<int> pushV, vector<int> popV)
//{
//	stack<int> sta;
//	int index = 0;
//	int outdex = 0;
//	while (outdex < popV.size())
//	{
//		while (sta.empty()|| sta.top() != popV[outdex])
//			if (index < pushV.size())
//				sta.push(pushV[index++]);
//			else
//				return false;
//			sta.pop();
//			outdex++;
//	}
//	return true;
//}
//#include <sstream>
//string num2str(const int num){
//	stringstream ss;
//	ss << num;
//	return ss.str();
//}
//int evalRPN(vector<string>& tokens) {
//	stack<string> sta;
//	int i = 0;
//	while (i < tokens.size())
//	{
//		if (tokens[i] == "+")
//		{
//			int left = atoi(sta.top().c_str());
//			cout << left << endl;
//			sta.pop();
//			int right = atoi(sta.top().c_str());
//			cout << right << endl;
//			sta.pop();
//			int res = right + left;
//			string s = num2str(res);
//			sta.push(s);
//			i++;
//		}
//		else if (tokens[i] == "-")
//		{
//			int left = atoi(sta.top().c_str());
//			sta.pop();
//			int right = atoi(sta.top().c_str());
//			sta.pop();
//			int res = right - left;
//			string s = num2str(res);
//			sta.push(s);
//			i++;
//		}
//		else if (tokens[i] == "*")
//		{
//			int left = atoi(sta.top().c_str());
//			sta.pop();
//			int right = atoi(sta.top().c_str());
//			sta.pop();
//			int res = right * left;
//			string s = num2str(res);
//			sta.push(s);
//			i++;
//		}
//		else if (tokens[i] == "/")
//		{
//			int left = atoi(sta.top().c_str());
//			sta.pop();
//			int right = atoi(sta.top().c_str());
//			sta.pop();
//			int res = right / left;
//			cout << res << endl;
//			string s = num2str(res);
//			sta.push(s);
//			i++;
//		}
//		sta.push(tokens[i++]);
//	}
//	return atoi(sta.top().c_str());
//}
/*
vector<vector<int>> levelOrder(TreeNode* root) {
	queue<int> que;
	int i = 0;
	vector<vector<int>> vv;
	queue.push(root);
	i++;
	while(!queue.empty())
	{
		for(int size = 0;size < i; ++size)
		{
			vector<int> v;
			if(queue.top()->left!=nullptr)
			{
				queue.push(queue.top()->left);
				i++;
			}
			if(queue.top()->right!=nullptr)
			{
				queue.push(queue.top()->right);
				i++;
			}
			v.push_back(queue.top());
			queue.pop(queue.top());
		}
		vv.push_back(v);
	}
	return vv;
}
*/
#include<functional>
int main()
{
	priority_queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	vector<int> v1{ 1, 2, 3, 4, 5 };
	priority_queue<int> q2(v1.begin(), v1.end());
	priority_queue<int, vector<int>, greater<int>> q3(v1.begin(),v1.end());
	cout << q1.top() << endl << q2.top() << endl << q3.top() << endl;  //按照小堆的方式打印
	//vector<int> l{ 1, 2, 3, 4, 5 };
	//vector<int> l1{ 4, 5, 3, 2, 1 };
	//cout<<IsPopOrder(l, l1);
	/*vector<string> v{ "4", "13", "5", "/", "+"};
	int c = 10;
	string s = to_string(c);
	cout << s << endl;*/

	return 0;
}