#if 0
#include<iostream>
#include<map>
#include<string>
using namespace std;
void printfs(map<int,string>& p)
{
	for (map<int, string>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << (*it).second << endl;
	}
}
void test()
{
	map<int, string>v;   //必须指定两个参数类型，第一个键值第二个是实值
	//四种插入数据的方式
	v.insert(pair<int,string>(1, "西瓜"));
	v.insert(make_pair(2, "南瓜"));          //推荐
	v.insert(map<int, string>::value_type(3, "冬瓜"));
	v[4] = ("北瓜");
	v[5];          //如果不做数据插入那么系统会自动给你插入一个值，在目前位置有的是插0，有的插" "空所以不建议这样插入，但是可以这输出比较方便
	printfs(v);
	v.erase(5);       //删除指定key值的pair对组（意思就是将实值和key键值都删掉）
	printfs(v);
	map<int,string>::iterator p = v.find(3);       //返回的是迭代器，找到返回key所对应的迭代器，找不到返回v.end（）
	if (p != v.end())
	{
		cout << "找到" << (*p).second << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	int a = v.count(4);
	cout << a << endl;
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<time.h>
using namespace std;
enum{吃饭,拉屎,吃屎};
class person
{
public:
	person(string name,int money)
	{
		this->name = name;
		this->money = money;
	}
	string name;
	int money;
};
void chushihua(vector<person>& p)
{
	string name1 = "员工";
	string  A = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		string name2 = name1 + A[i];
		int money = rand() % 10000 + 10000;
		person s(name2, money);
		p.push_back(s);
	}
}
void printfs(vector<person>& p)
{
	for (vector<person>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << it->name << " " << it->money << endl;
	}
}
void Fenzu(vector<person>& p1,multimap<int,person>&p2)
{
	for (vector<person>::iterator it = p1.begin(); it != p1.end(); ++it)
	{
		int num = rand() % 3;
		p2.insert(make_pair(num, *it));
	}
}

void func(multimap<int,person>& p)
{
	multimap<int, person>::iterator it = p.find(吃饭);
	int a = 0;
	int num = p.count(吃饭);
	cout << "吃饭部门员工" << endl;
	for (it; a++ < num; ++it)  //1 A B | 2 C D|3 E
	{
		cout << "姓名 :" << (*it).second.name << " " << "工资 :" << (*it).second.money << endl;
	}
	cout << "-------------------------------" << endl;
	it = p.find(拉屎);
	a = 0;
	num = p.count(拉屎);
	cout << "拉屎部门员工" << endl;
	for (it; a++ < num; ++it)  //1 A B | 2 C D|3 E
	{
		cout << "姓名 :" << (*it).second.name << " " << "工资 :" << (*it).second.money << endl;
	}
	cout << "---------------------------------" << endl;
	it = p.find(吃屎);
	a = 0;
	num = p.count(吃屎);
	cout << "吃屎部门员工" << endl;
	for (it; a++ < num; ++it)  //1 A B | 2 C D|3 E
	{
		cout << "姓名 :" <<  (*it).second.name << " " <<"工资 :"<< (*it).second.money << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//初始化五名员工
	vector<person>v;
	chushihua(v);
	//分组
	multimap<int, person>M;      //这里员工分组选择的是multimap容器，是因为multimap容器一个key值（组）可以容纳多个实值（员工）
	Fenzu(v, M);
	//按照分组打印
	func(M);
	return 0;
}
#endif
















