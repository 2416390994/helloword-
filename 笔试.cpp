////#include<iostream>
////#include<vector>
////#include<string>
////using namespace std;
////
////vector<int> DistanceToHigher(vector<int>& height) {
////	// write code here
////	vector<int> vec;
////	int size = height.size();
////	for (int i = 0; i < size; i++)
////	{
////		int j;
////		for (j = i - 1; j >= 0; --j)
////		{
////			if (height[j] > height[i])
////			{
////				vec.push_back(i - j);
////				break;
////			}
////		}
////		if (j < 0)
////			vec.push_back(0);
////	}
////	return vec;
////}
////
////int main()
////{
////	//vector<int> vec{ 175, 179, 174, 163, 176, 177 };
////	//vector<int> vvec = DistanceToHigher(vec);
////	string s = "100";
////	int a  = atoi(s.c_str());
////	cout << a << endl;
////	return 0;
////}
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void funv()
{
	string str;
	while (getline(cin, str))
	{
		size_t size = str.size();
		vector<int> vec;
		for (int i = 0; i < size; ++i)
		{
			string s;
			while (i < size && str[i] != ' ')
			{
				s += str[i];
				i++;
			}
			vec.push_back(atoi(s.c_str()));
		}
		size_t size2 = vec.size();
		int max = vec[0];
		int flag = 0;
		for (int i = 0; i < size2 - 1; ++i)
		{

			if (i == 0 && vec[0] > vec[1])
			{
				flag = 1;
				cout << 2<< " ";
			}
			if (max < vec[i] && vec[i + 1] < vec[i] && (vec[i + 1] > max || vec[i + 1] == max))
			{
				flag = 1;
				cout << i + 1 << " ";
				max = vec[i];
				i += 1;
			}
			if (max < vec[i])
			{
				max = vec[i];
			}
		}
		if (flag == 0)
			cout << -1;
		cout << endl;
	}
}
//1 22 22 33 22 12 45 44 5
int main()
{

	funv();
	return 0;
}
//
//
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void funv()
{
	string s;
	getline(cin, s);
	size_t size = s.size();
	vector<string> vec1;
	vector<string> vec2;

	for (int i = 0; i < size; ++i)
	{
		string str;
		while (i < size && s[i] != ',')
		{
			str += s[i];
			i++;
		}
		//уркЁвс
		int count = 0;
		for (int j = 0; j < str.size() - 1; ++j)
		{
			int max = 0;
			while (j < str.size() - 1 && str[j] + 1 == str[j + 1])
			{
				max++;
				j++;
			}
			if (max > count)
				count = max;
			max = 0;
		}
		if (count >= 2)
		{
			vec1.push_back(str);
			vec1.push_back(to_string(count + 1));
			count = 0;
		}

		//ур╤твс
		int count2 = 0;
		for (int j = 0; j < str.size() - 1; ++j)
		{
			int max = 0;
			while (j < str.size() && str[j] == str[j + 1])
			{
				max++;
				j++; 
			}
			if (max > count2)
				count2 = max;
			max = 0;
		}
		if (count2 >= 2)
		{
			vec2.push_back(str);
			vec2.push_back(to_string(count2 + 1));
			count2 = 0;
		}
	}


	cout << 1 << endl;

}



int main()
{
	funv();

	return 0;
}