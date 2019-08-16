//设计RandomPool结构
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
	RandomPool()         //初始化index
	{
		this->index = 0;
	}
	void insert(T key)   //插入key
	{
		if (p2.find(key) != p2.end() && index != 0)    //判断插入的值是否存在
		{
			cout << "此值已存在,无法插入" << endl;
			return;
		}
		else
		{
			cout << "插入成功" << endl;
			index++;
			p1.insert(make_pair(index, key));
			p2.insert(make_pair(key, index));
		}		
	}
	void Delete(T key)         //删除key值
	{
		if (p2.find(key) == p2.end())
		{
			cout << "此键值不存在" << endl;
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
	int getindex()           //获取现在RandomPool结构中的index
	{
		return index;
	}
	int getsize()          //获取RandomPool结构的长度
	{
		return p1.size();
	}
	void getRandom()       //随机获取key值
	{
		map<int, T>::iterator it = p1.find((rand() % p1.size() + 1));
		cout << (*it).second << endl;
	}
	void get()   //打印目前RandomPool中的key值
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
	v.insert("你好");
	v.insert("你好");
	v.Delete("你好");
	v.Delete("我好");
	v.insert("你好");
	v.insert("我好");
	v.insert("大家好");
	v.Delete("我好");
	v.get();
	v.getRandom();
	return 0;
}
