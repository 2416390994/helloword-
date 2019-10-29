#include<iostream>
#include<assert.h>
using namespace std;
namespace N1
{
	template<class T>
	class vector
	{
	public:
		//vector迭代器实际上就是原生态的指针
		typedef T*  iterator;
	public:
		vector()
			:_begin(nullptr)
			, _end ( nullptr)
			,_endofstorage(nullptr)
		{}
		vector(int n, const T& data)
			:_begin(new T[n])
		{
			for (int i = 0; i < n; ++i)
			{
				_begin[i] = data;
			}
			_end = _begin + n;
			_endofstorage = _end;
		}
		template<class Iterator>  //任意类型区间
		vector(Iterator first, Iterator end)
		{
			int length = 0;
			T* temp = first;
			auto it = first;
			while (it != end)
			{
				++it;
				++length;
			}
			_begin = new T[length];
			for (int i = 0; i < length; ++i)
			{
				_begin[i] = *temp++;
			}
			_end = _begin + length;
			_endofstorage = _end;
		}
		vector(vector<T>& data)
		{
			int si = data.size();
			_begin = new T[si];
			for (int i = 0; i < si; ++i)
			{
				_begin[i] = data[i];
			}
			_end = _begin + si;
			_endofstorage = _end;
		}
		vector<T>& operator=(vector<T>& data)  //赋值运算符里面我给出了两步操作
		{
			if (_begin)
			{
				delete[] _begin;
				_begin = nullptr;
				_end = nullptr;
				_endofstorage = nullptr;
			}
			int si = data.size();
			_begin = new T[si];
			for (int i = 0; i < si; ++i)
			{
				_begin[i] = data[i];
			}
			_end = _begin + si;
			_endofstorage = _end;
			return *this;
		}
		~vector()
		{
			if (_begin)
			{
				delete[] _begin;
				_begin = nullptr;
				_end = nullptr;
				_endofstorage = nullptr;
			}
		}
		iterator begin()
		{
			return _begin;
		}
		iterator end()
		{
			return _end;
		}
		void resize(int newsize, const T& data = T())
		{
			int oldsize = size();
			if (newsize > oldsize)
			{				
				if (capacity() < newsize)
					reserve(newsize);
				for (int i = oldsize; i < oldsize + (newsize - oldsize); ++i)
				{
					_begin[i] = data;
				}	
			}
			_end = _begin + newsize;
		}
		void reserve(int newcapacity)
		{
			int n = size();
			int oldcapacity = capacity();
			if(newcapacity > oldcapacity)
			{
				T* temp = new T[newcapacity];
				if (_begin)
				{
					for (int i = 0; i < n; ++i)
					{
						temp[i] = _begin[i];
					}
					delete[] _begin;
				}
				_begin = temp;
				//_end = _begin + size();  这样写有坑，必须要在之前的位置将size()保存起来，因为扩容结束，_begin只向新空间，_end依然在旧空间，相减无意义，但是+在_end上无意义，运行会出错
				_end = _begin + n;
				_endofstorage = _begin + newcapacity;
			}
		}
		const T& operator[](int n)const
		{
			assert(n < size());
			return _begin[n];
		}
		T& operator[](int n)
		{
			assert(n < size());
			return _begin[n];
		}
		T& front()
		{
			return *_begin;
		}
		const T& front() const
		{
			return *_begin;
		}
		T& back()
		{
			return *(_end - 1);
		}
		const T& back() const
		{
			return *(_end - 1);
		}
		void push_back(const T& data)
		{
			check();
			*_end++ = data;
		}
		void pop_back()
		{
			_end--;
		}
		iterator insert(iterator pos,const T& data)  //返回值意思是刚插入元素的位置
		{
			check();  //检查是否需要扩容
			auto it = _end;
			while (it >= pos)
			{
				*(it) = *(it - 1);
				it--;
			}
			*pos = date;
			_end++;  //标记尾部的标记后移
			return pos;
		}
		iterator erase(iterator pos)
		{
			auto it = pos;
			while (it != end())
			{
				*it = *(it + 1);
				it++;
			}
			--_end;  ////标记尾部的标记前移
			return pos;
		}
		int size()
		{
			return _end - _begin;
		}
		int capacity()
		{
			return _endofstorage - _begin;
		}
		bool empty()
		{
			return _begin == _end;
		}
		void clear()
		{
			_end = _begin;
		}
	private:
		T* _begin;  //标记起始位置
		T* _end;  //标记有效元素末尾
		T* _endofstorage;  //标记空间末尾
		void check()
		{
			if (_end == _endofstorage)
			{
				reserve(capacity() * 2 + 1);
			}
		}
	};	
	void test()
	{
		vector<int> v1;
		vector<int> v2(10,5);
		int a[] = { 1, 2, 3, 4, 5 };
		vector<int> v3(a, a + (sizeof(a) / sizeof(a[0])));
		vector<int> v4(v3);
		vector<int> v5;
		v5 = v4;
		cout << v1.size() << endl; 
		cout << v1.capacity() << endl;
		cout << v2.size() << endl;
		cout << v2.capacity() << endl;
		cout << v3.size() << endl;
		cout << v3.capacity() << endl;
		cout << v4.size() << endl;
		cout << v4.capacity() << endl;
		cout << v5.size() << endl;
		cout << v5.capacity() << endl;
		auto it = v3.begin();
		while (it != v3.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		cout << v3.front() << endl;
		cout << v3.back() << endl;
	}
	void test1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		auto it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		auto it2 = v1.begin();
		while (it2 != v1.end())
		{
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;
	}
}
using namespace N1;
int main()
{
	//test();
	//test1();
	return 0;
}