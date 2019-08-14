#include<iostream>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
class animal
{
public:
	animal()
	{}
	animal(string name, string type) 
		:name(name)
		, type(type)
	{}
public:
	string type;
	string name;
	int index;
};
class animalAdd// : public animal
{
public:
	animalAdd()   //��index���г�ʼ��
	{
		this->index = 0;
	}
	void add(animal &S)    //ѹ��
	{
		if (S.type == "dog")
		{
			p1.push(S);
			S.index = this->index++;
		}
		else
		{
			p2.push(S);
			S.index = this->index++;
		}
	}
	void pollAll()      //ȫ������
	{
		if (p1.front().index < p2.front().index)
		{
			p1.pop();
		}
		else
		{
			p2.pop();
		}
	}
	void pollDog()
	{
		while (p2.size() > 0)
			p2.pop();
	}
	void pollCat()
	{
		while (p1.size() > 0)
			p1.pop();
	}
	void isEmpty()
	{
		if (p1.size() > 0 || p2.size() > 0)
			cout << "�����л���è���߹���ʵ��" << endl;
		else
			cout << "������û��è���߹���ʵ��" << endl;
	}
	void isDogEmpty()
	{
		if (p2.size() > 0)
			cout << "�й�" << endl;
		else
			cout << "�޹�" << endl;
	}
	void isCatEmpty()
	{
		if (p1.size() > 0)
			cout << "��è" << endl;
		else
			cout << "��è" << endl;
	}
private:
	queue<animal>p1;
	queue<animal>p2;
	int index;
};
void test()
{
	animal c1("����һ��", "cat");
	animal c2("���Ӷ���", "cat");
	animal c3("��������", "cat");
	animal c4("�����ĺ�", "cat");
	animal d1("�ڱ�һ��", "dog");
	animal d2("�ڱ�����", "dog");
	animal d3("�ڱ�����", "dog");
	animal d4("�ڱ��ĺ�", "dog");
	animalAdd v;
	v.add(c1);
	v.add(d1);
	v.add(c2);
	v.add(d2);
	v.add(c3);
	v.add(d3);
	v.add(c4);
	v.add(d4);
	v.isCatEmpty();
	v.isDogEmpty();
	v.isEmpty();
	v.pollCat();
	v.isCatEmpty();
	v.pollDog();
	v.isDogEmpty();
	v.isEmpty();
}
int main()
{
	test();
	return 0;
}