#include<iostream>
#include<vector>
using namespace std;
int func(vector<int>& vec,int k)
{
	size_t size = vec.size();
	int i = 0;   //一个标记的是下一个替换的位置 
	int j = 0;    //一个标记的是现在遍历的位置
	int count = 0;
	while(i < size)
	{
		while (j < size && vec[j] != k)
		{
			j++;
		}
		i = j;
		while (i < size && vec[i] == k)
		{
			i++;
		}
		if (i < size)
		{
			swap(vec[i], vec[j]);
			count++;
		}
	}
	return size - count;
}

int searchInsert(vector<int>& nums, int target) {
	int L = 0;
	int R = nums.size() - 1;
	int middle = 0;
	if (target < nums[0])
		return 0;
	if (target > nums[nums.size() - 1])
		return nums.size();
	while (L <= R)
	{
		middle = L + ((R - L) >> 1) ;
		if (nums[middle] < target)
			L = middle + 1;
		else if (nums[middle] > target)
			R = middle - 1;
		else
			return middle;
	}

	return L + (L - R);
}

int main()
{
	/*int x = 10;
	int y = 10;
	x = y = ++y;
	cout << x << y << endl;*/
	/*vector<int> vec{ 3, 3 };
	cout << func(vec, 3);
	for (auto e : vec)
	cout << e << endl;*/
	vector<int> vec{ 1, 3, 5, 6 };
	//cout << searchInsert(vec, 2) << endl;
	searchInsert(vec, 2);


	//int c = 'A' + 1.6;
	//cout << c << endl;

	return 0;
}

//#include<iostream>
//using namespace std;
//void func(int *a, int length, int find)
//{
//	int L = 0;
//	int R = length - 1;
//	int flat = 0;
//	while (L <= R)
//	{
//		int middle = L + ((R - L) >> 1);
//		if (find < a[middle])
//		{
//			R = middle - 1;
//		}
//		else if (find > a[middle])
//		{
//			L = middle + 1;
//		}
//		else
//		{
//			printf("%d\n", middle);
//			flat = 1;
//			break;
//		}
//	}
//	if (flat = 0)
//	{
//		printf("没找到\n");
//	}
//}
//int main()
//{
//	int a[10] = { 1, 2, 5, 7 };
//	func(a, 4, 5);
//	return  0;
//}
//
//
//
