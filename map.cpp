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
	map<int, string>v;   //����ָ�������������ͣ���һ����ֵ�ڶ�����ʵֵ
	//���ֲ������ݵķ�ʽ
	v.insert(pair<int,string>(1, "����"));
	v.insert(make_pair(2, "�Ϲ�"));          //�Ƽ�
	v.insert(map<int, string>::value_type(3, "����"));
	v[4] = ("����");
	v[5];          //����������ݲ�����ôϵͳ���Զ��������һ��ֵ����Ŀǰλ���е��ǲ�0���еĲ�" "�����Բ������������룬���ǿ���������ȽϷ���
	printfs(v);
	v.erase(5);       //ɾ��ָ��keyֵ��pair���飨��˼���ǽ�ʵֵ��key��ֵ��ɾ����
	printfs(v);
	map<int,string>::iterator p = v.find(3);       //���ص��ǵ��������ҵ�����key����Ӧ�ĵ��������Ҳ�������v.end����
	if (p != v.end())
	{
		cout << "�ҵ�" << (*p).second << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
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
enum{�Է�,��ʺ,��ʺ};
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
	string name1 = "Ա��";
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
	multimap<int, person>::iterator it = p.find(�Է�);
	int a = 0;
	int num = p.count(�Է�);
	cout << "�Է�����Ա��" << endl;
	for (it; a++ < num; ++it)  //1 A B | 2 C D|3 E
	{
		cout << "���� :" << (*it).second.name << " " << "���� :" << (*it).second.money << endl;
	}
	cout << "-------------------------------" << endl;
	it = p.find(��ʺ);
	a = 0;
	num = p.count(��ʺ);
	cout << "��ʺ����Ա��" << endl;
	for (it; a++ < num; ++it)  //1 A B | 2 C D|3 E
	{
		cout << "���� :" << (*it).second.name << " " << "���� :" << (*it).second.money << endl;
	}
	cout << "---------------------------------" << endl;
	it = p.find(��ʺ);
	a = 0;
	num = p.count(��ʺ);
	cout << "��ʺ����Ա��" << endl;
	for (it; a++ < num; ++it)  //1 A B | 2 C D|3 E
	{
		cout << "���� :" <<  (*it).second.name << " " <<"���� :"<< (*it).second.money << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//��ʼ������Ա��
	vector<person>v;
	chushihua(v);
	//����
	multimap<int, person>M;      //����Ա������ѡ�����multimap����������Ϊmultimap����һ��keyֵ���飩�������ɶ��ʵֵ��Ա����
	Fenzu(v, M);
	//���շ����ӡ
	func(M);
	return 0;
}
#endif
















