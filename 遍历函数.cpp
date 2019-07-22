#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>//1.���ͷ�ļ�functional
#include<string>
using namespace std;
#if 0
//��һ�����ǣ�for_eachǰ�������Ѿ�ѧ�������÷º��������߻ص�������ӡ�ķ���
//�ڶ������ǽ����������÷�����������for_each�ķ���ֵ��¼����
//��Ϊα�����������һ���࣬�ڲ�����ά���ܶ������
class person
{
public:
	void operator()(int v)
	{
		count++;
		cout << v << endl;
	}
	int count;
};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	person p1 = for_each(v.begin(), v.end(), person());    //��������ֵ���������Ƿ���һ�������͵Ķ���
	cout << p1.count << endl;;
}
//������for_each���԰󶨲����������������������
class person01:public binary_function<int,int,void>
{
public:
	void operator()(int v,int start)const
	{
		cout << v + start << endl;
	}
};
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	for_each(v.begin(), v.end(), bind2nd(person01(),100));    //�ڵ������������а�Ŀ�������ڲ������ݵĻ�����+100
}
#endif
class person02 :public binary_function<int, int, int>
{
public:
	int operator()(int v, int start)const
	{
		return v + start;
	}
};
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	vector<int>v1;
	v1.resize(v.size());     //����ռ�
	transform(v.begin(), v.end(), v1.begin(), bind2nd(person02(), 10));   //�����������Ԫ��
	for_each(v.begin(), v.end(), [](int val){cout << val << endl; });    //��ӡ
}
class func
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
void test04()
{
	vector<int>p1;
	vector<int>p2;
	for (int i = 0; i < 10; ++i)
	{
		p1.push_back(i + 10);
		p2.push_back(i + 20);
	}
	vector<int>p3;
	p3.resize(p1.size());
	transform(p1.begin(), p1.end(), p2.begin(), p3.begin(),func()); 
	for_each(p3.begin(), p3.end(), [](int val){cout << val << endl; });    
}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}