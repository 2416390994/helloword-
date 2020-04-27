//#include<iostream>
//#include<string>
//#include<vector>
//#include<time.h>
//using namespace std;
//void func(vector<int>& vec)
//{
//	int L = 0;
//	int less = L - 1;
//	int R = vec.size();
//	while (L < R)
//	{
//		if (vec[L] == 1)
//		{
//			swap(vec[++less], vec[L++]);
//		}
//		else if (vec[L] == 2)
//		{
//			L++;
//		}
//		else
//		{
//			swap(vec[--R], vec[L]);
//		}
//	}
//}
//int* func2(vector<int>& vec,int L,int R)
//{
//	int less = L - 1;
//	int more = R;
//	while (L < more)
//	{
//		if (vec[L] < vec[R])
//		{
//			swap(vec[++less], vec[L++]);
//		}
//		else if (vec[L] > vec[R])
//		{
//			swap(vec[--more], vec[L]);
//		}
//		else
//		{
//			L++;
//		}
//	}
//	swap(vec[R], vec[more]);
//	return new int[]{ less, more + 1};
//}
//
//void func1(vector<int>& vec,int L,int R)
//{
//	if (L < R)
//	{
//		swap(vec[R], vec[L + rand() % (R - L) + 1]);
//		int * p = func2(vec, L,R);
//		func1(vec, L, p[0]);
//		func1(vec, p[1], R);
//	}
//	
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	//vector<int> vec = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 3, 2, 1, 2, 2, 3, 3, 1, 1, 2 };
//	
//	
//	//func(vec);
//
//	vector<int> vec = { 7, 4, 1, 8, 5, 2, 9, 6, 3, 0 };
//
//	func1(vec, 0, 9);
//
//	for (auto e : vec)
//		cout << e << " ";
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
//class myqueue
//{
//public:
//	void PUSH(int number)
//	{
//		vec.push(number);
//	}
//	void TOP()
//	{
//		if (vec.size() == 0)
//		{
//			cout << -1 << endl;
//			return;
//		}
//		cout << vec.front() << endl;
//	}
//	void POP()
//	{
//		if (vec.size() == 0)
//		{
//			cout << -1 << endl;
//			return;
//		}
//		vec.pop();
//	}
//	void SIZE()
//	{
//		cout << vec.size() << endl;
//	}
//	void CLEAR()
//	{
//		while (!vec.empty())
//		{
//			vec.pop();
//		}
//	}
//private:
//	queue<int> vec;
//};
//void func()
//{
//	int count;
//	cin >> count;
//	for (int i = 0; i < count; ++i)
//	{
//		int size;
//		cin >> size;
//		myqueue queue;
//		for (int j = 0; j < size; ++j)
//		{
//			string s;
//			cin >> s;
//			if (s == "PUSH")
//			{
//				int a;
//				cin >> a;
//				queue.PUSH(a);
//			}
//			else if (s == "TOP")
//			{
//				queue.TOP();
//			}
//			else if (s == "SIZE")
//			{
//				queue.SIZE();
//			}
//			else if (s == "POP")
//			{
//				queue.POP();
//			}
//			else
//			{
//				queue.CLEAR();
//			}
//		}
//	}
//}
//
//int main()
//{
//	func();
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//#include<queue>
//#include<math.h>
//using namespace std;
//void func()
//{
//	int count;
//	cin >> count;
//	for (int i = 0; i < count; ++i)
//	{
//		int number;
//		cin >> number;
//		vector<int> vec_1_x;
//		vector<int> vec_1_y;
//		vector<int> vec_2_x;
//		vector<int> vec_2_y;
//		for (int j = 0; j < number; ++j)
//		{
//			int a;
//			cin >> a;
//			vec_1_x.push_back(a);
//			cin >> a;
//			vec_1_y.push_back(a);
//		}
//		for (int j = 0; j < number; ++j)
//		{
//			int a;
//			cin >> a;
//			vec_2_x.push_back(a);
//			cin >> a;
//			vec_2_y.push_back(a);
//		}
//		float sum = INT_MAX;
//		for (int x_1 = 0, y_1 = 0; x_1 < number, y_1 < number; ++x_1, ++y_1)
//		{
//			for (int x_2 = 0,  y_2 = 0; x_2 < number, y_2 < number; ++x_2, ++y_2)
//			{
//				float min = sqrt(((vec_1_x[x_1] - vec_2_x[x_2]) * (vec_1_x[x_1] - vec_2_x[x_2])) + ((vec_1_y[y_1] - vec_2_y[y_2])* (vec_1_y[y_1] - vec_2_y[y_2])));
//				if (min < sum)
//				{
//					sum = min;
//				}
//			}
//		}
//		printf("%.3f\n", sum);
//	}
//}
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;
void func()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		int a, b;
		cin >> a >> b;
		int sum = 1;
		int number = 1;
		while (number < a)
		{
			number = (number <<= 1) + 1;
			sum++;
		}
		if (b >= sum)
		{
			cout << -1 << endl;
			break;
		}
		int flag = 0;
		while (--sum)
		{
			a >>= 1;
			if (b == sum)
			{
				flag = 1;
				cout << a << endl;
				break;
			}
		}
		if (flag == 0)
		cout << -1 << endl;
	}
}

int main()
{
	long long
	unsigned int a = INT_MAX;
	cout << a << endl;
	func();
	return 0;
}
//class myqueue
//{
//public:
//	void PUSH(int number)
//	{
//		sta1.push(number);
//	}
//	void POP()
//	{
//		if (sta1.empty())
//		{
//			return;
//		}
//		while (!sta1.empty())
//		{
//			sta2.push(sta1.top());
//			sta1.pop();
//		}
//		sta2.pop();
//		while (!sta2.empty())
//		{
//			sta1.push(sta2.top());
//			sta2.pop();
//		}
//	}
//	void FRONT()
//	{
//		if (sta1.empty())
//		{
//			return;
//		}
//		while (!sta1.empty())
//		{
//			sta2.push(sta1.top());
//			sta1.pop();
//		}
//		cout << sta2.top() << endl;
//		while (!sta2.empty())
//		{
//			sta1.push(sta2.top());
//			sta2.pop();
//		}
//	}
//private:
//	stack<int> sta1;
//	stack<int> sta2;
//};
//
//void func()
//{
//	int count;
//	cin >> count;
//	myqueue queue;
//	for (int i = 0; i < count; ++i)
//	{
//		string s;
//		cin >> s;
//		if (s == "add")
//		{
//			int a;
//			cin >> a;
//			queue.PUSH(a);
//		}
//		else if (s == "peek")
//		{
//			queue.FRONT();
//		}
//		else
//		{
//			queue.POP();
//		}
//
//	}
//}
//int main()
//{
//	func();
//	return 0;
//}


