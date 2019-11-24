//#include<iostream>
//using namespace std;
//bool func(int c)
//{
//	int count = 0;
//	for (int i = 2; i <= (c / 2); ++i)
//	{
//		if (c % i == 0)
//			count += i;
//	}
//	count += 1;
//	if (count == c)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	int size;
//	while (cin >> size)
//	{
//		int count = 0;
//		for (int i = 2; i <= size; ++i)
//		{
//			if (func(i) == true)
//				count += 1;
//		}
//		cout << count << endl;
//		count = 0;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		string str1;
		string str2;
		int i;
		for (i = 0; (i < str.size()) && (str[i] != '-'); ++i)
		{
			str1 += str[i];
		}
		int j = i + 1;
		for (j; j < str.size(); ++j)
		{
			str2 += str[j];
		}
		if (str1 == "joker JOKER" || str2 == "joker JOKER")
			cout << "joker JOKER" << endl;
		else if (str1.size() == 7 && str2.size() == 7)
		{
			if (str1[0] == '2' || str2[0] == '2')
				cout << "2 2 2 2" << endl;
			else if (str1[0] == 'A' || str2[0] == 'A')
				cout << "A A A A" << endl;
			else if (str1[0]  > str2[0])
				cout << str1 << endl;
			else
				cout << str2 << endl;
		}
		else if (str1.size() == 5 && str2.size() == 5)
		{
			if (str1[0] == '2' || str2[0] == '2')
				cout << "2 2 2" << endl;
			else if (str1[0] == 'A' || str2[0] == 'A')
				cout << "A A A" << endl;
			else if (str1[0]  > str2[0])
				cout << str1 << endl;
			else
				cout << str2 << endl;
		}
		else if (str1.size() == 9 && str2.size() == 9)
		{
			string str3;
			string str4;
			str3 += str1[0];
			str3 += str1[1];
			str4 += str2[0];
			str4 += str2[1];
			if (str3 == "10" || str4 == "10")
				cout << "10 J Q K A" << endl;
			else if (str1[0]  > str2[0])
				cout << str1 << endl;
			else
				cout << str2 << endl;
		}
		else if (str1.size() == 10 || str2.size() == 10)
		{
			string str3;
			string str4;
			str3 += str1[0];
			str3 += str1[1];
			str4 += str2[0];
			str4 += str2[1];
			if (str3 == "10" || str4 == "10")
				cout << "10 J Q K A" << endl;
		}
		else if ((str1.size() == 7 && str2.size() != 4) || (str1.size() != 4 && str2.size() == 7))
		{
			if (str1.size() == 7)
				cout << str1 << endl;
			else
				cout << str2 << endl;
		}
		else if (str1.size() == 1 && str2.size() == 1)
		{
			if (str1[0] == '2' || str2[0] == '2')
				cout << '2' << endl;
			else if (str1[0] == 'A' || str2[0] == 'A')
				cout << 'A' << endl;
			else if (str1[0] > str2[0])
				cout << str1 << endl;
			else
				cout << str2 << endl;
		}
		else if (str1.size() == 2 || str2.size() == 2)
		{
			string str3;
			string str4;
			str3 += str1[0];
			str3 += str1[1];
			str4 += str2[0];
			str4 += str2[1];
			if (str3 == "10" || str4 == "10")
				cout << "10" << endl;
		}
		else
			cout << "ERROR" << endl;
	}
	return 0;
}