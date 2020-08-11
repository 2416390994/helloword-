//#include<iostream>
//using namespace std;
//
//class my
//{
//public:
//	static my* ret()
//	{
//		return new my;
//	}
//private:
//	my() = delete;
//	my(const my* p) = delete;
//};
//
//class my2
//{
//public:
//	my2()
//	{
//
//	}
//private:
//	void* operator new(size_t){}
//	void operator delete(void*){}
//};
//
//
//
//
//int main()
//{
//	my* p = my::ret();
//
//
//
//	int * p = (int*)malloc(sizeof(int)* 10);
//	int* p1 = (int*)calloc(10, sizeof(int));
//	int* p2 = (int*)realloc(p1, 50);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//void func()
//{
//	int size;
//	cin >> size;
//	string s;
//	cin >> s;
//	int left = 0;
//	int right = size - 1;
//	int count = 0;
//	while (left < right)
//	{
//		if (s[left] != s[right])
//		{
//			count++;
//		}
//		left++;
//		right--;
//	}
//	cout << count << endl;
//}
//
//
//int main()
//{
//
//	func();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int func2(int num)
//{
//	for (int i = 2; i <= sqrt(num); ++i)
//	{
//		if (num % i == 0)
//		{
//			return i;
//		}
//		
//	}
//	return -1;
//}
//
//
//
//
//void func()
//{
//	int count;
//	cin >> count;
//	while (count--)
//	{
//		int row, col;
//		cin >> row >> col;
//		if (row == 1 && col == 1)
//		{
//			cout << 1 << endl;
//		}
//		else if (row == 1 && col == 2)
//		{
//			cout << 2 << endl;
//		}
//		else if (row == 2 && col == 1)
//		{
//			cout << 2 << endl;
//		}
//		else if (row == 1 && ((col % 2) != 0))
//		{
//			cout << col << endl;
//		}
//		else if (row == 1 && ((col % 2) == 0))
//		{
//			cout << (col / 2) << endl;
//		}
//		else if ((row % 2) != 0 && col == 1)
//		{
//			cout << row << endl;
//		}
//		else if (((row % 2) == 0) && col == 1)
//		{
//			cout << (row / 2) << endl;
//		}
//		else if (((row % 2) == 0) && ((col % 2) == 0))
//		{
//			cout << 2 << endl;
//		}
//		else
//		{
//			int ret1 = func2(row);
//			int ret2 = func2(col);
//			cout << ret1 << endl;
//			cout << ret2 << endl;
//			while ((ret1 != -1) || (ret2 != -1))
//			{
//				if (ret1 != -1)
//				{
//					row /= ret1;
//				}
//				if (ret2 != -1)
//				{
//					col /= ret2;
//				}
//				ret1 = func2(row);
//				ret2 = func2(col);
//			}
//			int min = row > col ? col : row;
//			cout << min << endl;
//		}
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
#include<math.h>
#include<vector>
using namespace std;
int func2(long long num)
{
	for (long long i = 2; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			return i;
		}
	}
	return -1;
}

void func()
{
	vector<long long> vec;
	long long count;
	cin >> count;
	while (count--)
	{
		long long row, col;
		cin >> row >> col;

		if (row == 1 && col == 1)
		{
			cout << 1 << endl;
		}
		else if (((row % 2) == 0) || ((col % 2) == 0))
		{
			cout << 2 << endl;
		}
		else if (row == 1 || col == 1)
		{
			int ret1 = func2(row);
			int ret2 = func2(col);
			while ((ret1 != -1) || (ret2 != -1))
			{
				if (ret1 != -1)
				{
					row /= ret1;
				}
				if (ret2 != -1)
				{
					col /= ret2;
				}
				ret1 = func2(row);
				ret2 = func2(col);
			}
			int min = row > col ? row : col;
			cout << min << endl;
		}
		else
		{
			int ret1 = func2(row);
			int ret2 = func2(col);
			while ((ret1 != -1) || (ret2 != -1))
			{
				if (ret1 != -1)
				{
					row /= ret1;
				}
				if (ret2 != -1)
				{
					col /= ret2;
				}
				ret1 = func2(row);
				ret2 = func2(col);
			}
			int min = row < col ? row : col;
			vec.push_back(min);
		}
	}
	for (long long i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
}


int main()
{
	func();
	return 0;
}