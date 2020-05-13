#include<iostream>
#include<string>
#include<vector>
#include<bitset>
using namespace std;
//struct Node
//{
//	int val;
//	Node* next;
//};
//
//class vec
//{
//public:
//	vec()
//	{
//		table = new Node[10];
//		for (int i = 0; i < 10; ++i)
//		{
//			table[i].next = nullptr;
//		}
//	}
//
//private:
//	Node* table;
//
//};
//
void func()
{
	bitset<100> bt;

	//将哪些比特位置1
	bt.set(12);
	bt.set(22);
	bt.set(32);
	bt.set(42);

	cout << bt << endl;

	cout << bt.size() << endl;
	cout << bt.count() << endl;

	//将哪些比特位置0
	bt.reset(12);
	bt.reset(22);
	bt.reset(32);
	bt.reset(42);

	cout << bt.size() << endl;
	cout << bt.count() << endl;
	if (bt.test(12))   //检测当前比特位是0还是1
	{
		cout << "12 bit is 1" << endl;
	}
	else
	{
		cout << "12 bit is 0" << endl;
	}



}
int main()
{
	func();

	return 0;
}