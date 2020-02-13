//#include<iostream>
//#include<vector>
//using namespace std;
//int func()
//{
//	int a;
//	int b;
//	cin >> a; 
//	int num = 0;
//	int count = 0;
//	for (int i = 0; i < a; ++i)
//	{
//		cin >> b;
//		if (i == 0 && b < 0)
//		{
//			num = b;
//			count = b;
//		}
//		else
//			num += b;
//		if (count < num)
//		{
//			count = num;
//		}
//		if (num < 0)
//		{
//			num = 0;
//		}
//	}
//	return count;
//}
//
//bool func2()
//{
//	int num = 0;
//	int a = 7, b = 3,  c = 1,  d = 6;
//	for (int i = 0; i < 4; ++i)
//	{
//		for (int j = 0; j < 4; ++j)
//		{
//			for (int k = 0; k < 4; ++k)
//			{
//				if (i == 0)
//					num = a + b;
//				else if (i == 1)
//					num = a - b;
//				else if (i == 2)
//					num = a * b;
//				else
//					num = a / b;
//				
//
//				if (j == 0)
//					num = num + c;
//				else if (j == 1)
//					num = num - c;
//				else if (j == 2)
//					num = num * c;
//				else
//					num = num / c;
//
//				if (k == 0)
//					num = num + d;
//				else if (k == 1)
//					num = num - d;
//				else if (k == 2)
//					num = num * d;
//				else
//					num = num / d;
//
//				if (num == 24)
//				{
//					cout << i << endl;
//					cout << j << endl;
//					cout << k << endl;
//					return true;
//
//				}
//				num = 0;
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	cout << func() << endl;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//class A
//{
//
//
//};
//
//
//
//int main()
//{
//	A* a = new A;
//	cout << sizeof(a) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
////int main()
////{
////	string s1;
////	string s2;
////	while (getline(cin, s1))
////	{
////		getline(cin, s2);
////		int array[256] = { 0 };
////		for (int i = 0; i < s2.size(); ++i)
////		{
////			array[s2[i]] = 1;
////		}
////		string s3;
////		for (int i = 0; i < s1.size(); ++i)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
////		{
////			if (array[s1[i]] != 1)
////			{
////				s3.push_back(s1[i]);
////			}
////		}
////		cout << s3 << endl;
////	}
////	return 0;
////}
//int func()
//{
//	vector<int> vec;
//	int a;
//	int b;
//	int c;
//	int d;
//	int flag = 0;
//
//		cin >> a >> b >> c >> d;
//		for (int x = 0; x < 24; ++x)
//		{
//			int q = a;
//			int w = b;
//			int e = c;
//			int r = d;
//			if (x == 0)
//			{
//				a = e; b = q; c = r; d = w;
//			}
//			else if (x == 1)
//			{
//				a = r; b = e; c = q; d = w;
//			}
//			else if (x == 2)
//			{
//				a = e; b = r; c = q; d = w;
//			}
//			else  if (x == 3)
//			{
//				a = e; b = q; c = w; d = r;
//			}
//			else if (x == 4)
//			{
//				a = r; b = q; c = e; d = w;
//			}
//			else if (x == 5)
//			{
//				a = q; b = r; c = e; d = w;
//			}
//			else if (x == 6)
//			{
//				a = q; b = e; c = r; d = w;
//			}
//			else if (x == 7)
//			{
//				a = q; b = e; c = w; d = r;
//			}
//			else if (x == 8)
//			{
//				a = r; b = q; c = w; d = e;
//			}
//			else if (x == 9)
//			{
//				a = q; b = r; c = w; d = e;
//			}
//			else if (x == 10)
//			{
//				a = q; b = w; c = r; d = e;
//			}
//			else if (x == 11)
//			{
//				a = q; b = w; c = e; d = r;
//			}
//			else  if (x == 12)
//			{
//				a = r; b = e; c = w; d = q;
//			}
//			else if (x == 13)
//			{
//				a = e; b = r; c = w; d = q;
//			}
//			else if (x == 14)
//			{
//				a = e; b = w; c = r; d = q;
//			}
//			else if (x == 15)
//			{
//				a = r; b = w; c = q; d = r;
//			}
//			else if (x == 16)
//			{
//				a = r; b = w; c = e; d = q;
//			}
//			else if (x == 17)
//			{
//				a = w; b = r; c = e; d = q;
//			}
//			else if (x == 18)
//			{
//				a = w; b = e; c = r; d = q;
//			}
//			else if (x == 19)
//			{
//				a = w; b = e; c = q; d = r;
//			}
//			else if (x == 20)
//			{
//				a = r; b = w; c = q; d = c;
//			}
//			else if (x == 21)
//			{
//				a = w; b = r; c = q; d = e;
//			}
//			else if (x == 22)
//			{
//				a = w; b = q; c = r; d = e;
//			}
//			else if (x == 23)
//			{
//				a = w; b = q; c = e; d = r;
//			}
//			int num;
//			for (int i = 0; i < 4; ++i)
//			{
//				for (int j = 0; j < 4; ++j)
//				{
//					for (int k = 0; k < 4; ++k)
//					{
//						if (i == 0)
//							num = a + b;
//						else if (i == 1)
//							num = a - b;
//						else if (i == 2)
//							num = a * b;
//						else
//							num = a / b;
//
//						if (j == 0)
//							num = num + c;
//						else if (j == 1)
//							num = num - c;
//						else if (j == 2)
//							num = num * c;
//						else
//							num = num / c;
//
//						if (k == 0)
//							num = num + d;
//						else if (k == 1)
//							num = num - d;
//						else if (k == 2)
//							num = num * d;
//						else
//							num = num / d;
//
//
//						if (num == 24)
//						{
//							cout << i << j << k << endl;
//							flag = 1;
//							return 1;
//						}
//					}
//				}
//			}
//		}
//	return -1;
//}
//
//
//int main()
//{
//	int a;
//	while (a = func())
//	{
//		
//		if (a == -1)
//			cout << "false" << endl;
//		else
//			cout << "ture" << endl;
//	}
//	return 0;
//}
//
//
//
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void func(vector<int>& vec)
{
	for (auto e : vec)
		cout << e << endl;
}
class A
{
	friend ostream& operator<<(const ostream& _cout, A& a);
public:
	A()
	{
		a = 10;
	}
	A(const A& b)
	:a(b.a)
	{
	}
	
	int a; 
};
ostream& operator<<(ostream& _cout,const A& a)
{
	_cout << a.a;
	return _cout;
}
void* mymemset(void * a, void* ptr, int val, int count)
{
	void* ret = ptr;
	char * s1 = (char*)ptr;
	char * s2= (char*)a;
	s1++;
	s2++;
	while (count--)
	{
		*s1 = (char)val;
		*s2 = (char)val;
		s1++;
	}
	return ret;
}
void mymemcpy(void *a,void *b,)
{

}
int main()
{
	char s[] = "hello";
	char *a = "123456";
	*s = '2';
	*a = '2';
	cout << *a << endl;
	//mymemset(a, s, 66, 5);
	//cout << s << endl;
	vector<int> vec = { 1, 2, 3};
	return 0;
}
