//#include<iostream>
//using namespace std;
//int main()
//{
//	char a = 'c';
//	double b = static_cast<double>(a);
//	cout << b << endl;
//	return 0;
//}
//������̬��������һ�������ຯ������ͬ���麯����
//�����ָ��ָ������Ķ���
#if 0
#include<iostream>
using namespace std;
class father
{
public:
	virtual void func(){}         //�麯��
};
class child : public father
{
public:
	void func(){}
};
void test()
{
	father *p = new child;          //�����ָ��ָ������Ķ���
	child *b = dynamic_cast<child*>(p);   //�ɸ���תΪ�����ǲ���ȫ�ģ��������﷢���˶�̬�����оͿ���ʹ�ö�̬������ת��
}
void test2()
{
	int* a =NULL;
	const int* b = NULL;
	//ȥ��const
	int* c = const_cast<int*>(b);
	//����const
	const int* d = const_cast<const int*>(a);
	int e;
	int& f = e;
	const int& h = e;
	//����const
	const int& g = const_cast<const int&>(f);
	//ȥ��const
	int& L = const_cast<int&>(h);

}

int main()
{
	test2();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
void func(int a,int b)
{
	if (b == 0)
	{
		throw - 1;//�׳��쳣
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try
	{
		func(a, b);
	}
	catch (int)  //����int�쳣
	{
		cout << "�쳣�Ѿ�������\n";
	}
	catch (...)    //�������������쳣
	{
		cout << "�����쳣������\n";
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
void func(int a, int b)
{
	if (b == 0)
	{
		throw - 1;//�׳��쳣
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try
	{
		func(a, b);
	}
	catch (int)  //����int�쳣
	{
		throw;
		cout << "test���������쳣\n";
	}
}
//main��������test()������test��������func()����������ÿһ�������һ����쳣���� ��
//Ȼ��main������ʼִ�У�����test������Ȼ��test��������func������function�����׳��쳣���ȷ��ز��ұ�test����������
//��ʱ��main����������쳣����û�з�������
int main()
{
	try
	{
		test();
	}
	catch (int)
	{
		cout << "main��������int�쳣\n";
	}
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class person{};
void func(int a,int b)
{
	if (b == 0)
		throw person();//����������ʾ��������
}
void test()
{
	int a = 10;
	int b = 0;
	try      //����ִ���������
	{
		func(a,b);
	}
	catch (person)
	{
		cout << "�Զ��������쳣\n";
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father{};  //�����׳��쳣���Զ�������
class person     //�����鿴ջ��������
{
public:
	person()
	{
		cout << "���캯��\n";
	}
	~person()
	{
		cout << "��������\n";
	}
};
void func(int a, int b)
{
	if (b == 0)
	{
		person p1;
		person p2;
		throw father();//����������ʾ�������󣬳��ִ�����׳�father���Ͷ���
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try      //����ִ���������
	{
		func(a, b);
	}
	catch (father)        ///����father���͵��쳣
	{
		cout << "�Զ��������쳣\n";
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class father    //����
{
public:
	virtual void FUNC()
	{}
}; 
class child1 :public father
{
public:
	virtual void FUNC()
	{
		cout << "Ҽ���쳣\n";
	}
};
class child2 :public father
{
public:
	virtual void FUNC()
	{
		cout << "�����쳣\n";
	}
};
void func(int a, int b)
{
	if (b == 0)
	{
		
		throw child1();          //�����׳������������쳣
	}
}
void test()
{
	int a = 10;
	int b = 0;
	try                              //����ִ���������
	{
		func(a, b);
	}
	catch (father& e)          //���ﲶ����Ǹ���Ķ����ø����ָ���������ָ������Ķ��� ���Ѿ������˶�̬
	{
		e.FUNC();             //��Ȼ�Ѿ������˶�̬������󶨣�����ʱ�󶨣���ô�ͻ������ͬ��������FUNC��
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<stdexcept>           //����ͷ�ļ�
using namespace std;
class person
{
public:
	person(string a,int b)
	{
		this->ages = b;
		this->name = a;
		if (b > 200 || b < 0)
		{
			throw out_of_range("����Խ����\n");
		}
	}
	string name;
	int ages;
};

void test()
{
	try      
	{
		person p("����ʦ", 1000);
	}
	catch (out_of_range& e)          //�����Ƽ������ã�out_of_range��ʵҲ��һ��������
	{ 
		cout <<e.what();             //ÿ�������඼����һ��what()
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
//_EXCEPTION_INLINE virtual __CLR_OR_THIS_CALL ~exception() _NOEXCEPT;
//_EXCEPTION_INLINE virtual const char * __CLR_OR_THIS_CALL what() const;
//c++�����е�ϵͳ�Զ����쳣���Ǽ̳�exception�࣬�������кܶຯ��������Ҫ������дֻ��Ҫ���õ��ĺ���������д�Ϳ�����
class perro:public exception          //���F12���Բ鿴���࣬���ڶ��������������������д����Ϊ����̳е����캯�������Լ�д
{
public:
	perro(string error)
	{
		this->error = error;
	}
	virtual ~perro()         //��ΪҲû���ڶ��ϴ������������������Ҳ�Ͳ��Լ�ʵ����
	{

	}
	virtual const char * what() const
	{
		return this->error.c_str();     //��Ϊ�����what��������ֵ��char* ����������Ҫ��string���ͽ���ǿת
	}
	string error;
};
class person
{
public:
	person(string name, int ages)
	{
		this->name = name;
		if (ages<0 || ages>200)
		{
			throw perro("����̫����");
		}
		else
			this->ages = ages;
	}
	string name;
	int ages;
};
void test()
{
	try
	{
		person p("��˽�", 300);
	}
	catch (perro & p1)
	{
		cout << p1.what() << endl;
	}
}
int main()
{
	test();
	return 0;
}
#endif






