#include<iostream>
#include<unordered_map>
#include<unordered_multimap>
#include<string>
using namespace std;
void func()
{
	unordered_map<string, string> m;
	m.insert(pair<string, string>("��ʱ��", "�ɽ�"));
	m.insert(make_pair("��ʱ��2", "�ν�"));

	//�鿴Ԫ�ظ���
	cout << m.size() << endl;

	//�鿴Ͱ�ĸ���
	cout << m.bucket_count() << endl;
	
	//�鿴��0��Ͱ�е�Ԫ�ظ���
	cout << m.bucket_size(0) << endl;

	//�鿴��ʱ�����ĸ�Ͱ��
	cout << m.bucket("��ʱ��") << endl;
	cout << m.bucket("��ʱ��2") << endl;


	//����������������[]
	cout << m["��ʱ��"] << endl;
	cout << m.size() << endl;

	//[]:���key�����ڣ�<key,Ĭ��value>����һ����ֵ�ԣ�Ȼ������뵽�����У�����Ĭ�ϵ�value,vs2013���ؿ�
	cout << m["������"] << endl;
	cout << m.size() << endl;




}
void func2()
{
	unordered_multimap<string, string> m;
}

int main()
{
	//func();
	func2();

	return 0;
}