//#include<iostream>
//using  namespace std;
//int main()
//{
//	unsigned long long a, b;
//	a = 0;
//	b = 0;
//	unsigned long long sun;
//	unsigned long long count;
//	while (cin >> a >> b)
//	{
//		if (a < 1 || a > b || b > 1e9)
//			return -1;
//		sun = 0;
//		count = 0;
//		for (unsigned long long i = 1; i <= a; ++i)
//		{
//			unsigned long long j = i;
//			while (j / 10 != 0)
//			{
//				sun += j % 10;
//				j = j / 10;
//			}
//			if (j / 10 == 0)
//			{
//				sun = sun + j;
//			}
//		}
//		count = (sun % 3 == 0) ? ++count : count;
//		for ( unsigned long long i = a + 1; i <= b; ++i)
//		{
//			unsigned long long j = i;
//			while (j / 10 != 0)
//			{
//				sun += j % 10;
//				j = j / 10;
//			}
//			if (j / 10 == 0)
//			{
//				sun = sun + j;
//			}
//			count = (sun % 3 == 0) ? ++count : count;
//		}	
//		cout << count << endl;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	
//	cout << "value a = " << a << endl;
//	cout << "value *p = " << p << endl;
//	cout << "address a = " << &a << endl;
//	cout << "address p = " << p << endl;
//	return 0;
//}