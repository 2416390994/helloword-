#include<iostream>
using namespace std;
//int main()
//{
//	int c;
//	while (cin >> c)
//	{
//		if (c == 1 || c == 2)
//		{
//			cout << -1 << endl;
//			continue;
//		}
//		if (c % 4 == 0)
//			cout << 3 << endl;
//		else if (c % 4 == 1)
//			cout << 2 << endl;
//		else if (c % 4 == 2)
//			cout << 4 << endl;
//		else if (c % 4 == 3)
//			cout << 3 << endl;
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
	string str3;
	while (cin >> str1 >> str2)
	{


		if (str1.size() < str2.size())
			swap(str1, str2);
		str3.resize(str1.size() + 1);
		int flag = 0;
		int a1 = str1.size() - 1;
		int a2 = str2.size() - 1;
		int a3 = str3.size() - 1;
		while (a1 >= 0)
		{
			int a, b;
			if (a2 >= 0)
				b = str2[a2] - '0';
			else
				b = 0;
			a = str1[a1] - '0';
			str3[a3] = ((a + b + flag) % 10) + '0';
			if (a + b + flag >= 10)
				flag = 1;
			else
				flag = 0;
			--a1;
			--a2;
			--a3;
		}
		if (flag == 1)
			str3[0] = '1';
		else
			str3.erase(str3.begin());
		cout << str3 << endl;
		str3.clear();
	}
	return 0;
}