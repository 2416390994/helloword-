/*
#include<stdio.h> 
int bucket(int num, int length, int max, int min)
{
	return (int)(num - min)*length / (max - min);  //�����ǲ�Ӱ����
	//return (num - 9) / 9;
}
int func(int *a, int length)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < length; ++i)   //����һ���������������õ������ֵ����Сֵ
	{
		if (a[i] < min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}
	//Ͱ�ĸ����������鳤��+1
	int * _1 = new int[length + 1];//��һ������������ʾ�������Ͱ������û��Ԫ��	
	int * _2 = new int[length + 1];//�ڶ�������������¼�������Ͱ��������ֵ
	int * _3 = new int[length + 1];//����������������¼���Ͱ�������Сֵ
	for (int i = 0; i <= length; ++i)    //�õ�����֮��Ҫ���ǳ�ʼ�����Ȱ����ݳ�ʼ����0
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
	for (int i = 0; i < length; ++i)           ///��һ������֮��Ͱ�ÿ�����ֱ����˺ţ���ž����������ĸ�Ͱ
	{
		bid = bucket(a[i], length, max, min);
		//_2[bid] =	a[i];      //��һ���൱�ڳ�ʼ�����ѵ�ǰͰ�е����ֵ��ʼ��Ϊ�����������Сֵ��Ҫ�������ֽ�������min��ľͽ�������Ϊ���ܸ�ֵΪ0����һ��ʼ���������и�����ô�죬���������ʼ��Ϊ��Сֵ���
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
		//_3[bid] = max;  //ͬ������������ֵֻ��Ϊ�˳�ʼ�����������ֵ�������ģ���Ϊ���滹Ҫ�Ƚϣ�û������˼��
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
	int peek()             //�鿴
	{
		if (a == nullptr)
		{
			cout << "Ϊ��" << endl;
			return 0;
		}
		else
			return a[index - 1];
	}
	void push(int num)     //���
	{
		if (index == size )
		{
			cout << "�������޷����룡��" << endl;
			return;
		}
		this->a[index++] = num;
	}
	int pop()     //����
	{
		if (index == 0)
		{
			cout << "�ѿգ��޷���������" << endl;
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
	int peek()    //�鿴
	{
		if (index == 0)
		{
			cout << "�ѿ�" << endl;
		}
		return a[index - 1];
	}
	void push(int num)    //ѹ�����
	{
		if (index == size)
		{
			cout << "����" << endl;
			return;
		}
		for (int i = index -1 ; i >= 0; --i)
		{
			a[i + 1] = a[i];
		}
		a[0] = num;
		index++;
	}
	int pop()  //����
	{
		if (index == 0)
		{
			cout << "�ѿգ��޷�����" << endl;
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
	void push(int num)    //����
	{
		if (size == length)
		{
			cout << "�������޷�����" << endl;
			return;
		}
		size++;
		a[start] = num;
		start = (start == length - 1) ? 0 : start + 1;
	}
	int pop()        //����
	{
		if (size == 0)
		{
			cout << "�ѿգ��޷�����" << endl;
			return 0;
		}
		size--;
		int tmp = end;
		end = (end == length - 1) ? 0 : end + 1;
		return a[tmp];
	}
	int peek()   //�鿴
	{
		if (size == 0)
		{
			cout << "�ѿգ�û�����ֿ��Բ鿴" << endl;
			return 0;
		}
		return a[end];
	}
private:
	int *a;    //����
	int size;   //����Ĵ�С�������ֵĲ���仯������
	int start;   //ָ��Ԫ�ؿ��Բ����λ��
	int end;   ///ָ����е����һ��λ�ã����Ҫ�����Ļ��������λ�õ����ֵ���
	int length;//���������¼�������ĳ���
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
















