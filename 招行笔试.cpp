//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//void func()
//{
//
//	int count;
//	string s1;
//	while (cin >> count)
//	{
//		vector<string> vec;
//		for (int i = 0; i < count; ++i)
//		{
//			cin >> s1;
//			int L = 0;
//			int R = s1.size() - 1;
//			int flag = 0;
//			while (L < R)
//			{
//				if ((s1[L] == '1' && s1[R] == '1') || (s1[L] == '2' && s1[R] == '5') || (s1[L] == '3' && s1[R] == '8') || (s1[L] == '4' && s1[R] == '7') || (s1[L] == '6' && s1[R] == '9'))
//				{
//					L++;
//					R--;
//				}
//				else if ((s1[R] == '1' && s1[L] == '1') || (s1[R] == '2' && s1[L] == '5') || (s1[R] == '3' && s1[L] == '8') || (s1[R] == '4' && s1[L] == '7') || (s1[R] == '6' && s1[L] == '9'))
//				{
//					L++;
//					R--;
//				}
//				else
//				{
//					flag = 1;
//					vec.push_back("NO");
//					break;
//				}
//			}
//			if (flag == 0)
//				vec.push_back("YES");
//		}
//		for (auto e : vec)
//			cout << e << endl;
//	}
//}
//
//
//int main()
//{
//	func();
//	return 0;
//}



#include<iostream>
#include<string>
#include<vector>
using namespace std;
void func()
{

	int count;
	string s1;
	while (cin >> count)
	{
		vector<string> vec;
		for (int i = 0; i < count; ++i)
		{
			cin >> s1;
			int L = 0;
			int R = s1.size() - 1;
			int flag = 0;
			while (L < R)
			{
				if ((s1[L] == '1' && s1[R] == '1') || (s1[L] == '2' && s1[R] == '5') || (s1[L] == '3' && s1[R] == '8') || (s1[L] == '4' && s1[R] == '7') || (s1[L] == '6' && s1[R] == '9'))
				{
					L++;
					R--;
				}
				else if ((s1[R] == '1' && s1[L] == '1') || (s1[R] == '2' && s1[L] == '5') || (s1[R] == '3' && s1[L] == '8') || (s1[R] == '4' && s1[L] == '7') || (s1[R] == '6' && s1[L] == '9'))
				{
					L++;
					R--;
				}
				else
				{
					flag = 1;
					cout << "NO" << endl;
					break;
				}
			}
			if (flag == 0)
				cout << "YES" << endl;
		}
	}
}


int main()
{
	func();
	return 0;
}