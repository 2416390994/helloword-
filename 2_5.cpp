#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
//void func(vector<int>& vec)
//{
//	int L = 0;
//	int  less = L - 1;
//	int more = vec.size() - 1;
//	while (L < more)
//	{
//		if (vec[L] % 2 == 1)
//		{
//			swap(vec[++less], vec[L++]);
//		}
//		else
//		{
//			swap(vec[more--], vec[L]);
//		}
//	}
//}
//int* func1(vector<int>& vec,int L,int R)
//{
//	int less = L - 1;
//	int more = R;
//	while (L < more)
//	{
//		if (vec[L] < vec[R])
//		{
//			swap(vec[++less], vec[L++]);
//		}
//		else if (vec[L] > vec[R])
//		{
//			swap(vec[--more], vec[L]);
//		}
//		else
//		{
//			L++;
//		}
//	}
//	swap(vec[more], vec[R]);
//	return new int[]{less, more + 1};
//}
//void func2(vector<int>& vec,int L,int R)
//{
//	if (L < R)
//	{
//		srand((unsigned int)time(NULL));
//		swap(vec[R], vec[L + rand() % (R - L) + 1]);
//		int* p = func1(vec, L, R);
//		func2(vec, L, p[0]);
//		func2(vec, p[1], R);
//	}
//}
//void func3(vector<int>& vec)
//{
//	for (int i = 0; i < vec.size() - 1; ++i)
//	{
//		for (int j = 0; j < vec.size() - 1 - i; ++j)
//		{
//			if (vec[j] > vec[j + 1])
//				swap(vec[j], vec[j + 1]);
//		}
//	}
//}

namespace N1
{
	class stack
	{
	public:
		stack(int size)
			:_size(size)
			, _index(0)
			, _stack(new int[size])
		{}
		void push(int num)
		{
			if (_index == _size)
				cout << "已满" << endl;
			else
				_stack[_index++] = num;
		}
		void pop()
		{
			if (_index == 0)
				cout << "已空" << endl;
			else
				_index--;
		}
		int front()
		{
			if (_index == 0)
				cout << "已空" << endl;
			else
				return  _stack[_index - 1];
		}
		int size()
		{
			return  _index;
		}
	private:
		int _size;
		int _index;
		int* _stack;
	};
	class queue
	{
	public:
		queue(int size)
			:_size(size)
			, _queue(new int[size])
			, _index(0)
		{}
		void push(int num)
		{
			if (_size == _index)
				cout << "已满" << endl;
			else
			{
				for (int i = _index - 1; i >= 0; --i)
				{
					_queue[i + 1] = _queue[i];
				}
				_queue[0] = num;
				_index++;
			}
		}

		void pop()
		{
			if (_size == 0)
				cout << "已空" << endl;
			else
			{
				_index--;
				_size--;
			}
		}
		int front()
		{
			return _queue[_index - 1];
		}
		int back()
		{
			return _queue[0];
		}
		int size()
		{
			return _size;
		}
	private:
		int* _queue;
		int _size;
		int _index;
	};

	class queue2
	{
	public:

		queue2(int size)
			:_queue(new int[size])
			, _size(0)
			, _begin(0)
			, _end(0)
			, length(size)
		{}
		void push(int num)
		{
			if (_size == length)
				cout << "已满" << endl;
			else
			{
				_size++;
				_queue[_begin] = num;
				_begin = _begin == length - 1 ? 0 : _begin + 1;
			}
		}

		void pop()
		{
			if (_size == 0)
				cout << "已空" << endl;
			else
			{
				_size--;
				_end = _end == length ? 0 : _end + 1;
			}
		}
		int size()
		{
			return _size;
		}
		int front()
		{
			if (_size > 0)
				return _queue[_end];
			else
				cout << "已空" << endl;
			return 0;
		}
		int back()
		{
			if (_size > 0)
			{
				if (_begin == 0)
				{
					return _queue[length - 1];
				}
				return _queue[_begin - 1];
			}
			else
			{
				cout << "已空" << endl;
				return 0;
			}
		}
	private:
		int* _queue;
		int _size;
		int _begin;
		int _end;
		int length;
	};
}


int main()
{
	/*N1::queue que(5);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);

	cout << que.size() << endl;
	que.push(6);
	cout << que.back() << endl;
	cout << que.front() << endl;
*/

	N1::queue2 que(5);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);
	cout << que.size() << endl;
	cout << que.front() << endl;
	cout << que.back() << endl;
	que.push(6);
	que.pop();
	que.pop();
	que.pop();
	que.pop();
	que.pop();
	cout << que.size() << endl;
	cout << que.front() << endl;
	cout << que.back() << endl;

	/*N1::stack sta(5);
	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);
	sta.push(5);
	cout << sta.size() << endl;
	sta.pop();
	cout << sta.size() << endl;
	sta.pop();
	sta.pop();
	sta.pop();
	sta.pop();*/


	//vector<int> vec{ 8, 5, 2, 0, 7, 4, 1, 9, 6, 3 };
	//func2(vec,0,9);
	/*func3(vec);
	for (auto e : vec)
		cout << e << endl;*/
	return 0;
}