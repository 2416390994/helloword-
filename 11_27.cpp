#include<iostream>
using namespace std;
//bool Test1()
//{
//	//�ɹ�����true,ʧ�ܷ���false
//	return false;
//}
//void Test2()
//{
//	//....
//
//	throw 1; //�׳��쳣
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
//	//��������ִ��˳�������������ĩ��
//	delete[] p;
//	fclose(fd);
//}
//int main()
//{
//	TestFunc();
//	return 0;
//}
//RAII --- ��Դ��ȡ����ʼ��
//�ڹ��캯���з���Դ
//�������������ͷ���Դ

//����ָ��ļ�ģ��ʵ��
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
//			_ptr = nullptr;  //�Ӳ�����䶼���ԣ���Ϊ���������������Ѿ����٣���Ա����Ҳ�Ͳ�������
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
			cout << "����" << endl;
		}
		~auto_ptr()
		{
			cout << "����" << endl;
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
		auto_ptr(auto_ptr<T>& ap)  //��Ҳ����auto_ptr���ǳ�����ķ�ʽҲ������Դ��ת��
		{
			_ptr = new int(*(ap._ptr));
		}
		auto_ptr<T>& operator=(auto_ptr<T>& ps)
		{
			if (this != &ps)
			{
				if (!this)   //�����ǰ�����Ѿ�������Դ�ˣ���Ҫ�Ȱѵ�ǰ�������Դ���ͷ�
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
	
	vs::auto_ptr<int> ps2(ps1);  //��Ϊps2����󴴽��ģ�auto_ptr�ͻ�²�֮ǰ��ps1����ܲ����ˣ�Ȼ��������ָ���ڲ�����ָ��ָ���
	
	//*ps1 = 10;   ָ��ָ���֮�������䱨����ʱps1�Ѿ��Ǹ��ն���
	//vs::auto_ptr<int> ps3;
	//ps3 = ps2;
}
int main()
{
	TestAuto_ptr();
	return 0;
}