#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	void Permutation1(vector<string> &array, string str, int begin,int size)//������beginλ�����п�����
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
	void Permutation1(vector<string> &array, string str, int begin)//������beginλ�����п�����
	{
		if (begin == str.size() - 1)
			array.push_back(str);
		for (int i = begin; i <= str.size() - 1; i++)
		{
			if (i != begin && str[i] == str[begin])//���ظ��ַ�ʱ������
				continue;
			swap(str[i], str[begin]);//��i==beginʱ��ҲҪ���������������ַ���
			//��i!=beginʱ���Ƚ�����ʹ��beginλȡ����ͬ�Ŀ����ַ����ٱ���������ַ�
			Permutation1(array, str, begin + 1);//���������������ַ���

			//swap(str[i], str[begin]);//Ϊ�˷�ֹ�ظ������������Ҫ��begin����Ԫ�����»�����

			/*������˵��abca����Ϊʲôʹ��������swap����
			����ʱ��a��b������������
			����ʱ��a��c��������������ʹ��һ��swapʱ����b��c������
			����ʱ��a��a��������
			*/
		}
	}

	vector<string> Permutation(string str) {
		//�����õݹ�����
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