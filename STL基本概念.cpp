#if 0
#include<iostream>
using namespace std;
void test()
{
	int a = 0;
	int b = 0;
	int d = 0;
	int e = 0;
	char c;
	while ((c = cin.get())!= '\n')
	{
		if (c >= 'A' && c <= 'Z')
		{
			 a++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			b++;
		}
		else if (c >= '0' && c <= '9')
		{
			d++;
		}
		else
		{
			e++;
		}
	}
	cout << "��д��ĸ" << a << endl << "Сд��ĸ" << b << endl << "����" << e << endl << "����" << d << endl;
}
void test2()
{
	int a = 0;
	int b = 0;
	int d = 0;
	int e = 0;
	int count = 0;
	while (1)
	{
		char c = cin.get();
		if (c == '\n')
		{
			if (++count == 3)
				break;
		}
		if (c >= 'A' && c <= 'Z')
		{
			a++;
		}
		else if (c >= 'a' && c <= 'z')
		{
			b++;
		}
		else if (c >= '0' && c <= '9')
		{
			d++;
		}
		else
		{
			if (c == '\n')
			{}
			else
				e++;
		}
	}
	cout << "��д��ĸ" << a << endl << "Сд��ĸ" << b << endl << "����" << e << endl << "����" << d << endl;
}
int main()
{
	test2();
	return 0;
}
#endif
//vector
#if 0
#include<iostream>
#include<vector>//����ͷ�ļ�
using namespace std;
void test()
{
	vector<int>v;      //����һ����Ϊv������������������int������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//vector<int>::iterator itbegin = v.begin(); //��������������ָ����������ʼλ��
	//vector<int>::iterator itend = v.end();      //�����end����ָ�������һ��������һ��λ��
	//while (itbegin != itend)
	//{
	//	cout << *(itbegin++) << endl;
	//}
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}
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
using namespace std;
void test()
{
	vector<int>v;      //����һ����Ϊv������������������int������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	for (vector<int>::iterator it = v.begin(); it != v.end; ++it)
	{
		cout << it << endl;
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<vector>//����ͷ�ļ�
#include<algorithm>//�㷨ͷ�ļ�
using namespace std;
void myprintf(int v)
{
	cout << v << endl;
}
void test()
{
	vector<int>v;      //����һ����Ϊv������������������int������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	for_each(v.begin(), v.end(), myprintf);//myprintf�Զ����һ���ص����������岽��ɲ鿴Դ��
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
using namespace std;
class person
{
public:
	person(string name ,int ages)
	{
		this->ages = ages;
		this->name = name;
	}
	int ages;
	string name;
};
void test()
{
	person p1("��ͷ����", 10);
	person p2("Сͷ�ְ�", 50);
	person p3("Χȹ����", 25);
	person p4("��������", 28);
	vector<person*>v;   //<>�ڵ����;���������������ŵ���������
	v.push_back(&p1);  //�����ڴ�ŵ����Զ������͵�ָ����ô�����Ҫ�ĳɵ�ַ
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	//��ô*itҲ���Ÿı䣬���ʱ��*it���൱��ָ���Զ����������Ͷ����ָ�롣һ�仰*it����< >�ڵ�����
	for (vector<person*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->name << " " << (*(*it)).ages << endl;   //���������ֱ�����ʽ��չʾ
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
//������Ƕ��
#include<iostream>
using namespace std;
#include<vector>
void test()
{
	//�ȶ���һ��Ƕ�׵�������������Ƚ�ѧ¥����Ľ���
	vector<vector<int>>v;
	//�ڶ����ڲ���������������ﶨ�������Ϳ�����
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	//�ȶ����ڲ�������ֵ
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i);
		v2.push_back(10 + i);
		v3.push_back(100 + i);
	}
	//������С��������������ֵ
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	//�������ǳ��Դ�ӡһ���������������
	//��ӡҲ�Ǵ�С������ʼ��ӡ��
	for (vector<vector<int>>::iterator it1 = v.begin(); it1 < v.end(); ++it1)
	{
		for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); ++it2)
		{
			cout << (*it2) << " ";
		}
		cout << endl;
	}
}
int main()
{
	test();
	return 0;
}
#endif
#if 0
#include<iostream>
using namespace std;
class person
{
public:
	static int man;
};
int person::man = 10;
int main()
{
	cout << person::man << endl;
	return 0;
}
#endif