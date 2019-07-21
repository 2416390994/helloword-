#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;
#if 0
//����ʽ������ֻҪ�������ݾ��Զ�����
void printfs(set<int>& p)
{
	for (set<int>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test()
{
	set<int>v;
	v.insert(1); //��������ֻ����insert
	v.insert(7);
	v.insert(3);
	v.insert(9);
	v.insert(5);
	printfs(v);          //1 3 5 7 9 Ĭ�ϴ�С�����������
	v.erase(++v.begin());    //��֧��������ʵ�����  1 5 7 9 
	v.erase(7);          //����ֱ��ͨ��ʵֵ����ɾ�� 1 5 9
	printfs(v);
}
void test1()
{
	set<int>v;
	v.insert(1); 
	v.insert(7);
	v.insert(3);
	v.insert(9);
	v.insert(5);
	set<int>::iterator pos = v.find(3);
	if (pos != v.end())
		cout << "�ҵ���" << endl;
	else
		cout << "û�ҵ�" << endl;
	//��Ϊset������û���ظ���ֵ����countҪô��0��Ҫô��1
	int counts = v.count(5);
	cout << "v.count(5)�ĸ�������" << counts << endl;
	set<int>::iterator s = v.lower_bound(10);
	//lower_bound��set�����ص�һ�� >=set�����ĵ��������Ҳ����Ļ��ͷ���v.set()(Ҳ�����������һ��Ԫ�ص���һ��λ��)
	if (s != v.end())
		cout << "�ҵ���" << *s << endl;
	else
		cout << "û�ҵ�" << endl;
	//upper_bound��set�����ص�һ�� >set�����ĵ��������Ҳ����Ļ��ͷ���v.set()
	set<int>::iterator s1 = v.upper_bound(5);    
	if (s1 != v.end())
		cout << "�ҵ���" << *s1 << endl;
	else
		cout << "û�ҵ�" << endl;
	//equal_range��set���᷵����������ֵ(������)��set�����޺�����Ҳ����lower_bound��set����upper_bound��set��
	//��ʱ�����Ҫ����ײ�ȥ��������������������ֵ������pair<iterator, iterator>
	//pair<iterator, iterator>�����һ������
	pair<set<int>::iterator , set<int>::iterator> L = v.equal_range(3);
	//�������൱�ڶ�����˱���L������ȡ����ֵ 
	if (L.first != v.end())
		cout << "�ҵ��� lower_bound��set��= " << *(L.first) << endl;
	else
		cout << "û�ҵ�" << endl;
	if (L.second != v.end())
		cout << "�ҵ��� upper_bound��set��= " << *(L.second) << endl;
	else
		cout << "û�ҵ�" << endl;
}
void test2()
{
	///��һ�ִ�������ķ�ʽ
	pair<string, int> p("����", 10);
	cout << p.first << " " << p.second << endl;
	///�ڶ��ִ�������ķ�ʽ
	pair<string, int> p1 = make_pair("����", 10);
	cout << p1.first << " " << p1.second << endl;
}
void test3()
{
	//����insert����������ظ���ֵ���
	set<int>v;
	v.insert(1);
	v.insert(1);
	printfs(v);        //�������гɹ�����ֻ��ӡһ��1
	//��������ײ�鿴insert��������ֵԭ��
	///_Pairib insert(value_type&& _Val)
	//typedef typename _Mybase::_Pairib _Pairib;
	//typedef pair<iterator, bool> _Pairib;   //����ֵԭ�������ڶ��������Ƕ��Ƿ����ɹ��ļ��
	//��֪����ֵ�Ƕ������ͣ����ǽ��м��һ��
	pair<set<int>::iterator, bool>  _Pairib;
	_Pairib = v.insert(10);
	if (_Pairib.second)
	{
		cout << "��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}
	_Pairib = v.insert(10);
	if (_Pairib.second)
	{
		cout << "�ڶ��β���ɹ�" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��" << endl;
	}
}
//�Ӵ�С����set����
//����Ĭ���Ǵ�С���󣬵��ǲ�������֮��Ͳ����ٱ������޸ģ�����Ҫ��Ӵ�С����ͱ����ڲ�������ǰ��ָ��������������÷º�����
class person
{
public:
	int operator() (int a, int b)       //����()��Ҫ��Ϊʲô��Ϊ��Ҳ��֪��
	{
		return a > b;
	}

};
void printfs2(set<int, person>& p)
{
	for (set<int, person>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test4()
{
	set<int>v;
	v.insert(1);
	v.insert(7);
	v.insert(3);
	v.insert(9);
	v.insert(5);
	printfs(v);   //Ĭ���Ǵ�С�����ӡ
	set<int, person>v1;
	v1.insert(1);
	v1.insert(7);
	v1.insert(3);
	v1.insert(9);
	v1.insert(5);
	printfs2(v1);
}
#endif
#if 0
//�Զ�����������������
class person
{
public:
	person(string name, int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	string name;
	int ages;
};
class sorts           //α������������дһ����
{
public:
	bool operator() (const person& a, const person& b)       //����()��Ҫ��Ϊʲô��Ϊ��Ҳ��֪��
	{
		return a.ages > b.ages;
	}
};
void printfs(set<person,sorts>& p)
{
	cout << "-----------------" << endl;
	for (set<person,sorts>::iterator it = p.begin(); it != p.end(); ++it)
	{
		cout << "|  "<< it->name <<"\t"<< "|  " << (*it).ages <<"\t"<< "| " << endl;
		cout << "-----------------" << endl;
	}
}
void test5()
{
	set<person,sorts>v;
	person p1("����", 100);
	person p2("2��", 90);
	person p3("3��", 80);
	person p4("4��", 70);
	person p5("5��", 60);
	person p6("6��", 50);
	person p7("7��", 40);
	person p8("үү", 30);
	v.insert(p1);
	v.insert(p2);
	v.insert(p3);
	v.insert(p4);
	v.insert(p5);
	v.insert(p6);
	v.insert(p7);
	v.insert(p8);
	printfs(v);
}
int main()
{
	test5();
	return 0;
}
#endif
int main()
{
	vector<int>v;
	int a = 1;
	v.push_back(a);
	v.push_back(a);
	v.push_back(a);
	v.push_back(a);
	v.push_back(a);
	cout << v.size() << endl;
}