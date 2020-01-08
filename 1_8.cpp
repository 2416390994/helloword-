#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//	int InversePairs(vector<int> data) {
//		int length = data.size();
//		if (length <= 0)
//			return 0;
//		//vector<int> copy=new vector<int>[length];
//		vector<int> copy;
//		for (int i = 0; i<length; i++)
//			copy.push_back(data[i]);
//		long long count = InversePairsCore(data, copy, 0, length - 1);
//		//delete[]copy;
//		return count % 1000000007;
//	}
//	long long InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
//	{
//		if (start == end)
//		{
//			copy[start] = data[start];
//			return 0;
//		}
//		int length = (end - start) / 2;
//		long long left = InversePairsCore(copy, data, start, start + length);
//		long long right = InversePairsCore(copy, data, start + length + 1, end);
//
//		int i = start + length;
//		int j = end;
//		int indexcopy = end;
//		long long count = 0;
//		while (i >= start&&j >= start + length + 1)
//		{
//			if (data[i]>data[j])
//			{
//				copy[indexcopy--] = data[i--];
//				count = count + j - start - length;          //count=count+j-(start+length+1)+1;
//			}
//			else
//			{
//				copy[indexcopy--] = data[j--];
//			}
//		}
//		for (; i >= start; i--)
//			copy[indexcopy--] = data[i];
//		for (; j >= start + length + 1; j--)
//			copy[indexcopy--] = data[j];
//		return left + right + count;
//	}
//};
//int Add(int num1, int num2)
//{
//	vector<int> vec1;
//	vec1.resize(num1);
//	auto it = vec1.begin();
//	vec1.insert(it, num2, 0);
//	return vec1.size();
//}
int Add(int num1, int num2)
{
	string str1;
	str1.resize(num1);
	string str2;
	str2.resize(num2);
	str1.append(str2.begin(), str2.end());
	return str1.size();
}
int main()
{
	cout << Add(100, 100);
	//vector<int> a{ 5, 8, 9, 4, 6, 2, 1 };
	//Solution b;
	//b.InversePairs(a);

	return 0;
}