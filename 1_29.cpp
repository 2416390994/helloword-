#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int myAtoi(string str) {
	size_t size = str.size();
	int flag = 0;
	int i = 0;
	while (i < size)
	{
		if (str[i] == ' ')
			++i;
		else if (str[i] == '+' || str[i] == '-' || ('0' <= str[i] && str[i] <= '9'))
			break;
		else
			return 0;
	}
	if (str[i] == '-')
	{
		flag = 1;
		++i;
	}
	int num = 0;
	int s = 0;
	int count = 0;
	int first = 0;
	for (; i < size; ++i)
	{

		if ('0' <= str[i] && str[i] <= '9')
		{
			s = str[i] - '0';
			num = (num * 10) + s;
		}
		else
			break;
	}
	if (flag == 1)
		return -num;
	return num;
}

bool isPalindrome(string s) {
	if (s.size() == 0)
		return true;
	size_t size = s.size();
	int i = 0;
	int j = size - 1;
	int flag = 0;
	while (i <= j)
	{
		while (i <= j)
		{
			if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z' || '0' <= s[i] && s[i] <= '9')
			{
				flag = 1;
				break;
			}
			else
				++i;
		}
		while (i <= j)
		{
			if ('a' <= s[j] && s[j] <= 'z' || 'A' <= s[j] && s[j] <= 'Z' || '0' <= s[j] && s[j] <= '9')
			{
				flag = 1;
				break;
			}
			else
				--j;
		}
		
		if (flag == 1)
		{
			flag = 0;
			if (s[i] == s[j] || s[i] == (s[j] + 32) || s[i] == (s[j] - 32))
			{
				if (('0' <= s[i] && s[i] <= '9') && ('0' > s[j] || s[j] > '9') || ('0' > s[i] || s[i] > '9') && ('0' <= s[j] && s[j] <= '9'))
					return false;
				++i;
				--j;
			}
			else
				return false;
		}
	}
	return true;
}


int compress(vector<char>& chars) {
	sort(chars.begin(), chars.end());
	size_t size = chars.size();
	for (auto i = chars.begin(); i != chars.end(); ++i)
	{
		int count = 1;
		auto j = i;
		while (j + 1 != chars.end() && *j == *(j + 1))
		{
			count++;
			j++;
		}
		if (count == 1)
		{
		}
		else
		{
			if (count == 2)
				*(++i) = '2';
			else
			{
				string s = to_string(count);
				for (int x = 0; x < s.size(); ++x)
				{
					*(++i) = s[x];
				}
				chars.erase(i + 1, j + 1);
			}
		}
	}
	return chars.size();
}

int evalRPN(vector<string>& tokens) {
	auto i = tokens.begin();
	auto j = tokens.begin();
	while (tokens.size() > 1)
	{
		if (*i != "+" && *i != "-" && *i != "*" && *i != "/")
		{
			++i;
		}
		else
		{
			j = i - 2;
			if (*i == "+")
			{
				int left = atoi((*(i - 2)).c_str());
				int right = atoi((*(i - 1)).c_str());
 				int ss = left + right;
				*(i - 2) = to_string(ss);
				tokens.erase(i - 1, i + 1);
			}
			else if (*i == "-")
			{
				int left = atoi((*(i - 2)).c_str());
				int right = atoi((*(i - 1)).c_str());
				int ss = left - right;
				*(i - 2) = to_string(ss);
				tokens.erase(i - 1, i + 1);
			}
			else if (*i == "*")
			{
				int left = atoi((*(i - 2)).c_str());
				int right = atoi((*(i - 1)).c_str());
				int ss = left * right;
				*(i - 2) = to_string(ss);
				tokens.erase(i - 1, i + 1);
			}
			else
			{
				int left = atoi((*(i - 2)).c_str());
				int right = atoi((*(i - 1)).c_str());
				int ss = left / right;
				*(i - 2) = to_string(ss);
				tokens.erase(i - 1, i + 1);
			}
			i = j;
		}
	}
	return atoi(tokens[0].c_str());
}

int main()
{
	vector<string> vec = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
	cout << evalRPN(vec) << endl;
	//int a = 1;
	//int *p = &a;
	//a = *p++;
	//cout <<  *p << endl;
	//cout << a << endl;
	//vector<char> vec = { 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	////searchRange(vec, 1);
	///cout << isPalindrome("0P");
	//cout << compress(vec);
	//cout << (char)'0' + 32 << endl;
	return 0;
}