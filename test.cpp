#if 0
#include<stdio.h>
int main()
{
	int a = 10;
	const int b = a;
	int *p = (int *)&b;
	*p = 20;
	printf("%d,%d", *p, b);
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	const int b = 10;
	int *a = (int *)&b;
	return 0;
}
#endif
#if 0
#include<stdio.h>
int main()
{
	const int b = 10;
	int * p = (int *)&b;
	*p = 20;
	printf("%d\n", b);
	int a[10] = { b };
	printf("%d", a[0]);

	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
int main()
{
	//int &a = 10;
	const int &a = 10;
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class person
{
public:
	inline int max(int a, int b);
private:
	int a;
};
inline int person::max(int a, int b)
{
		int ret = ++a + b;
		return ret;
}
int main()
{
	person p1;
	int ret = p1.max(10, 20);
	printf("%d\n", ret);
	return 0;
}
#endif 
#if 0
#include<iostream>
using namespace std;
class person
{
public:

	person()
	{
		this->a = 10;
		cout << "���캯��\n";
	}
	person(int a)
	{
		this->a = a;
		cout << "�вι��캯��\n";
	}
	person(const person &p)
	{
		this->a = p.a;
		cout << "�������캯��\n";
	}
	void aab()
	{
		cout << this->a << endl;
	}
private:
	int a;
};
void test()
{
	person p1 = person (100);
	person p2(100);
	person p3(p2);
	person p4 = p2;
	p3.aab();
	p2.aab();
	p1.aab();
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
class phone
{
public:
	phone()
	{
		cout << "phone����\n";
	}
	~phone()
	{
		cout << "phone����\n";
	}
};
class game
{
public:
	game()
	{
		cout << "game����\n";
	}
	~game()
	{
		cout << "game����\n";
	}

};
class person
{
public:
	person()
	{
		cout << "person����\n";
	}
	~person()
	{
		cout << "person����\n";
	}

	string a;
	phone shouji;
	game youxi;
};
void test()
{
	person p;

}

int main()
{
	test();
	return 0;
}
#endif
#include<iostream>
using namespace std;
class person
{
public:
	person()
	{
		this->a = 10;
		cout << "Ĭ�Ϲ��캯��\n";
	}
	person(const person &p)
	{
		this->a = p.a;
		cout << "�������캯��\n";
	}
	~person()
	{
		cout << "��������\n";
	}
	int a;
};
void test()
{
	/*person p1;
	person p2 = p1;
	person* p3 = (person*)malloc(sizeof(person));
	p3->a = 20;
	person *p4 = new person;
	free(p3);
	delete p4;*/
	//char *p = new char[10];

}
int main()
{
	test();
	return 0;
}








