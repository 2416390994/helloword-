#if 0
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>//1.���ͷ�ļ�functional
#include<string>
using namespace std;
#if 0
class func
{
public:
	void operator()(int a)
	{
		cout << a+100 << endl;
	}

};
class func2 :public binary_function<int,int,void>//3.�̳���binary_function<��������1����������2������ֵ>
{
public:
	void operator()(int a, int start)const         //4.��const���ηº���operaator
	{
		cout << a + start << endl;
	}

};
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	for_each(v.begin(),v.end(),func()); //ʹ��α������ӡ
	//��ε���������
	//1.���ͷ�ļ�functional
	//2.����bind2nd������
	//3.�̳���binary_function<��������1����������2������ֵ>
	//4.��const���ηº���operaator
	cout << "��������ʼֵ��" << endl;
	int num;
	cin >> num;	
	for_each(v.begin(), v.end(), bind2nd(func2(), num));//2.����bind2nd������
}
#endif
#if 0
class func :public unary_function<int,bool> //��������һ����bool operator()(int a)const �����int a�Ĳ�����һ���Ǻ�������ֵ����
{
public:
	bool operator()(int a)const
	{
		return a > 5;
	}

};
//ȡ��������
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	vector<int>::iterator it = find_if(v.begin(), v.end(), func());
	if (it != v.end())
	{
		cout << "�ҵ���" << *it << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
	//�����޸�����������ı�º����ڲ�������Ѱ�ҵ�һ��С��5����
	//����Ҫ���õ�ȡ��������
	//1.���ȡ��������
	//2.�̳й�ϵ
	//3.const
	//4.ͷ�ļ�
	it = find_if(v.begin(), v.end(), not1(func()));    //������������ǰ��������˼���Ǵ�v.begin(),��v.end()��������ͷ��
	if (it != v.end())
	{
		cout << "�ҵ���" << *it << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}
#endif
#if 0
//����ָ��������
void func(int a,int num)
{
	cout << a + num << endl;
}
void test03()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	int num;
	cin >> num;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(func), num));//��ε��õ��Ǻ�������α������ptr_fun(func)����ָ��������
}
#endif
//��Ա����������
class person         
{
public:
	person(string name, int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	void func()        //��Ա����
	{
		cout << "���� :" << name << "���� :" << ages << endl;
	}
	string name;
	int ages;
};
void func(person & p)     //ȫ�ֺ���
{
	cout << "���� :" << p.name << "���� :" << p.ages<<endl;
}
void test04()
{
	vector<person>v;
	person p1("��1", 101);
	person p2("��2", 50);
	person p3("��3", 60);
	person p4("��4", 20);
	person p5("��5", 80);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	for_each(v.begin(), v.end(), func); //��������������ǻص��������üӣ�����α����Ҫ��()����Ϊα�����ӣ�����ʵ������������һ��������������
	cout << "------------------------------------------------" << endl;
	//���������ṩ�Ļص�������ȫ�ֺ���������Ѻ����õ����ڲ��ú�����Ϊ��Ա��������ô�ͻ���Ҫ��Ա����������
	for_each(v.begin(), v.end(), mem_fun_ref(&person:: func));   //����ȫ�ֺ���
}
int main()
{
	test04();
	return 0;
}
#endif