#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#if 0
bool istypeid(const char* types)
{
	//此处可以将所有的内置类型枚举出来
	const char* typesid[] = { "int", "double", "long long" };
	for (auto e : typesid)
	{
		if (strcmp(types, e) == 0)  //相等返回0
			return true;
	}
	return false;
}
template<class T>
void Copy(T* A, T* B, int _size)
{
	//通过typeid()可以将T的实际类型按照字符串的方式返回
	if (istypeid(typeid(T).name()))
	{
		memcpy(A, B, sizeof(T)*_size);
	}
	else
	{
		for (int i = 0; i < _size; ++i)
		{
			A[i] = B[i];
		}
	}
}
#endif
struct TrueType
{};
struct FalseType
{};
template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;
};
template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};
template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};
template<>
struct TypeTraits<long long>
{
	typedef TrueType PODTYPE;
};
template<>
struct TypeTraits<double>
{
	typedef TrueType PODTYPE;
};
template<class T>
void Copy(T* A, T* B, int _size,TrueType)
{
	memcpy(A, B, sizeof(T)*_size);
}
template<class T>
void Copy(T* A, T* B, int _size, FalseType)
{
	for (int i = 0; i < _size; ++i)
	{
		A[i] = B[i];
	}
}
template<class T>
void _Copy(T* A, T* B, int _size)
{
	Copy(A, B, _size, TypeTraits<T>::PODTYPE());
}
namespace N1
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const string& p);
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& p)
		{
			_str = new char[strlen(p._str) + 1];
			strcpy(_str, p._str);
		}
		string& operator=(const string& p)
		{
			if (this != &p)
			{
				char* temp = new char[strlen(p._str) + 1];
				strcpy(temp, p._str);
				delete[] _str;
				_str = temp;
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
void test1()
{
	int a[] = { 1, 2, 3 };
	int b[3] = {};
	_Copy(b, a, 3);
	cout << b[0] << endl;
	cout << b[1] << endl;
	cout << b[2] << endl;
}
void test2()
{
	N1::string s1[3]{"111", "222", "333"};
	N1::string s2[3];
	_Copy(s2, s1, 3);
}
class date
{
public:
	void func()
	{}
	date()
	{
		cout << "dhaei" << endl;
	}
};
void test(date& p)
{
}
int main()
{
	//test1();
	test2();
	test(date());
	return 0;
}

