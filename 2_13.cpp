#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int func(int num)
{
	if (num == 1 || num == 2)
		return 1;
	return (num - 1) + (num - 2);                     
}

class Solution {
public:
	string addStrings(string num1, string num2) {
		int num1size = num1.size();
		int num2size = num2.size();
		if (num1size < num2size)  //让num1中始终保存的是两个字符串中较长的那一个
		{
			swap(num1, num2);
			swap(num1size, num2size);
		}
		string strRet(num1size + 1, '0');   //然后利用较长的一个字符串给返回的 字符串确定长度
		int offset = 0;  //这个标志位使用来记录是否进位的标志
		for (int i = num1size - 1, j = num2size - 1; i >= 0; --i, --j)  //注意看外部的循环是较长的字符串
		{
			char cret = num1[i] - '0';  //这里的cret是一个字符，但是用的是ASCII标志的字符，记录的却是字符代表的数字
			if (j >= 0)  //因为num2比较短，所以要进行判断，是否还能够从num2中读取到字符
			{
				cret += num2[j] - '0';  //可以读取到的话继续累加
			}
			cret += offset;  //并且还要类加上上一次的进位，第一次的话就是0，也不影响啥
			offset = 0;  //标志位累加之后
			if (cret >= 10)
			{
				offset = 1;  //内部的主要作用就是让标志位记录下来，他大于10，然后够将10卸载下来，但是卸载下来的10用标志位保存着，
				cret -= 10;  //卸载10
			}
			strRet[i + 1] += cret;  //然后将剩余的个位数加到现在的位置
			//注意这里的+=，因为在循环之前我们申请的一个字符串中都已经被初始化成了000000000，所以现在就等于是在字符0的基础之上加数字,但是加的数字不会大于10，因为之前的10 已经卸载了
		}
		if (offset == 1)  //最后循环出来之后还需要再判断一次，判断最后一次到底有没有offset标志位
		{
			strRet[0] += 1;  //有的话就在最前面的空间加上1
		}
		else
			strRet.erase(strRet.begin());  //不然的话就把最前面的一个空间消除掉
		return strRet;
	}
};
namespace name
{
	class mystring
	{
		friend ostream& operator<<(ostream& _cout, const mystring& p);
	public:
		mystring(char*  s = "")
		{
			if (s == nullptr)
			{
				s = "";
			}
			ptr = new char[strlen(s) + 1];
			strcpy(ptr, s);
		}
		mystring(const mystring& s)
		{
			ptr = new char[strlen(s.ptr) + 1];
			strcpy(ptr, s.ptr);
		}
		mystring& operator=(const mystring& s)
		{
			if (this != &s)
			{
				delete ptr;
				ptr = new char[strlen(s.ptr) + 1];
				strcpy(ptr, s.ptr);
			}
			return *this;
		}
		int size()
		{
			return strlen(ptr);
		}
		~mystring()
		{
			if (ptr)
			{
				delete ptr;
				ptr = nullptr;
			}
		}
	private:
		char* ptr;
	};
	ostream& operator<<(ostream& _cout, const mystring& p)
	{
			_cout << p.ptr;
			return _cout;
	}
};







int main()
{
	name::mystring s;
	cout << s.size() << endl;
	/*char c = 65;
	cout << c << endl;
	string s;
	s = "123456";
	auto it = s.begin();
	cout << *it << endl;
	cout << typeid(s).name() << endl;
	int num = 5;
	cout << func(num) << endl;*/
	return 0;
}