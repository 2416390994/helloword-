#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#if 0
class person
{
public:
	void operator()(int num)
	{
		cout << num << endl;
	}
	
};
void printfs(set<int>& p)
{
	for (set<int>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it <<" ";
	}
	cout << endl;
}
class oper
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
void printfs2( set<int,oper>& p)
{
	for (set<int,oper>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it <<" ";
	}
	cout << endl;
}
bool func(int a, int b)
{
	return a > b;
}
void test01()
{
	person a;
	a(111);
}
void test02()
{
	set<int>v;
	v.insert(10);
	v.insert(18);
	v.insert(9);
	v.insert(15);
	printfs(v);
	set<int,oper>v1;    //���÷º���
	v1.insert(10);
	v1.insert(18);
	v1.insert(9);
	v1.insert(15);
	printfs2(v1); 
}
int main()
{	
	test01();
	test02();
	return 0;
}
#endif
#if 0
#include<algorithm>

class func20
{
public:
	//һԪν�ʵ�ʹ�ã�һԪ��������bool ν���������ˣ�int a��
	bool operator()(int a)
	{
		return a > 5;
	}
};
void test()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	//����������Ҫ��һ����������
	//func20 p;
	//find_if(v.begin(), v.end(), p); 
	//�����Ը�ⶨ��һ��������ô�Ϳ�������������func20()
	//find_if��󷵻�һ��������
	vector<int>::iterator it = find_if(v.begin(), v.end(), func20());   
	if (it!=v.end())
	{
		cout << "�ҵ��˵�һ������5������" << *it << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}


}
//��Ԫν�ʵ�ʹ��
void printfs(vector<int>& p)
{
	for (vector<int>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
class func
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
bool func2(int a, int b)
{
	return a > b;
}
void test2()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	sort(v.begin(), v.end());
	printfs(v);         //������֮��ṹ�㷢���˸ı�
	sort(v.begin(), v.end(), func());  //�º�������
	printfs(v);
	sort(v.begin(), v.end(), func2);    //���ûص�����
	//����߶˵ķ�ʽ��ӡһ��
	//lambda���ʽ[](){}  //��������
	for_each(v.begin(), v.end(), [](int val){cout << val << " " << endl;});
}
#endif
void test04()
{
	//telplate<class T>T negate<T>      ȡ��
	negate<int>n;
	cout << n(10) << endl;
	//telplate<class T>T plus<T> �ӷ�
	plus<int>p;
	cout << p(1,1) << endl;

}
void test05()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	//template<class T>T greater<T>����
	sort(v.begin(), v.end(), greater<int>());//ʹ���ڽ��Ĵ��ں��������ڲ�ʵ�ֺ������Լ�д����ʵһ��
	for_each(v.begin(), v.end(), [](int val){cout << val << " " ; });
}
int main()
{
	test04();
	test05();
	return 0;
}