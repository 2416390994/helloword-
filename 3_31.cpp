#include<iostream>
#include<vector>
using namespace std;
//int minNumberInRotateArray(vector<int> rotateArray) {
//	if (rotateArray.size() < 0)
//		return 0;
//	int L = 0;
//	int R = rotateArray.size() - 1;
//	int M = (R + L) / 2;
//	while (L < R)
//	{
//		if (rotateArray[R] > rotateArray[L])
//			return rotateArray[L];
//		M = (R + L) / 2;
//
//		if (rotateArray[M] > rotateArray[L])
//		{
//			L = M + 1;
//		}
//		else if (rotateArray[M] < rotateArray[R])
//		{
//			R = M;
//		}
//		else
//		{
//			L++;
//		}
//
//	}
//	return rotateArray[L];
//}
//
//int  NumberOf1(int n) {
//	int count = 0;
//	while (n)
//	{
//		if ((n & 0x1) == 1)
//		{
//			count++;
//		}
//		n >>= 1;
//		if (n == -1)
//			break;
//	}
//	return count;
//}

//double Power(double base, int exponent) {
//	if (exponent == 0)
//		return 1;
//	if (base == 0)
//		return 0;
//	double c = base;
//	while (--exponent)
//	{
//		c = c * base;
//	}
//	return c;
//}

void reOrderArray(vector<int> &array) {
	int x = array.size();
	int y = 0;
	while (x)
	{
		if (array[y] % 2 == 0)
		{
			int a = array[y];
			array.erase(array.begin() + y);
			array.push_back(a);
		}
		else
		{
			y++;
		}
		--x;
	}
}
int main()
{
	//cout << Power(2, 3) << endl;
	//cout<<NumberOf1(-10);
	vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	reOrderArray(vec);

	for (auto e : vec)
		cout << e << endl;
	//cout << minNumberInRotateArray(vec) << endl;
	return 0;
}