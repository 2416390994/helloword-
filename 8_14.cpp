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
	animalAdd()   //对index进行初始化
	{
		this->index = 0;
	}
	void add(animal &S)    //压入
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
	void pollAll()      //全部弹出
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
			cout << "队列中还有猫或者狗的实例" << endl;
		else
			cout << "队列中没有猫或者狗的实例" << endl;
	}
	void isDogEmpty()
	{
		if (p2.size() > 0)
			cout << "有狗" << endl;
		else
			cout << "无狗" << endl;
	}
	void isCatEmpty()
	{
		if (p1.size() > 0)
			cout << "有猫" << endl;
		else
			cout << "无猫" << endl;
	}
private:
	queue<animal>p1;
	queue<animal>p2;
	int index;
};
void test()
{
	animal c1("橘子一号", "cat");
	animal c2("橘子二号", "cat");
	animal c3("橘子三号", "cat");
	animal c4("橘子四号", "cat");
	animal d1("黑豹一号", "dog");
	animal d2("黑豹二号", "dog");
	animal d3("黑豹三号", "dog");
	animal d4("黑豹四号", "dog");
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