#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>//1.���ͷ�ļ�functional
#include<string>
using namespace std;
#if 0
//���Ȳ���һ�¼򵥵�
void test01()
{
	vector<int>p2;
	for (int i = 0; i < 10; ++i)
	{
		p2.push_back(i);
	}
	vector<int>::iterator it = find(p2.begin(), p2.end(), 5);        //��˼������5������ֵ��һ��������
	if (it != p2.end())
	{
		cout << "�ҵ���" << *it << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}
//�����Զ��������
class person
{
public:
	person(string name,int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	bool operator == (const person& p)           //�����мǼ���const�������˰�
	{
		if (this->ages == p.ages && this->name == p.name)
			return true;
		else
			return false;
	}
	int ages;
	string  name;
};
void test02()
{
	vector<person>v;
	person p1("��1", 10);
	person p2("��2", 9);
	person p3("��3", 8);
	person p4("��4", 7);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//find(v.begin(), v.end(),p2);ֱ���������ҿ϶��ǲ��еģ�����Ҫ֪���ײ����������ҵ�  
	//if (*_First == _Val)���ǿ������д�����ǵײ�Ĳ��Һ��ģ��õ���==
	//�������Զ�������������������Ǳ����==��������
	vector<person>::iterator it = find(v.begin(), v.end(), p2);
	if (it != v.end())
	{
		cout << "�ҵ���" << (*it).name<<" "<<(*it).ages << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}
#endif
#if 0
//�û��������
class person
{
public:
	person(string name, int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	int ages;
	string  name;
};
class func:public binary_function<person*,person*,bool>
{
public:
	bool operator()(const person* p1,const person* p2)const
	{
		if (p1->ages == p2->ages && p1->name == p2->name)
		{
			return true;
		}
		else
			return false;
	}
};
void test03()
{
	vector<person*>v;
	person p1("��1", 10);
	person p2("��2", 9);
	person p3("��3", 8);
	person p4("��4", 7);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	person* p5 = new person("��2", 9);
	vector<person*>::iterator it = find_if(v.begin(), v.end(),bind2nd(func(),p5));
	if (it != v.end())
	{
		cout << "�ҵ���" << (*it)->name << " " << (*it)->ages << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}
#endif
#if 0
void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(8);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "�ҵ���" << (*it)<< endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
}
#endif
#if 0
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 4);
	if (ret)
		cout << "�ҵ���" << endl;
	else
		cout << "û�ҵ�" << endl;
}
#endif
int func(int a)
{
	return a > 4;
}
void test06()
{
	vector<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	int ret = count(v.begin(), v.end(), 3);     //����ֵ�����в���
	cout << ret << endl;
	ret = count_if(v.begin(), v.end(), func);     //�������ң����ûص�����
	cout << ret << endl;
}
int main()
{
	test06();
	return 0;
}