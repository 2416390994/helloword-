//#include<iostream>
//using namespace std;
//class string1
//{
//public:
//	static  int a ;
//
//};
//int string1:: a = 10;
//int main()
//{
//	return 0;
//}
#include<iostream>
using namespace std;
template <typename t>
struct father
{
	virtual void push(const t& ) = 0;
	virtual void pop() = 0;
	virtual const t & begin() = 0;
	virtual const t & end() = 0;
	virtual size_t size() = 0;
};
template <class t>
class child:public father<t>
{
public:
	static const int _cap = 100;
	child()
	{
		_size = 0;
		capacity = _cap;
		buf = 0;
		re_capacity(capacity);
	}
	~child()
	{
		free(buf);
	}
	void push(const t& s)
	{
		if (_size >= capacity)
		{
			re_capacity(capacity += _cap);
		}
		buf[_size ++] = s;
	}
	void pop()
	{
		if (_size != 0)
			_size--;
	}
	const t & begin()
	{
		if (_size)
			return buf[0];
	}
	const t & end()
	{
		if (_size)
			return buf[_size - 1];
	}
	size_t size()
	{
		return _size;
	}
	void re_capacity(size_t s)
	{
		if (buf != nullptr)
			buf = (t *)realloc(buf,sizeof(t)* s);
		else
			buf = (t *)malloc(sizeof(t)* s);
	}
	t& operator [](size_t num)
	{
		if (num >=0||num<_size)
		{
			return buf[num];
		}
	}
private:
	size_t _size;
	size_t capacity;
	t *buf;
};
int main()
{
	child<int> v;
	v.push(10);
	v.push(20);
	v.push(5);
	v.push(0);
	cout << v.begin() << endl;
	cout << v.end() << endl;
	v.pop();
	cout << v[0] << endl;
	cout << v.size() << endl;
	return 0;
}