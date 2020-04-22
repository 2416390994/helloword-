//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//int main()
//{
//	int a = 20;
//	//printf("%d,%d,%d,%d,%d,%d,%d,%d", a);
//
//
//	int num1 = 1 / 2;// 0
//	float num2 = 1 / 2.0;//0.5整数与实数的结果是实数
//	float num3 = 3 / 2.0;//1.5
//	float num4 = 3 / 2;//1 整数与整数的结果是整数
//	printf("%d, %f\n", num1, num1);
//	printf("%d\n", num2);
//	printf("%f, %d\n", num3, num3);
//	printf("%f, %d\n", num4, num4);
//
//
//	return 0;
//}

#include<iostream>
#include<vector>
#include<string>
using namespace std;
void func1(vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = 0; j < vec.size() - i - 1; ++j)
		{
			if (vec[j] >vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
}

int main()
{
	vector<int> vec = { 7, 4, 1, 8, 5, 2, 0, 9, 6, 3 };

	func1(vec);

	for (auto e : vec)
		cout << e << endl;
	return 0;
}











