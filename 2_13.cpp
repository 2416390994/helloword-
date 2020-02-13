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
		if (num1size < num2size)  //��num1��ʼ�ձ�����������ַ����нϳ�����һ��
		{
			swap(num1, num2);
			swap(num1size, num2size);
		}
		string strRet(num1size + 1, '0');   //Ȼ�����ýϳ���һ���ַ��������ص� �ַ���ȷ������
		int offset = 0;  //�����־λʹ������¼�Ƿ��λ�ı�־
		for (int i = num1size - 1, j = num2size - 1; i >= 0; --i, --j)  //ע�⿴�ⲿ��ѭ���ǽϳ����ַ���
		{
			char cret = num1[i] - '0';  //�����cret��һ���ַ��������õ���ASCII��־���ַ�����¼��ȴ���ַ����������
			if (j >= 0)  //��Ϊnum2�Ƚ϶̣�����Ҫ�����жϣ��Ƿ��ܹ���num2�ж�ȡ���ַ�
			{
				cret += num2[j] - '0';  //���Զ�ȡ���Ļ������ۼ�
			}
			cret += offset;  //���һ�Ҫ�������һ�εĽ�λ����һ�εĻ�����0��Ҳ��Ӱ��ɶ
			offset = 0;  //��־λ�ۼ�֮��
			if (cret >= 10)
			{
				offset = 1;  //�ڲ�����Ҫ���þ����ñ�־λ��¼������������10��Ȼ�󹻽�10ж������������ж��������10�ñ�־λ�����ţ�
				cret -= 10;  //ж��10
			}
			strRet[i + 1] += cret;  //Ȼ��ʣ��ĸ�λ���ӵ����ڵ�λ��
			//ע�������+=����Ϊ��ѭ��֮ǰ���������һ���ַ����ж��Ѿ�����ʼ������000000000���������ھ͵��������ַ�0�Ļ���֮�ϼ�����,���Ǽӵ����ֲ������10����Ϊ֮ǰ��10 �Ѿ�ж����
		}
		if (offset == 1)  //���ѭ������֮����Ҫ���ж�һ�Σ��ж����һ�ε�����û��offset��־λ
		{
			strRet[0] += 1;  //�еĻ�������ǰ��Ŀռ����1
		}
		else
			strRet.erase(strRet.begin());  //��Ȼ�Ļ��Ͱ���ǰ���һ���ռ�������
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