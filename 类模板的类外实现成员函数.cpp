#if 0
#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class person
{
public:
	person(T1 name, T2 ages);
	void func();
	T1 name;
	T2 ages;
};
template<class T1,class T2>
person<T1,T2>::person(T1 name, T2 ages)
{
	this->name = name;
	this->ages = ages;
}
template<class T1,class T2>
void person<T1,T2>::func()
{
	cout << this->name << endl << this->ages << endl;
}
void test()
{
	person<string, int>p1("����", 18);
	p1.func();
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
template<class T1,class T2>
class person
{
	friend void func(person<T1, T2>&p)//ȫ�ֺ�������Ԫ
	{
		cout << p.name << endl << p.ages << endl;
	}
public:
	person(T1 name, T2 ages)
	{
		this->name = name;
		this->ages = ages;
	}
private:
	T1 name;
	T2 ages;
};
void test()
{
	person<string, int>p("��ɮ",88);
	func(p);//��Ȼû��ȫ����������Ĭ��func��ȫ�ֺ�������Ԫ
}

int main()
{
	test();
	return 0;
}
#endif
#include<iostream>
using namespace std;
template<class T>
class array
{
public:
	array(int capacity)//�вι��캯��    ʵ��array<int>p(10);
	{
		this->capacity = capacity;
		this->size = 0;
		this->myarray = new T[this->capacity];
	}
	array(const array &p)   //�������캯��
	{
		this->capacity = p.capacity;
		this->size = p.size;
		this->myarray = new T[p.capacity];
		for (int i = 0; i < this->size; ++i)
		{
			this->myarray[i] = p[i];     //���ﲻ��дp.myarray[i],��Ϊ����д��[]����������أ�Ŀ�ľ���Ϊ���ô��������
		}
	}
	array& operator=(const array &p)    //=�������������
	{
		if (this->capacity != NULL)
		{
			delete[] this->myarray;
			this->myarray = NULL;
			this->size = NULL;
			this->capacity = NULL;
		}
		this->capacity = p.capacity;
		this->size = p.size;
		this->myarray = new T[p.capacity];
		for (int i = 0; i < this->size; ++i)
		{
			this->myarray[i] = p[i];     //���ﲻ��дp.myarray[i],��Ϊ����д��[]����������أ�Ŀ�ľ���Ϊ���ô��������
		}
		return *this
	}
	T operator[](int num)
	{
		return this->myarray[num];
	}

	void push(int val)    //β��
 	{
		this->myarray[this->size] = val;
		size++;
	}
	int getsize()          //��ȡ��Ч����
	{
		return this->size;
	}
	int getcapacity()      //��ȡ����
	{
		return this->capacity;
	}
	~array()           //��������
	{
		if (this->capacity != NULL)
		{
			delete[] this->myarray;
			this->size = NULL;
			this->myarray = NULL;
			this->capacity = NULL;
		}
	}
private:
	T *myarray;
	int capacity;
	int size;
};


void printfs(array<int>& p)    //��ӡ����ĺ���
{
	for (int i = 0; i < p.getsize(); ++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

void test()
{
	array<int>p1(10);
	int j = 10;
	for (int i = 0; i < p1.getcapacity(); ++i)     //���в�������
	{	
		p1.push(j);
	}
	printfs(p1);
}
int main()
{
	test();
	return 0;
}









