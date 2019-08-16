//���RandomPool�ṹ
#include<iostream>
#include<map>
#include<time.h>
#include<stdlib.h>
#include<string>
using namespace std;
template<class T>
class RandomPool
{
public:
	RandomPool()         //��ʼ��index
	{
		this->index = 0;
	}
	void insert(T key)   //����key
	{
		if (p2.find(key) != p2.end() && index != 0)    //�жϲ����ֵ�Ƿ����
		{
			cout << "��ֵ�Ѵ���,�޷�����" << endl;
			return;
		}
		else
		{
			cout << "����ɹ�" << endl;
			index++;
			p1.insert(make_pair(index, key));
			p2.insert(make_pair(key, index));
		}		
	}
	void Delete(T key)         //ɾ��keyֵ
	{
		if (p2.find(key) == p2.end())
		{
			cout << "�˼�ֵ������" << endl;
			return;
		}
		
		map<T, int>::iterator it1 = p2.find(key);
		map<int, T>::iterator it2 = p1.find(index);
		if (key != ((*it2).second))
		{
			int c = (*it1).second;
			p1.erase((*it1).second);
			p1.insert(make_pair((*it1).second, (*it2).second));
			p2.erase(key);
			p2.insert(make_pair((*it2).second, c));
			map<int, T>::iterator it3 = p1.find(index);
			p2.erase((*it3).second);
			p1.erase(index);
			index--;
			return;
		}
		p1.erase((*it1).second);
		p2.erase(key);
		index--;
	}
	int getindex()           //��ȡ����RandomPool�ṹ�е�index
	{
		return index;
	}
	int getsize()          //��ȡRandomPool�ṹ�ĳ���
	{
		return p1.size();
	}
	void getRandom()       //�����ȡkeyֵ
	{
		map<int, T>::iterator it = p1.find((rand() % p1.size() + 1));
		cout << (*it).second << endl;
	}
	void get()   //��ӡĿǰRandomPool�е�keyֵ
	{
		for (map<int,string>::iterator it = p1.begin(); it != p1.end(); ++it)
		{
			cout << (*it).second << endl;
		}
	}
private:
	map<int, T>p1;
	map<T, int>p2;
	int index;
};
int main()
{
	srand((unsigned int)time(NULL));
	RandomPool<string>v;
	v.insert("���");
	v.insert("���");
	v.Delete("���");
	v.Delete("�Һ�");
	v.insert("���");
	v.insert("�Һ�");
	v.insert("��Һ�");
	v.Delete("�Һ�");
	v.get();
	v.getRandom();
	return 0;
}
