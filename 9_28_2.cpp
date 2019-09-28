//#include<iostream>
//using namespace std;
////class Solution
////{
////public:
////	void push(int node) {
////		if (stack2.empty())
////		{
////			stack1.push(node);
////		}
////		else
////		{
////			while (!stack2.empty())
////			{
////				stack1.push(stack2.top());
////				stack2.pop();
////			}
////			stack1.push(node);
////		}
////	}
////
////	int pop() {
////		if (stack1.empty())
////		{
////			stack2.pop();
////		}
////		else
////		{
////			while (!stack1.empty())
////			{
////				stack2.push(stack1.top());
////				stack1.pop();
////			}
////			stack2.pop();
////		}
////	}
////
////private:
////	stack<int> stack1;
////	stack<int> stack2;
////};
////int main()
////{
////	Solution s;
////	s.pop();
////	return 0;
////}
//class Solution {
//public:
//	int  NumberOf1(int n) {
//		if (n > 0)
//		{
//			int count = 0;
//			while (n > 0)
//			{
//				if ((n & 1) == 1)
//					++count;
//				n >>= 1;
//			}
//			return count;
//		}
//		else
//		{
//			int count = 0;
//			for (int i = 1; i <= 32; ++i)
//			{
//				if ((n & 1) == 1)
//					++count;
//				n >>= 1;
//
//			}
//			return count;
//		}
//
//	}
//};
//int main()
//{
//	Solution s;
//	int c = s.NumberOf1(-10);
//	cout << c << endl;
//	return 0;
//}