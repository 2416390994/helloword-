#include<iostream>
using namespace std;
//bool Test1()
//{
//	//成功返回true,失败返回false
//	return false;
//}
//void Test2()
//{
//	//....
//
//	throw 1; //抛出异常
//}
//void TestFunc()
//{
//	int *p = new int[10];
//	FILE* fd = fopen("aaa.txt", "rb");
//	if (fd == nullptr)
//	{
//		delete[] p;
//		return;
//	}
//	if (!Test1())
//	{
//		delete[] p;
//		fclose(fd);
//		return;
//	}
//	try
//	{
//		Test2();
//	}
//	catch (...)
//	{
//		delete[] p;
//		fclose(fd);
//	}
//	//...
//	
//	//假如上面执行顺利，来到代码的末端
//	delete[] p;
//	fclose(fd);
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}
//RAII --- 资源获取及初始化
//在构造函数中放资源
//在析构函数中释放资源

//智能指针的简单模拟实现
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr = nullptr)
//	:_ptr(ptr)
//	{
//		cout << "SmartPtr" << endl;
//	}
//	~SmartPtr()
//	{
//		cout << "~SmartPtr" << endl;
//		if (_ptr)
//		{
//			delete _ptr;
//			_ptr = nullptr;  //加不加这句都可以，因为析构结束，对象已经销毁，成员变量也就不存在了
//		}
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//struct A
//{
//	int a = 100;
//	int b = 200;
//	int c = 300;
//};
//int main()
//{
//	SmartPtr<int> sp(new int);
//	*sp = 10;
//	cout << *sp << endl;
//	SmartPtr<A> sp1(new A);
//	cout << sp1->a << endl;;
//	return 0;
//}
namespace vs
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{
			cout << "构造" << endl;
		}
		~auto_ptr()
		{
			cout << "析构" << endl;
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		auto_ptr(auto_ptr<T>& ap)  //这也就是auto_ptr解决浅拷贝的方式也就是资源的转移
		{
			_ptr = new int(*(ap._ptr));
		}
		auto_ptr<T>& operator=(auto_ptr<T>& ps)
		{
			if (this != &ps)
			{
				if (!this)   //如果当前对象已经管理资源了，就要先把当前对象的资源先释放
					delete _ptr;
				_ptr = ps._ptr;
				ps._ptr = nullptr;
			}
			return *this;
		}
		int get()
		{
		cout<<
		}
	private:
		T* _ptr;
	};
}
void TestAuto_ptr()
{
	vs::auto_ptr<int> ps1(new int(10));
	
	vs::auto_ptr<int> ps2(ps1);  //因为ps2是最后创建的，auto_ptr就会猜测之前的ps1你可能不用了，然后在智能指针内部，让指针指向空
	
	//*ps1 = 10;   指针指向空之后，这个语句报错，此时ps1已经是个空对象
	//vs::auto_ptr<int> ps3;
	//ps3 = ps2;
}
int main()
{
	TestAuto_ptr();
	return 0;
}