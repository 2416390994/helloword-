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
//ʹ������ȫ�ֳ�Ա����i,sum,һ��ÿ��������һ���ۼӣ����ڹ��캯���ڲ�����������ۼӵĹ��̣�
//����û����һ�ι��캯��ʵ��һ���������ۼӣ�������n�ι��캯���������������ܡ���Ҫע����ǣ�
//ֱ�������鴴��n������ʱ���еģ���Ϊ�����±�����ǳ��������Ǳ���������취����new��̬����n������
//������n�ι��캯����
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
//	//Func * p = new Func[n];  //����ʹ��new������n����������Ϊ���鲻��ʹ�ñ�������Ϊ������
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
//	ListNode* Circle(ListNode* pHead)    //�ж��Ƿ�����������Ļ���������ָ�������ĵ�
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