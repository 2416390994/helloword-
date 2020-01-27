#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0;
		int j = 0;
		int count1;
		int count2;
		int size1 = name.size();
		int size2 = typed.size();
		while (i < size1)
		{
			if (name[i] != typed[j])
				return false;
			count1 = count2 = 1;
			while (i < size1 && name[i] == name[i + 1])
			{
				i++;
				count1++;
			}
			i++;
			while (j < size2 && name[i - 1] == typed[j] && typed[j] == typed[j + 1])
			{
				j++;
				count2++;
			}
			j++;
			if (count2 < count1)
				return false;
		}
		return true;
	}
};
string reverseOnlyLetters(string S) {
	size_t size = S.size();
	int i = 0;
	int j = size - 1;
	int flag1 = 0;
	int flag2 = 0;
	while (i < j)
	{
		if ('a' <= S[i] && S[i] <= 'z' || 'A' <= S[i] && S[i] <= 'Z')
			flag1 = 1;
		else
			++i;
		if ('a' <= S[j] && S[j] <= 'z' || 'A' <= S[j] && S[j] <= 'Z')
			flag2 = 1;
		else
			--j;
		if (flag1 ==1 &&  flag2 == 1)
		{
			swap(S[i], S[j]);
			flag1 = flag2 = 0;
			++i;
			--j;
		}
	}
	return S;
}

bool isLongPressedName(string name, string typed) {
	int i = 0;
	int j = 0;
	int count1;
	int count2;
	int size1 = name.size();
	int size2 = typed.size();
	while (i < size1)
	{
		if (name[i] != typed[j])
			return false;

		count1 = count2 = 1;
		while (i < size1 && name[i] == name[i + 1])
		{
			i++;
			count1++;
		}
		i++;
		
		while (j < size2 && name[i - 1] == typed[j] && typed[j] == typed[j + 1])
		{
			j++;
			count2++;
		}
		j++;
		if (count2 < count1)
			return false;

		
	}
	return true;
}

float func(float a, int b){ float m = 1, n = 1; int i; for (i = 1; i <b; i++){ m *= a / i; n += m; }return n; }
int pivotIndex(vector<int>& nums) {
	size_t size = nums.size();
	if (size == 0)
		return -1;
	int i = 0;
	int j = size - 1;
	int sum1 = nums[i];
	int sum2 = nums[j];
	while (i < j)
	{
		if (sum1 > sum2 && nums[j - 1] >= 0)
		{
			sum2 += nums[--j];
		}
		else if (sum1 < sum2 && nums[i + 1] >= 0)
		{
			sum1 += nums[++i];
		}
		else
		{
			sum2 += nums[--j];
			sum1 += nums[++i];
			if (j == i)
				return j;
		}
	}
	return -1;
}

int main()
{
	vector<int> vec = {-1, -1, -1, -1, 0, 1};

	cout << pivotIndex(vec) << endl;
	//cout << func(1, 1) << endl;
	return 0;
}
//int main(){ char *p = "abcdefgh", *r; long *q; q = (long*)p; q++; r = (char*)q; printf("%s\n", r); }
//int main(){char str[]="ABCD", *p=str;
//int i = 0;
//int count = 0;
//cout << str[4] << endl;
//while (str[i++])
//{
//	count++;
//}
//cout << count << endl;
//printf("%d\n", *(p+4));return 0;};
//
//int main()
//{
//
//	//cout << reverseOnlyLetters("7_28]") << endl;
//	//cout << isLongPressedName("xnhtq", "xhhttqq") << endl;
//	return 0;
//}