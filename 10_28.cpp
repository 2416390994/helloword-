#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
#if 0
namespace n1
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const string& p);
	public:
		string(char*  str = "")  //默认的构造函数，给出了缺省参数为的是防止只声明 不初始化
		{
			if (str == nullptr)  //其次就是判空假如外部传递的参数是空的话，
				str = "";     //那就先让指针指向""空字符串再拷贝，最后的结果就是只拷了"\0"
			_str = new char[strlen(str) + 1];  //开辟空间
			strcpy(_str, str);  //拷贝元素
		}
		string(const string& p)
		{
			_str = new char[p.size() + 1];
			strcpy(_str, p._str);
		}
		string& operator=(const string& p)
		{
			if (this != &p) //注意这里比较的是地址
			{
				delete[] _str;  //刚开始我还在这一步进行了判空操作，最后发现没有必要因为，因为所有对象在初始化的时候都有空间，哪怕是个'\0'
				_str = new char[p.size() + 1];
				strcpy(_str, p._str);
			}
			return *this;
		}
		int size()const
		{
			return strlen(this->_str);
		}
		int size()
		{
			return strlen(this->_str);
		}
		char operator[](int x)const
		{
			return _str[x];
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
	ostream& operator<<(ostream& _cout, const string& p)
	{
		for (int i = 0; i < p.size();++i)
		{
			_cout << p[i];
		}
		return _cout;
	}
	void test()
	{
		string s("123");
		string s1(nullptr);
		string s2(s);
		cout << s2 << endl;
		s2 = "456";
		cout << s2 << endl;
	}
}

using namespace n1;
int main()
{
	test();
	return 0;  
}
#endif
#if 0
namespace n1
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const string& p);
	public:
		string(char*  str = "")  //默认的构造函数，给出了缺省参数为的是防止只声明 不初始化
		{
			if (str == nullptr)  //其次就是判空假如外部传递的参数是空的话，
				str = "";     //那就先让指针指向""空字符串再拷贝，最后的结果就是只拷了"\0"
			_str = new char[strlen(str) + 1];  //开辟空间
			strcpy(_str, str);  //拷贝元素
		}
		//但是在此处 又有一个问题就是，vs2013将我们设置的_str，没有初始化的情况下会给成nullptr
		//但是别的编译器就会不一定设置为什么
		//假如现在的_str里面放的是随机值，那么和临时对象交换之后，相当于临时对象指向的是随机值，那么在析构临时对象的时候
		//假如发现不是指向空，而是随机值，而去释放那么代码就崩溃了，但是要是时空的话，就不会去释放，就没事
		string(const string& p)
			//:_str(nullptr) //所以先制空
		{
			string strtemp(p._str);  //使用默认构造函数来构造拷贝构造函数，提高代码复用率，但是这里需要注意的是，使用的是p._str，而不是直接使用对象，否则就是无限递归
			swap(_str, strtemp._str); //交换临时变量和当前对象
		}
		//但是一般自己给自己赋值的可能性比较小，所以又有了一种赋值运算符的重载
		//string& operator=(const string& p)
		//{
		//	if (this != &p) 
		//	{
		//		string strtemp(p); //这里调用的又是拷贝构造函数
		//		swap(_str, strtemp._str);
		//	}
		//	return *this;
		//}
		//重新给出的重载
		string& operator=(string p)  //直接在 传参阶段就调用拷贝构造函数构造出临时对象
		{
			//这个版本根本不用考虑自己给自己赋值，因为就算你是自己给自己赋值，赋值之后还是自己
			swap(_str, p._str);  
			return *this;
		}
		int size()const
		{
			return strlen(this->_str);
		}
		int size()
		{
			return strlen(this->_str);
		}
		char operator[](int x)const
		{
			return _str[x];
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
	ostream& operator<<(ostream& _cout, const string& p)
	{
		for (int i = 0; i < p.size(); ++i)
		{
			_cout << p[i];
		}
		return _cout;
	}
	void test()
	{
		string s("123");
		string s1(nullptr);
		string s2(s);
		cout << s2 << endl;
		s2 = "456";
		cout << s2 << endl;
	}
}

using namespace n1;
int main()
{
	test();
	return 0;
}
#endif
#if 0
namespace n1
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const string& p);
	public:
		string(char*  str = "")  
			:count(new int(1))  //每一个新的资源都是通过构造函数诞生的，所在构造函数的位置多申请一块空间，这空间被共享这块资源的所有对象都可以范围，注意前题是所有共享这一块资源的对象
		{
			if (str == nullptr)  
				str = "";     
			_str = new char[strlen(str) + 1]; 
			strcpy(_str, str);
		}
		string(const string& p)  //拷贝构造就是直接让新 对象的指针全部指向，被共享的资源，只需要使资源计数+1即可
			:_str(p._str)
			, count(p.count)
		{
			++(*count);
		}
		string& operator=(const string& p)
		{
			if (this != &p)
			{
				//if (_str && 0 == (*count)--)  //如果现在
				//{
				//	delete[] _str;
				//	delete count;
				//	count = nullptr;
				//	_str = nullptr;
				//}
				this->~string();  //其实我感觉这里直接调用析构函数，可以增加代码复用性
				_str = p._str;
				count = p.count;
				(*(p.count))++;
			}
			return *this;
		}
		/*void operator=(char& s)
		{
			char * temp1 = new char[strlen(this->_str) + 1];
			strcpy(temp1, _str);
			int * temp2 = new int(1);
			this->~string();
			this->count = temp2;
			this->_str = temp1;
			
		}*/
		int size()const
		{
			return strlen(this->_str);
		}
		int size()
		{
			return strlen(this->_str);
		}
		char operator[](int x)const
		{
			return _str[x];
		}
		char& operator[](int x)
		{
			char * temp1 = new char[strlen(this->_str) + 1];
			strcpy(temp1, _str);
			int * temp2 = new int(1);
			this->~string();
			this->count = temp2;
			this->_str = temp1;
			return this->_str[x];
		}
		~string()
		{
			if ((_str!=nullptr) && (0 == --(*count)))  //简写为if(_str && 0 == --(*count))
			{
				delete[] _str;
				delete count;
				count = nullptr;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		int* count;
	};
	ostream& operator<<(ostream& _cout, const string& p)
	{
		for (int i = 0; i < p.size(); ++i)
		{
			_cout << p[i];
		}
		return _cout;
	}
	void test()
	{
		string s("123");
		string s2(s);
		s2 = "456";
		string s3 = s2;
		s2[0] = 'w';
		cout << s2 << endl;
	}
}
using namespace n1;
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<assert.h>
namespace N1
{
	class string
	{
		
		friend ostream& operator<<(ostream& _cout, const string& p);
	public:
		typedef char* iterator;   //迭代器
	public:
		string(char* str = "")
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = strlen(str);
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const char s, int n)
		{
			_size = n;
			_capacity = n;  //这里的容量没有+1,也就是说没有算最后的'\0'，这一切都是为了遵循，string本来的面貌
			_str = new char(n + 1);
			for (int i = 0; i < n; ++i)
				_str[i] = s;
			_str[n] = '\0';
		}
		string(const string& p)
			:_str(p._str)
			, _size(p._size)
			, _capacity(p._size)  //按理来说这里给出的空间的大小应该是p._capacity但是害怕p中有很大的容量，但是p中的有效元素却只有几个的情况下，所以直接按照size+1的大小来赋值，等到容量不够再扩容
		{
			_str = new char[p._size + 1];
			strcpy(_str, p._str);
		}
		string& operator= (const string& p)
		{
			if (this != &p)
			{
				delete[] _str;
				_str = new char[strlen(p._str) + 1];
				strcpy(_str, p._str);
				_size = strlen(p._str);
				_capacity = strlen(p._str);
			}
			return *this;
		}
		char& operator[](int x)const
		{
			assert(x < _size);
			return _str[x];
		}
		char& operator[](int x)
		{
			assert(x < _size);
			return _str[x];
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		/////////////////////////////////
		int size()const
		{
			return _size;
		}
		int capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return (_size == 0);
		}
		//////////////////////////////
		void resize(int newsize, char c)
		{
			int oldsize = _size;
			if (oldsize < newsize)  //如果之前空间的有效长度小于你现在要扩展到的有效长度，那么就先看是否需要扩容
			{
				if (_capacity < newsize)  //如果需要扩容
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - oldsize);  //扩完容再填充
			}
			_size = newsize;   //最后无论哪种情况都会走到下面
			_str[_size] = '\0';
		}
		void reserve(int size)
		{
			if (_capacity < size)
			{
				char* temp = new char[size + 1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = size;
			}
		}
		/////////////////////////////////
		void push_back(char ch)
		{
			if (_capacity == _size)
			{
				tow_capacity();
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(char* ch)
		{
			while (((size_t)_size + strlen(ch)) > (size_t)_capacity)   //这里我转size_t纯属是为了消除警告：无符号与有符号不匹配
			{
				tow_capacity();
			}
			_str = strcat(_str, ch);
			_size = _size + strlen(ch);
			return *this;
		}
		/////////////////////////////
		int find(char c)
		{
			for (int i = 0; i < _size; ++i)
			{
				if (c == _str[i])
					return i;
			}
			return npos;
		}
		int find(char* c)
		{
			int flag = 0;
			int i;
			for (i = 0; i < _size; ++i)
			{
				if (c[0] == _str[i])
				{
					for (int j = i; j < strlen(c)&&j<_size; ++j)
					{
						if (c[j] != _str[j])
						{
							flag = 1;
							break;
						}
					}
					if (flag != 1)
						return i;
				}
				flag = 0;
			}
			return npos;
		}
		int rfind(char c)
		{
			for (int i = _size - 1; i >= 0; --i)
			{
				if (c == _str[i])
					return i;
			}
			return npos;
		}
		int rfind(char* c)
		{
			int flag = 0;
			int i;
			for (i = _size - 1; i >= 0; --i)
			{
				if (c[0] == _str[i])
				{
					for (int j = i; j < strlen(c) && j<_size; ++j)
					{
						if (c[j] != _str[j])
						{
							flag = 1;
							break;
						}
					}
					if (flag != 1)
						return i;
				}
				flag = 0;
			}
			return npos;
		}
		string(char* begin,char* end)
		{
			_size = end - begin;
			_capacity = _size;
			_str = new char[_size + 1];
			strncpy(_str, begin, _size);
		}
		string substr(int pos = 0,int end = npos)   //为了写这种方法还要专门给出一种构造函数，为的就是临时对象在离开作用域时候就被销毁
		{
			if (end == npos)
				end = _size;
			string strtemp(_str + pos, _str + pos + (end - pos+ 1));  //截取的区间长度，+1的原因是你举个例子试试就知道了
			return strtemp;
		}
		const char* c_str()const
		{
			return _str;
		}
		/////////////////////////
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
	private:
		void tow_capacity()    //检测是否需要扩容
		{
			reserve(_capacity * 2);
		}
	private:
		char* _str;
		int _size;
		int _capacity;
		static int npos;
	};
	int string::npos = -1;
	ostream& operator<<(ostream& _cout, const string& p)
	{
		for (int i = 0; i < p._size; ++i)
		{
			_cout << p[i];
		}
		return _cout;
	}
	void test()
	{
		string s1("123456");
		string s2(s1);
		string s3;
		s3 = s2;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s3 << endl;
		cout << s2.capacity() << endl;
		s2.reserve(10);
		cout << s2.capacity() << endl;
		s2.resize(15, '!');
		cout << s2 << endl;
		s2.push_back('w');
		cout << s2 << endl;
		s2 += 'o';
		cout << s2 << endl;
		s2 += "rld";
		cout << s2 << endl;
		s2 += "大河向东流呀！天上的星星参北斗呀！说走咋就走呀，你有我有全都有呀！";
		cout << s2 << endl;
		cout << s2.find('o') << endl;
		cout << s2.rfind('o') << endl;
		cout << s2.find("world") << endl;
		cout << s2.rfind("world") << endl;
		cout << s2.find("hello") << endl;
		cout << s2.rfind("hello") << endl;
		cout << s2.substr(15, 19) << endl;
	}
}
//using namespace N1;
void sort_1(int *a,int length)
{
	for (int i = 1; i < length; ++i)
	{
		for (int j = i-1; j > 0 && a[j]>a[j - 1]; --j)
			swap(a[j], a[j - 1]);
	}
}
#endif
int main()
{
	//vector<int> v;
	//cout << v[0] << endl;
	//string s;
	//cout << s[0] << endl;
	//test();
	vector<int> v{ 1, 2, 3 };
	v.erase(v.end() - 1);
	find(v.begin(), v.end(), 2);
	vector<vector<int>> vv;  //目前的二位数组是空的，没有容量
	vv.resize(10);  //定义十行的二维数组，但是每行还是空
	for (int i = 0; i < 10; ++i)
	{
		vv[i].resize(10, 6); //用10个6初始化，每行数组
	}
	return 0;
}