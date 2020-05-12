#include<iostream>
#include<unordered_map>
#include<unordered_multimap>
#include<string>
using namespace std;
void func()
{
	unordered_map<string, string> m;
	m.insert(pair<string, string>("及时雨", "松江"));
	m.insert(make_pair("及时雨2", "宋江"));

	//查看元素个数
	cout << m.size() << endl;

	//查看桶的个数
	cout << m.bucket_count() << endl;
	
	//查看第0号桶中的元素个数
	cout << m.bucket_size(0) << endl;

	//查看及时雨在哪个桶中
	cout << m.bucket("及时雨") << endl;
	cout << m.bucket("及时雨2") << endl;


	//试试随机访问运算符[]
	cout << m["及时雨"] << endl;
	cout << m.size() << endl;

	//[]:如果key不存在，<key,默认value>构建一个键值对，然后将其插入到容器中，返回默认的value,vs2013返回空
	cout << m["董晨辉"] << endl;
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