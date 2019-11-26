#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//	{
//		int flag = 0;
//		int i = 0;
//		int j = 0;
//		int str1_size = str1.size();
//		int str2_size = str2.size();
//		while (i < str1_size && j < str2_size)
//		{
//			if (str1[i] == str2[i])
//			{
//				++i;
//				++j;
//			}
//			else if (str1[i] == '?')
//			{
//				++i;
//				++j;
//			}
//			else if (str1[i] == '*')
//			{
//				++i;
//				while (str1[i] != str2[j] && j < str2_size)
//				{
//					++j;
//				}
//			}
//			else
//				flag = 1;
//		}
//		if (flag == 1)
//			cout << "false" << endl;
//		else
//			cout << "true" << endl;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int c;
//	while (cin >> c)
//	{
//		int a1 = c;
//		int a2 = 0;
//		int a3 = a1;
//		int a4 = 0;
//		if (c == 0)
//		{
//			break;
//		}
//		while (a3 > 2)
//		{
//
//			a3 = a1 % 3;   //剩余的空瓶数
//			a2 += a1 / 3;  //兑换的饮料数
//			a3 = a3 + (a1 / 3);
//			a1 = a3;
//		}
//		if (a3 == 2)
//			a2 += 1;
//		cout << a2 << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		if (str1.size() < str2.size())
			swap(str1, str2);
		string str3;
		string str4;
		for (int i = 0; i < str1.size(); ++i)
		{
			for (int j = 0; j < str2.size(); ++j)
			{
				int k = i;
				while (str1[k] == str2[j] && j < str2.size() && k < str1.size())
				{
					str3 += str2[j];
					j++;
					k++;
				}
				if (str3.size() > str4.size())
				{
					str4 = str3;
				}
				str3.clear();
			}
			
		}
		cout << str4 << endl;

	}
	return 0;
}