#include<iostream>
#include<string>
#include<vector>
using namespace std;
class A
{
public:
	static A* func()
	{
		return new A;
	}
	A(const A& p) = delete;
	A& operator=(const A& p) = delete;
private:
	A()
	{
	
	}

	int* p;
};

iterator erase(iterator pos)
{
	Node* pCur = pos._pCur;
	if (pCur == first)
		return end();
	Node* pres = pCur->_next;
	pCur->_prv->_next = pCur->_next;
	pCur->_next->_prv = pCur->_prv;
	delete pCur;
	return iterator(pres);
}

void func()
{

}
struct B
{
	int a;
	int b;
	int c;
};
int main()
{
	B* A;
	func();

	return 0;
}