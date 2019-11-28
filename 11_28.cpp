//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//C++11：auto_ptr---->保留：资源转移实现
//就是为了防止之前其他人写的代码中使用了auto_ptr编译不能通过
//C++11提供了更靠谱的智能指针
//unique_ptr 唯一的指针，
//浅拷贝发生的原因就是拷贝构造函数和赋值运算符引起的，所以unique_ptr就是不提供这两个函数，就没法进行浅拷贝
//template<class T>
//class DFDef
//{
//public:
//	void operator()(T*& p)
//	{
//		if (p)
//		{
//			delete p;
//			p = nullptr;
//		}
//	}
//};
//template<class T>
//class Free
//{
//public:
//	void operator()(T* &p)
//	{
//		if (p)
//		{
//			free(p);
//			p = nullptr;
//		}
//	}
//};
//class FClose
//{
//public:
//	void operator()(FILE*& p)
//	{
//		if (p)
//		{
//			fclose(p);
//		}
//	}
//};
//namespace vs
//{
//	template<class T, class DF = DFDef<T>>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		~unique_ptr()
//		{
//			if (_ptr)
//			{
//				//delete _ptr;  //释放资源的方式固定死了，不能处理任意类型的资源，只能处理new类型的空间
//				//DF()(_ptr);
//				//上面这句代码 分成两句也就是
//				DF df;
//				df(_ptr);
//				_ptr = nullptr;
//			}
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		//解决浅拷贝:禁止调用拷贝构造函数，禁止调用拷贝构造函数
//		unique_ptr(const unique_ptr<T>&) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
//	private:
//		T* _ptr;
//	};
//}
//void TestUniquePtr()
//{
//	vs::unique_ptr<int, DFDef<int>> up1(new int);
//	vs::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
//	vs::unique_ptr<FILE, FClose> up3(fopen("1.txt","w"));
//
//}
//int main()
//{
//	TestUniquePtr();
//	return 0;
//}
//template<class T>
//class DFDef
//{
//public:
//	void operator()(T*& p)
//	{
//		if (p)
//		{
//			delete p;
//			p = nullptr;
//		}
//	}
//};
//
//template<class T>
//class Free
//{
//public:
//	void operator()(T*& p)
//	{
//		if (p)
//		{
//			free(p);
//			p = nullptr;
//		}
//	}
//};
//
//
//class FClose
//{
//public:
//	void operator()(FILE*& p)
//	{
//		if (p)
//		{
//			fclose(p);
//			p = nullptr;
//		}
//	}
//};
//
//namespace bite
//{
//	template<class T, class DF = DFDef<T>>
//	class unique_ptr
//	{
//	public:
//		// RAII
//		unique_ptr(T* ptr = nullptr)
//			: _ptr(ptr)
//		{}
//
//		~unique_ptr()
//		{
//			if (_ptr)
//			{
//				//delete _ptr; // 释放资源的方式固定死了，只能管理new的资源，不能处理任意类型的资源
//				//DF()(_ptr);
//				DF df;
//				df(_ptr);
//				_ptr = nullptr;
//			}
//		}
//
//		// 具有指针类似行为
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		unique_ptr(const unique_ptr<T>&) = delete;  // 1. 释放new的空间  2.默认成员函数 = delete ： 告诉编译器，删除该默认成员函数
//		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
//
//	private:
//		T* _ptr;
//	};
//}
//
//void TestUniquePtr()
//{
//	bite::unique_ptr<int> up1(new int);
//	bite::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
//	bite::unique_ptr<FILE, FClose> up3(fopen("1.txt", "w"));
//}
//
//int main()
//{
//	TestUniquePtr();
//	return 0;
//}
#if 0
#include<iostream>
using namespace std;
class WC
{
public:
	void GoToManRoom()const
	{
		cout << "go to left" << endl;
	}

	void GoToWoManRoom()const
	{
		cout << "go to right" << endl;
	}
};
class person
{
public:
	virtual void GoToWC(const WC& wc) = 0;  //纯虚函数
	string _name;
	int _age;
};
class man : public person
{
public:
	void GoToWC(const WC& wc)
	{
		wc.GoToManRoom();  //注意const成员只能调用const类型的成员函数
	}
};
class woman : public person
{
public:
	void GoToWC(const WC& wc)
	{
		wc.GoToWoManRoom();
	}
};
void test()
{
	WC wc;
	woman c1;
	c1.GoToWC(wc);
	man c2;
	c2.GoToWC(wc);
}
class 人妖 : public person
{
public:
	/*void GoToWC(const WC& wc)
	{
		wc.GoToWoManRoom();
	}*/
};
//void test2()
//{
//	person p;  //抽象类无法实例化对象
//	人妖 w;  //派生类不重写基类中已经被声明为纯虚函数的函数的话，也是无法实例化对象的
//	person* p1;  //但是可以创建指针
//}
class A
{
	static int a;
};
int A::a = 10;
int main()
{
	cout<<sizeof(A) << endl;
	return 0;
}
#endif
//#include<iostream>
//using namespace std;
////class Base
////{
////public:
////	virtual void A()
////	{}
////	virtual void B()
////	{}
////	int a;
////};
////int main()
////{
////	Base b;
////	b.a = 10;
////	return 0;
////}
//class Base
//{
//public:
//	virtual void A()
//	{}
//	virtual void B()
//	{}
//	int _a;
//};
//class son : public Base
//{
//public:
//	void A()
//	{
//		
//	}
//	void B()
//	{
//	}
//	int _b;
//	//int c;
//};
//int main()
//{
//	Base a;
//	a._a = 1;
//	son b;
//	b._b = 1;
//	cout << sizeof(son) << endl;
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		reverse(str.begin(), str.end());
//		cout << str << endl;
//	}
//
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//	{
//		if (str1.size() < str2.size())
//			swap(str1, str2);
//		int length1 = str1.size();
//		int length2 = str2.size();
//		if (length1 == 0 || length2 == 0)
//		{
//			cout << 0 << endl;
//			return 0;
//		}
//		int maxsize = 0;
//		int k = 0;
//		for (int i = 0; i < length1; ++i)
//		{
//			for (int j = 0; j < length2;++j)
//			{
//				int flag = 0;
//				k = i;
//				int count = 0;
//				while (k < length1 && j < length2 &&str1[k] == str2[j] || str1[k] == str2[j] - 32 || str1[k] == str2[j] + 32)
//				{
//					++k;
//					++j;
//					flag = 1;
//					++count;
//				}
//				k = i;
//				if (count > maxsize)
//				{
//					maxsize = count;
//				}
//				if (flag == 1)
//					--j;
//			}
//		}
//		cout << maxsize << endl;
//		maxsize = 0;
//	}
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int getCommonStrLength(char* pFirstStr, char* pSecondStr)
//{
//	int count = 0;
//	int maxsize = 0;
//	for (int i = 0; pFirstStr[i] != '\0'; ++i)
//	{
//		int k = i;
//		for (int j = 0; pSecondStr[j] != '\0'; ++j)
//		{
//			while (pFirstStr[k] != '\0' && pSecondStr[j] != '\0' &&pFirstStr[k] == pSecondStr[j] || pFirstStr[k] == pSecondStr[j] - 32 || pFirstStr[k] == pSecondStr[j] + 32)
//			{
//				k++;
//				j++;
//				count++;
//			}
//			k = i;
//
//		}
//		if (count > maxsize)
//		{
//			maxsize = count;
//		}
//		count = 0;
//	}
//	return maxsize;
//}
//int main()
//{
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//	{
//		if (str1.size() == 0 || str2.size() == 0) return 0;
//		if (str1.size() < str2.size())
//			swap(str1, str2);
//		int ret = getCommonStrLength((char*)str1.c_str(), (char*)str2.c_str());
//		cout << ret << endl;
//	}
//	return 0;
//}
//#include <string>  
//#include <iostream>  
//#include <vector>  
//#include <cctype>  
//#include<algorithm>
//using namespace std;
//int getCommonStrLength(string str1, string str2){
//
//	int len1 = str1.size();
//	int len2 = str2.size();
//
//	if (len1 == 0 || len2 == 0) return 0;
//
//	vector<vector<int> > vvi(len1, vector<int>(len2, 0));
//	int maxLen = 0;
//	for (int i = 0; i < len1; i++) {
//		if (tolower(str1[i]) != tolower(str2[0])){
//			vvi[i][0] = 0;  //初始化行 不匹配
//		}
//		else{
//			vvi[i][0] = 1;   //匹配
//			maxLen = 1;
//		}
//	}
//
//	for (int i = 0; i < len2; i++){
//		if (tolower(str2[i]) != tolower(str1[0])){
//			vvi[0][i] = 0;  //初始化列
//		}
//		else{
//			vvi[0][i] = 1;
//			maxLen = 1;
//		}
//	}
//	for (int i = 1; i < len1; i++){
//		for (int j = 1; j < len2; j++){
//			if (tolower(str1[i]) != tolower(str2[j])){
//				vvi[i][j] = 0;  //不匹配置0
//			}
//			else{
//				vvi[i][j] = vvi[i - 1][j - 1] + 1;  //匹配加1
//				maxLen = max(maxLen, vvi[i][j]);
//			}
//		}
//	}
//	return maxLen;
//}
//int main(){
//
//	string str1, str2;
//
//	while (cin >> str1 >> str2){
//		cout << getCommonStrLength(str1, str2) << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() < str2.size())
			swap(str1, str2);
		int length1 = str1.size();
		int length2 = str2.size();
		if (length1 == 0 || length2 == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		int maxsize = 0;
		int k = 0;
		for (int i = 0; i < length1; ++i)
		{
			for (int j = 0; j < length2; ++j)
			{
				int flag = 0;
				k = i;
				int count = 0;
				while (k < length1 && j < length2 &&str1[k] == str2[j] || str1[k] == str2[j] - 32 || str1[k] == str2[j] + 32)
				{
					++k;
					++j;
					flag = 1;
					++count;
				}
				k = i;
				if (count > maxsize)
				{
					maxsize = count;
				}
				if (flag == 1)
					--j;
			}
		}
		cout << maxsize << endl;
		maxsize = 0;
	}
	return 0;
}