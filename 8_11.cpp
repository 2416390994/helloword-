/*
#include<stdio.h> 
int bucket(int num, int length, int max, int min)
{
	return (int)(num - min)*length / (max - min);  //有误差但是不影响结果
	//return (num - 9) / 9;
}
int func(int *a, int length)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < length; ++i)   //经这一步遍历整个数组拿到了最大值和最小值
	{
		if (a[i] < min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}
	//桶的个数就是数组长度+1
	int * _1 = new int[length + 1];//第一个数组用来表示的是这个桶里面有没有元素	
	int * _2 = new int[length + 1];//第二个数组用来记录的是这个桶里面的最大值
	int * _3 = new int[length + 1];//第三个数组用来记录这个桶里面的最小值
	for (int i = 0; i <= length; ++i)    //拿到数组之后不要忘记初始化，先把数据初始化成0
	{
		_1[i] = 0;
		_2[i] = 0;
		_3[i] = 0;
	}
	int bid = 0;
	int * count = new int[length + 1];
	for (int i = 0; i <= length; ++i)
	{
		count[i] = 0;
	}
	int * count2 = new int[length + 1];
	for (int i = 0; i <= length; ++i)
	{
		count2[i] = 0;
	}
	for (int i = 0; i < length; ++i)           ///这一步下来之后就把每个数字编上了号，编号决定你属于哪个桶
	{
		bid = bucket(a[i], length, max, min);
		//_2[bid] =	a[i];      //这一步相当于初始化，把当前桶中的最大值初始化为整个数组的最小值，要是有数字进来，比min大的就交换，因为不能赋值为0，万一初始的数组中有复数怎么办，所以这里初始化为最小值最好
		if (count[bid] == 0)
		{
			_2[bid] = a[i];
			count[bid]++;
		}
		else
		{
			if (_2[bid] <a[i])
				_2[bid] = a[i];
		}
		//_3[bid] = max;  //同理，这里采用最大值只是为了初始化（但是这个值得是最大的，因为里面还要比较）没其他意思，
		if (count2[bid] == 0)
		{
			_3[bid] = a[i];
			count2[bid]++;
		}
		else
		{
			if (_3[bid] > a[i])
				_3[bid] = a[i];
		}
		_1[bid] = 1;
	}
	for (int i = 0; i <= length; ++i)
	{
		printf("%d     %d     %d\n", _1[i], _2[i], _3[i]);
	}
	int res = 0;
	int lastmax = _2[0];
	for (int i = 1; i <= length; ++i)
	{
		if (_1[i] == 1)
		{
			//res = _3[i] - lastmax;
			if (_3[i] - lastmax > res)
			{
				res = _3[i] - lastmax;
			}
			lastmax = _2[i];
		}
	}
	return res;
}
int main()
{
	int a[] = { 12, 25, 23, 59, 46, 54, 20, 21, 44, 16 };
	int c = sizeof(a) / sizeof(int);
	int p = func(a, c);
	printf("%d", p);
	return 0;
}
*/

/*
#include<iostream>
#include<string>
using namespace std;
class zhan
{
public:
	zhan(int size)
	{
		this->a = new int[size];
		this->index = 0;
		this->size = size;
	}
	int peek()             //查看
	{
		if (a == nullptr)
		{
			cout << "为空" << endl;
			return 0;
		}
		else
			return a[index - 1];
	}
	void push(int num)     //添件
	{
		if (index == size )
		{
			cout << "已满！无法插入！！" << endl;
			return;
		}
		this->a[index++] = num;
	}
	int pop()     //弹出
	{
		if (index == 0)
		{
			cout << "已空！无法弹出！！" << endl;
			return 0;
		}
		return a[--index];
	}
	~zhan()
	{
		delete[]a;
	}
private:
	int *a = nullptr;
	int index;
	int size;
};
int main()
{
	zhan p(4);
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	cout<<p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	p.pop();
	p.pop();
	return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;
class duilie
{
public:
	duilie(int size)
	{
		this->a = new int[size];
		this->index = 0;
		this->size = size;
	}
	int peek()    //查看
	{
		if (index == 0)
		{
			cout << "已空" << endl;
		}
		return a[index - 1];
	}
	void push(int num)    //压入队列
	{
		if (index == size)
		{
			cout << "已满" << endl;
			return;
		}
		for (int i = index -1 ; i >= 0; --i)
		{
			a[i + 1] = a[i];
		}
		a[0] = num;
		index++;
	}
	int pop()  //弹出
	{
		if (index == 0)
		{
			cout << "已空，无法弹出" << endl;
			return 0;
		}
		return a[--index];
	}
private:
	int * a;
	int index;
	int size;
};
int main()
{
	duilie p(4);
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	p.pop();
	p.pop();
	return 0;
	return 0;
}
*/
#include<iostream>
#include<string>
using namespace std;
class duilie
{
public:
	duilie(int size)
	{
		this->a= new  int[size];
		this->start = 0;
		this->size = 0;
		this->end = 0;
		this->length = size;
	}
	void push(int num)    //插入
	{
		if (size == length)
		{
			cout << "已满，无法插入" << endl;
			return;
		}
		size++;
		a[start] = num;
		start = (start == length - 1) ? 0 : start + 1;
	}
	int pop()        //弹出
	{
		if (size == 0)
		{
			cout << "已空，无法弹出" << endl;
			return 0;
		}
		size--;
		int tmp = end;
		end = (end == length - 1) ? 0 : end + 1;
		return a[tmp];
	}
	int peek()   //查看
	{
		if (size == 0)
		{
			cout << "已空，没有数字可以查看" << endl;
			return 0;
		}
		return a[end];
	}
private:
	int *a;    //数组
	int size;   //数组的大小随着数字的插入变化的那种
	int start;   //指向元素可以插入的位置
	int end;   ///指向队列的最后一个位置，如果要弹出的话就是这个位置的数字弹出
	int length;//用这个来记录传进来的长度
};
int main()
{
	duilie p(4);
	p.push(1);
	p.push(2);
	p.push(3);
	p.push(4);
	p.push(5);
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	cout << p.peek();
	p.pop();
	p.pop();
	p.pop();
	return 0;
}
















