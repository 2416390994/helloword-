//#include<iostream>
//using namespace std;
////bool Circle()
////{
////
////}
////void test1()
////{
////
////
////}
////int main()
////{
////	
////	return 0;
////}
///*
//使用两个全局成员变量i,sum,一个每次自增，一个累加，让在构造函数内部完成自增与累加的过程，
//这样没调用一次构造函数实现一次自增与累加，当调用n次构造函数，就完成这个功能。需要注意的是，
//直接用数组创建n个对象时不行的，因为数组下标必须是常量不能是变量，解决办法是用new动态创建n个对象，
//即调用n次构造函数。
//*/
//class Func
//{
//public:
//	Func()
//	{
//		sum += i;
//		i++;
//	}
//	int getsum()
//	{
//		return sum;
//	}
//
//	static int sum;
//	static int i;
//};
//int Func::sum = 0;
//int Func::i = 1;
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		Func * p;
//		p = new  Func[n];
//		int ret = p->getsum();
//		return ret;
//	}
//};
//int main()
//{
//	//int n = 0;
//	//cin >> n;
//	//Func * p = new Func[n];  //这里使用new来创建n个对象，是因为数组不能使用变量来作为参数。
//	//	cout << p->getsum() << endl;
//	Solution * p = new Solution;
//	int ret = p->Sum_Solution(10);
//	cout << ret << endl;
//	Func::sum = 0;
//	return 0;
//}
#include<iostream>
using namespace std;
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//	}
//};
//class Solution {
//public:
//	ListNode* Circle(ListNode* pHead)    //判断是否带环，带环的话返回两个指针相遇的点
//	{
//		if (pHead == nullptr&&pHead->next == nullptr)
//			return nullptr;
//		ListNode* fast = pHead;
//		ListNode* slow = pHead;
//		while (fast&&fast->next)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//			if (fast == slow)
//				return slow;
//		}
//		return nullptr;
//	}
//	ListNode* EntryNodeOfLoop(ListNode* pHead)
//	{
//		ListNode* pMeet = Circle(pHead);
//		if (!pMeet)
//			return nullptr;
//		ListNode* Lee = pHead;
//		while (pMeet != Lee)
//		{
//			pMeet = pMeet->next;
//			Lee = Lee->next;
//		}
//		return Lee;
//	}
//};
#include<string>
#include<stack>
class Solution {
public:
	string ReverseSentence(string str) {
		stack<string> p;
		int point1 = 0;
		int point2;
		while (str.find(' ', point1) != -1)
		{
			point2 = str.find(' ', point1);
			p.push(str.substr(point1, point2 - point1));
			point1 = point2 + 1;
		}
		p.push(str.substr(point1));
		str.clear();
		while (p.size() > 1)
		{
			str += p.top();
			str += ' ';
			p.pop();
		}
		str += p.top();
		return str;
	}
};
int main()
{
	Solution p;
	string s = "I am a student.";
	s = p.ReverseSentence(s);
	cout << s << endl;
	return 0;
}