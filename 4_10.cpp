#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	void Permutation1(vector<string> &array, string str, int begin,int size)//遍历第begin位的所有可能性
	{
		if (begin == size)
			array.push_back(str);
		for (int i = begin; i < size; ++i)
		{
			if (i != begin && str[i] == str[begin])
				continue;
			swap(str[i], str[begin]);
			Permutation1(array, str, begin++, size);
			swap(str[i], str[begin]);
		}
	}

	vector<string> Permutation(string str) {
		vector<string> vec;
		if (str.size() == 0)
			return vec;
		Permutation1(vec, str, 0,vec.size() - 1);
		return vec;
	}
};



class Solution {
public:
	void Permutation1(vector<string> &array, string str, int begin)//遍历第begin位的所有可能性
	{
		if (begin == str.size() - 1)
			array.push_back(str);
		for (int i = begin; i <= str.size() - 1; i++)
		{
			if (i != begin && str[i] == str[begin])//有重复字符时，跳过
				continue;
			swap(str[i], str[begin]);//当i==begin时，也要遍历其后面的所有字符；
			//当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
			Permutation1(array, str, begin + 1);//遍历其后面的所有字符；

			//swap(str[i], str[begin]);//为了防止重复的情况，还需要将begin处的元素重新换回来

			/*举例来说“abca”，为什么使用了两次swap函数
			交换时是a与b交换，遍历；
			交换时是a与c交换，遍历；（使用一次swap时，是b与c交换）
			交换时是a与a不交换；
			*/
		}
	}

	vector<string> Permutation(string str) {
		//可以用递归来做
		vector<string> array;
		if (str.size() == 0)
			return array;
		Permutation1(array, str, 0);
		sort(array.begin(), array.end());
		return array;
	}
};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		int count;
		int flag = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (flag == 0)
			{
				count = numbers[i];
				flag = 1;
			}
			else
			{
				if (numbers[i] == count)
					flag++;
				else
					flag--;
			}
		}
		if (flag == 0)
			return 0;
		sort(numbers.begin(), numbers.end());
		if (count == numbers[numbers.size() / 2])
			return count;
		else
			return 0;
	}
};