#include<iostream>
#include<vector>
#include<map>
using namespace std;


vector<int> plusOne(vector<int>& digits) {
	vector<int> vec;
	int flag = 0;
	int i = digits.size() - 1;
	vec.resize(digits.size() + 1);
	digits[i] = digits[i] + 1;
	while (digits[i] == 10)
	{
		digits[i] = 0;
		--i;
		if (i == -1)
		{
			for (int j = 1; j < vec.size(); ++j)
			{
				vec[j] = digits[j - 1];
			}
			vec[0] = 1;
			flag = 1;
			break;
		}
		digits[i] = digits[i] + 1;
	}
	if (flag == 1)
		return  vec;
	return digits;
}

int thirdMax(vector<int>& nums) {
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return nums[1] > nums[0] ? nums[0] : nums[1];
	int max1 = nums[0];
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > max1)
			max1 = nums[i];
	}
	int max2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == max1)
			continue;
		if (max2 < max1 && max2 < nums[i])
			max2 = nums[i];
	}
	int max3 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == max1 || nums[i] == max2)
			continue;
		if (max3 < max2 && max3 < nums[i])
			max3 = nums[i];
	}
	return max3;
}
//int thirdMax(vector<int>& nums) {
//	int max1 = nums[0];
//	int flag1 = 0;
//	int flag2 = 0;
//	int flag3 = 0;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (nums[i] > max1)
//		{
//			max1 = nums[i];
//			flag1 = 1;
//		}
//	}
//	int max2 = INT_MIN;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (nums[i] == max1)
//			continue;
//		if (max2 < max1 && max2 <= nums[i])
//		{
//			max2 = nums[i];
//			flag2 = 1;
//		}
//	}
//	int max3 = INT_MIN;
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		if (nums[i] == max1 || nums[i] == max2)
//			continue;
//		if (max3 < max2 && max3 <= nums[i])
//		{
//			max3 = nums[i];
//			flag3 = 1;
//		}
//	}
//	if (flag3 == 1)
//		return max3;
//	else
//		return max1;
//}
class Singleton {
private: static Singleton* instance;
private: Singleton(){}
public:
	static Singleton* getInstance() {
		return instance;
	}
};
Singleton* Singleton::instance = new Singleton();

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> vec;
	map<int, int> mmap;
	for (int i = 0; i < nums.size(); ++i)
	{
		mmap.insert(make_pair(nums[i], i));
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		if (target = 2 * nums[i])
			continue;
		auto it = mmap.find(target - nums[i]);
		if (it == mmap.end())
			continue;
		else
		{
			vec.push_back(i);
			vec.push_back(it->second);
			break;
		}
	}
	return vec;
}

int main()
{
	//Singleton::getInstance();
	vector<int> vec{ 3, 3 };
	twoSum(vec, 6);
	//cout << thirdMax(vec);
	return 0;
}


