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
		string(char*  str = "")  //Ĭ�ϵĹ��캯����������ȱʡ����Ϊ���Ƿ�ֹֻ���� ����ʼ��
		{
			if (str == nullptr)  //��ξ����пռ����ⲿ���ݵĲ����ǿյĻ���
				str = "";     //�Ǿ�����ָ��ָ��""���ַ����ٿ��������Ľ������ֻ����"\0"
			_str = new char[strlen(str) + 1];  //���ٿռ�
			strcpy(_str, str);  //����Ԫ��
		}
		string(const string& p)
		{
			_str = new char[p.size() + 1];
			strcpy(_str, p._str);
		}
		string& operator=(const string& p)
		{
			if (this != &p) //ע������Ƚϵ��ǵ�ַ
			{
				delete[] _str;  //�տ�ʼ�һ�����һ���������пղ����������û�б�Ҫ��Ϊ����Ϊ���ж����ڳ�ʼ����ʱ���пռ䣬�����Ǹ�'\0'
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
		string(char*  str = "")  //Ĭ�ϵĹ��캯����������ȱʡ����Ϊ���Ƿ�ֹֻ���� ����ʼ��
		{
			if (str == nullptr)  //��ξ����пռ����ⲿ���ݵĲ����ǿյĻ���
				str = "";     //�Ǿ�����ָ��ָ��""���ַ����ٿ��������Ľ������ֻ����"\0"
			_str = new char[strlen(str) + 1];  //���ٿռ�
			strcpy(_str, str);  //����Ԫ��
		}
		//�����ڴ˴� ����һ��������ǣ�vs2013���������õ�_str��û�г�ʼ��������»����nullptr
		//���Ǳ�ı������ͻ᲻һ������Ϊʲô
		//�������ڵ�_str����ŵ������ֵ����ô����ʱ���󽻻�֮���൱����ʱ����ָ��������ֵ����ô��������ʱ�����ʱ��
		//���緢�ֲ���ָ��գ��������ֵ����ȥ�ͷ���ô����ͱ����ˣ�����Ҫ��ʱ�յĻ����Ͳ���ȥ�ͷţ���û��
		string(const string& p)
			//:_str(nullptr) //�������ƿ�
		{
			string strtemp(p._str);  //ʹ��Ĭ�Ϲ��캯�������쿽�����캯������ߴ��븴���ʣ�����������Ҫע����ǣ�ʹ�õ���p._str��������ֱ��ʹ�ö��󣬷���������޵ݹ�
			swap(_str, strtemp._str); //������ʱ�����͵�ǰ����
		}
		//����һ���Լ����Լ���ֵ�Ŀ����ԱȽ�С������������һ�ָ�ֵ�����������
		//string& operator=(const string& p)
		//{
		//	if (this != &p) 
		//	{
		//		string strtemp(p); //������õ����ǿ������캯��
		//		swap(_str, strtemp._str);
		//	}
		//	return *this;
		//}
		//���¸���������
		string& operator=(string p)  //ֱ���� ���ν׶ξ͵��ÿ������캯���������ʱ����
		{
			//����汾�������ÿ����Լ����Լ���ֵ����Ϊ���������Լ����Լ���ֵ����ֵ֮�����Լ�
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
			:count(new int(1))  //ÿһ���µ���Դ����ͨ�����캯�������ģ����ڹ��캯����λ�ö�����һ��ռ䣬��ռ䱻���������Դ�����ж��󶼿��Է�Χ��ע��ǰ�������й�����һ����Դ�Ķ���
		{
			if (str == nullptr)  
				str = "";     
			_str = new char[strlen(str) + 1]; 
			strcpy(_str, str);
		}
		string(const string& p)  //�����������ֱ������ �����ָ��ȫ��ָ�򣬱��������Դ��ֻ��Ҫʹ��Դ����+1����
			:_str(p._str)
			, count(p.count)
		{
			++(*count);
		}
		string& operator=(const string& p)
		{
			if (this != &p)
			{
				//if (_str && 0 == (*count)--)  //�������
				//{
				//	delete[] _str;
				//	delete count;
				//	count = nullptr;
				//	_str = nullptr;
				//}
				this->~string();  //��ʵ�Ҹо�����ֱ�ӵ��������������������Ӵ��븴����
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
			if ((_str!=nullptr) && (0 == --(*count)))  //��дΪif(_str && 0 == --(*count))
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
		typedef char* iterator;   //������
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
			_capacity = n;  //���������û��+1,Ҳ����˵û��������'\0'����һ�ж���Ϊ����ѭ��string��������ò
			_str = new char(n + 1);
			for (int i = 0; i < n; ++i)
				_str[i] = s;
			_str[n] = '\0';
		}
		string(const string& p)
			:_str(p._str)
			, _size(p._size)
			, _capacity(p._size)  //������˵��������Ŀռ�Ĵ�СӦ����p._capacity���Ǻ���p���кܴ������������p�е���ЧԪ��ȴֻ�м���������£�����ֱ�Ӱ���size+1�Ĵ�С����ֵ���ȵ���������������
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
			if (oldsize < newsize)  //���֮ǰ�ռ����Ч����С��������Ҫ��չ������Ч���ȣ���ô���ȿ��Ƿ���Ҫ����
			{
				if (_capacity < newsize)  //�����Ҫ����
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - oldsize);  //�����������
			}
			_size = newsize;   //�������������������ߵ�����
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
			while (((size_t)_size + strlen(ch)) > (size_t)_capacity)   //������תsize_t������Ϊ���������棺�޷������з��Ų�ƥ��
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
		string substr(int pos = 0,int end = npos)   //Ϊ��д���ַ�����Ҫר�Ÿ���һ�ֹ��캯����Ϊ�ľ�����ʱ�������뿪������ʱ��ͱ�����
		{
			if (end == npos)
				end = _size;
			string strtemp(_str + pos, _str + pos + (end - pos+ 1));  //��ȡ�����䳤�ȣ�+1��ԭ������ٸ��������Ծ�֪����
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
		void tow_capacity()    //����Ƿ���Ҫ����
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
		s2 += "�������ѽ�����ϵ����ǲα���ѽ��˵��զ����ѽ����������ȫ����ѽ��";
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
	vector<vector<int>> vv;  //Ŀǰ�Ķ�λ�����ǿյģ�û������
	vv.resize(10);  //����ʮ�еĶ�ά���飬����ÿ�л��ǿ�
	for (int i = 0; i < 10; ++i)
	{
		vv[i].resize(10, 6); //��10��6��ʼ����ÿ������
	}
	return 0;
}