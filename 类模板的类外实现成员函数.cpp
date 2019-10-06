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
	person<string, int>p1("狗贼", 18);
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
	friend void func(person<T1, T2>&p)//全局函数做友元
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
	person<string, int>p("唐僧",88);
	func(p);//虽然没在全局声明但是默认func是全局函数做友元
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
	array(int capacity)//有参构造函数    实现array<int>p(10);
	{
		this->capacity = capacity;
		this->size = 0;
		this->myarray = new T[this->capacity];
	}
	array(const array &p)   //拷贝构造函数
	{
		this->capacity = p.capacity;
		this->size = p.size;
		this->myarray = new T[p.capacity];
		for (int i = 0; i < this->size; ++i)
		{
			this->myarray[i] = p[i];     //这里不必写p.myarray[i],因为我们写了[]运算符的重载，目的就是为了让代码更简明
		}
	}
	array& operator=(const array &p)    //=号运算符的重载
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
			this->myarray[i] = p[i];     //这里不必写p.myarray[i],因为我们写了[]运算符的重载，目的就是为了让代码更简明
		}
		return *this
	}
	T operator[](int num)
	{
		return this->myarray[num];
	}

	void push(int val)    //尾插
 	{
		this->myarray[this->size] = val;
		size++;
	}
	int getsize()          //获取有效长度
	{
		return this->size;
	}
	int getcapacity()      //获取容量
	{
		return this->capacity;
	}
	~array()           //析构函数
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


void printfs(array<int>& p)    //打印数组的函数
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
	for (int i = 0; i < p1.getcapacity(); ++i)     //进行插入数据
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









