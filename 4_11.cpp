//#include<iostream>
//#include<vector>
//using namespace std;
//void func()
//{
//	int a;
//	while (cin >> a)
//	{
//		vector<int> vec;
//
//		for (int i = 0; i < a; ++i)
//		{
//			int b;
//			cin >> b;
//			vec.push_back(b);
//		}
//		for (int i = 0; i < vec.size(); ++i)
//		{
//			unsigned long long first = 1;
//			unsigned long long second = 2;
//			unsigned long long third = 0;
//			while (--vec[i])
//			{
//				third = first + second;
//				first = second;
//				second = third;
//			}
//			printf("%04ld", (first % 10000));
//		}
//
//	}
//
//}
//
///*
//6
//18 15 21 13 25 27
//5
//1 10 100 1000 10000
//
//*/
//int main()
//{
//
//	func();
//
//	return 0;
//}







#include<iostream>
#include<string>
#include<vector>
using namespace std;
void func()
{
	string a;
	while (cin >> a)
	{
		int b = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			b += a[i] - '0';
		}


		int c = 0;
		if (b < 10)
		{
			cout << b << endl;
			continue;
		}

		while (b >= 10)
		{
			while (b)
			{
				c += (b % 10);
				b = b / 10;
			}
			if (c >= 10)
			{
				b = c;
				c = 0;
			}
		}
		cout << c << endl;
	}

}

int main()
{
	func();


	return 0;
}

