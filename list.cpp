#if 0
void test()
{
	list<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	list<int>::_Nodeptr it = v._Myhead->_Next;
	for (int i = 0; i < v._Mysize*2; ++i)
	{
		cout << it->_Myval;
		it = it->_Next;
		if (it == v._Myhead)
		{
			it = it->_Next;
			cout << endl;
		}
	}
}
void printfs(list<int>& q)                      //��ӡlist
{
	for (list<int>::iterator it = q.begin(); it != q.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void printfs2(list<int>& q)                      //��ӡlist
{
	for (list<int>::reverse_iterator it = q.rbegin(); it != q.rend(); ++it)      //reverse_iterator�����ӡ������
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test1()
{
	list<int>v;   //ģ��Ĭ�Ϲ���
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	list<int>v1(v.begin(), v.end());       //�ṩ���乹��
 	list<int>v2(10, 20);       //ֵ����
	printfs(v);       //�����ӡ           
	list<int>v3(v1);      //��������
	printfs2(v3);             //�����ӡ
}
void test2()
{
	//remove��elem��ɾ��������������elem��ͬ������
	list<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(2);
	v.remove(2);
	printfs(v);
}
bool func(int a,int b)
{
	return  a > b;
}
bool func2(int a, int b)
{
	return  a < b;
}
void test3()
{
	list<int>v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	printfs(v);
	v.reverse();     //��ת
	printfs(v);
	//sort(v.begin(), v.end());   ����ֱ�������ǻᱨ��ģ���Ϊ���в�֧��������ʵĵ������޷�ʹ����������
	v.sort();         //����ʹ�������������������ڲ��ṩ��һ������
	printfs(v);
	v.sort(func);     //���о��Ǽ���ʹ���ṩ���㷨�Ļ���ô��Ҫʹ�ûص�����
	printfs(v);
}
#endif
#include<iostream>
#include<list>
#include<string>
using namespace std;
void printfs(list<int>& q)                      //��ӡlist
{
	for (list<int>::iterator it = q.begin(); it != q.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
class person
{
public:
	person(string name, int ages, int tall)
	{
		this->ages = ages;
		this->myname = name;
		this->tall = tall;
	}
	bool operator==(person p)             //���ڷ���ֵΪʲô��bool���ͣ���remove�ײ㺯�����Կ���if (*_First == _Val)
	{                                      //�����Ȼ�Ƕ�==��������ô�ͱ�Ȼ���صȺ�����Ҫ֪���Ķ������Ǿ�������������Ȼ��߲���
		if (this->ages == p.ages&&this->myname == p.myname&&this->tall == p.tall)
		{
			return true;
		}
		else
			return false;
	}
	string myname;
	int ages;
	int tall;
};
bool func(person& a, person& b)        //�����int�����ݣ�����Ĳ�����   ����+����
{
	if (a.ages == b.ages)
	{
		return a.tall > b.tall;       //�����������������൱�Ͱ�˭�ĸ��Ӹ�˭��ǰ������
	}
	return a.ages > b.ages;            //����Ͱ���������ǰ��
}
void printfs(list<person>&v)
{
	for (list<person>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it).myname << "\t" << (*it).ages << "\t" << it->tall << endl;
	}
}

void test4()
{
	
	list<person>v;
	person p1("�߽���", 18,180);
	person p2("����", 22,120);
	person p3("����", 34,130);
	person p4("����", 28,150);
	person p5("������", 16,187);
	person p6("������", 10, 155);
	person p7("����", 10, 185);
	person p8("����", 10, 142);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	v.push_back(p8);
	//a���������С��Ԫ�ؽ������
	v.sort(func);       //�����Զ����������ͱ���ʹ���Լ�д�Ļص�����
	printfs(v);
	v.remove(p6);
	v.remove(p5);
	v.remove(p4);
	v.remove(p2);
	v.remove(p8);
	//��������Ҫʹ��remove��ɾ��p6,����϶��Ǵ���ģ������Ҫ�鿴remove�ĵײ㶨����
	//void remove(const _Ty& _Val)
	//{	// erase each element matching _Val
	//	iterator _Val_it = end();

	//	for (iterator _First = begin(); _First != end();)
	//	if (*_First == _Val)
	//	if (_STD addressof(*_First) == _STD addressof(_Val))
	//		_Val_it = _First++;
	//���ǻᷢ���ڵײ�����ôһ�仰if (*_First == _Val)��������Զ������ͺ�v.begin()�Ƚϣ�
	//���߶��Ƕ���Ҫ�ǻ������;Ϳ��������Ƚϣ��������Զ�������ϵͳ��֪����αȽϣ�
	//�������Ҫʹ��removeɾ���Զ����������ͣ��ͱ�����д ==
	cout << "===============================================" << endl;
	printfs(v);
}

int main()
{
	test4();
	return 0;
}