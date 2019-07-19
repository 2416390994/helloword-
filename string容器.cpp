#if 0
#include<iostream>
using namespace std;
#include<string>
void test()
{
	//string();  //string 就是一个类，然后string()就相当于string  p1()但是没有初始化
	//string p4("万绍");    //使用一个字符串来初始化
	//string p2(10, 'c');         //用字符c初始化n个字符，
	//string p1("康熙");      
	//string p3(p1);      
	//cout << p2 << endl;
	//cout << p3 << endl;
	string p1;     //定义一个空字符串
	char *c = "吃了吗"; 
	p1 = c;   //用char* 类型的字符串赋值给p1
	string b = "袁绍";
	p1 = b;      //用string类型数组初始化p1;
	char c = 'd';
	p1 = c;    //用字符初始化
	///////////////////////////////////////////////////
	string p2;
	char *c = "helloworld";
	p2.assign(c);
	p2.assign(c, 5);
	p2.assign(2, 'c');
	string p3("good morning");
	p2.assign(p3, 3, 5); //把p3从第3个字符开始之后的5个字符，赋值给p2

}
#endif
#if 0
#include<iostream>
#include<stdexcept>
using namespace std;
//string 存取字符操作
//char& operator[](int n)  通过[]存取字符串里面的数据
//char& at(int n)   通过函数存取字符串里面的数据
void test()
{
	string p("helloworld");
	for (int i = 0; i <p.size() ; ++i)
	{
		cout << p[i] << endl;
	}
}
void test2()
{
	string p("helloworld");
	for (int i = 0; i < p.size(); ++i)
	{
		cout << p.at(i);
	}
}
//[]和at存取数据到底有没有什么区别呢？有的
//区别就是[]不会抛出异常而是直接挂掉，at会抛出异常等待处理
//void test3()
//{
//	string p = "helloworld";
//	try
//	{
//		cout << p[100] << endl;
//	}
//	catch (out_of_range&e)
//	{
//
//		cout << e.what() << endl;
//	}
//
//}
void test4()
{
	string p = "helloworld";
	try
	{
		cout << p.at(100) << endl;
	}
	catch (out_of_range&e)
	{

		cout << e.what() << endl;
	}

}
int main()
{
	test();
	test2();
	test4();
	return 0;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
void test1()
{
	string p1 = "老鼠";
	string p2 = "爱大米";
	p1 += p2;
	cout << p1 << endl;
	/////////////////////////////////
	char* p3 = "老鼠";
	char* p4 = "爱大米";
	string p;                //最后必须用string类型的变量进行接收
	p += p3;
	p += p4;
	cout << p << endl;
	//////////////////////
	string pp;
	char a = 'a';
	char b = 'b';
	pp += a;
	pp += b;
	cout << pp << endl;
}
#endif
#if 0
#include<iostream>
#include<string>
using namespace std;
void test1()
{
	string p("请叫我");
	char* p1("女王大人");
	p.append(p1);
	cout << p << endl;
	//////////////////////////
	string pp("请叫我");
	char* pp1("女王大人");
	pp.append(pp1, 4); //将前四个字符连接到pp上
	cout << pp << endl;
}
//太多了不写了不写了😤
#endif
#if 0
void test1()
{
	string p("abcdef");
	//string& find(const string& str,int pos = 0)   pos默认参数，可以不给不给的话就从第0号元素去找，成功就返回找到的第一个元素的下标，没找到就返回-1
	int pos = p.find("bc");
	cout << pos << endl;
	int post2 = p.rfind("bc");      //r.find()是从右到左进行查找 ，给返回的是最后一个元素出现的位置
	cout << post2 << endl;
}
void test2()
{
	//string& replace(int pos,int n,const string&str) 用str字符串替换从pos开始的n个字符
	string p("hello");
	p.replace(1, 3, "woc");
	cout << p << endl;
}
#endif
#if 0
//compare比较的时候> 返回1 ，<返回-1,=返回0
void test2()
{
	string p1("ab");
	string p2("abc");
	if (p1.compare(p2) == 0)
	{
		cout << "相等" << endl;
	}
	else if (p1.compare(p2) > 0)
	{

		cout << "p1 > p2" << endl;
	}
	else if (p1.compare(p2) < 0)
	{
		cout << "p1 < p2" << endl;
	}
}
#endif
#if 0
//string子串  string substr(int pos = 0,int n =npos)const 返回由pos开始的n个字符组成的字符串
void test2()
{
	string p1("abcdef");
	string p2 = p1.substr(1, 3);        //从第一个字符开始跨过后面的3个字符，返回剩下的字符
	cout << p2 << endl;        //bcd
	//////////////////////////////////////////////
	string p3("http//:2416390994@qq.com");
	int pos = p3.find('@');    
	int post = p3.find(':');
	string p4 = p3.substr(post + 1,pos-post-1);      //输出从：开始后面pos-post-1（数字长度）长度的字符
	cout << p4 << endl;
}
#endif
#if 0
void test2()
{
	string p1("hello");
	p1.insert(1, "123456");
	cout << p1 << endl;       //结果h123456ello
	p1.erase(1, 3);//从第一个开始删，删三个字符
	cout << p1 << endl;             //结果h456ello
}
#endif
#if 0
void func1(string  s)
{
	cout << s << endl;
}
void func2(const char* s)
{
	cout << s << endl;
}
void test2()
{
	string p("abc");
	const char* s = p.c_str();   //.c_str()之后类型为const char* 
	cout << s << endl;
	string p1(s);       //这一步转换直接用的是string类内部的构造函数
	cout << p1 << endl;
//////////////////////////////////////////////////////////////////////////////////////////
	//隐式类型转换
	string s2(p1);
	char* name("abcd");
	func1(name);        //void func1(string s),进行了隐式类型转换，char* 可以转为string
	//func2(s2);        但是 void func2(const char* s) 无法转变成char*
}
#endif
#include<iostream>
#include<string>
using namespace std;
void test2()
{
	string p("abcDEfGh");
	for (int i = 0; i < p.size(); ++i)
	{
		p[i] = toupper(p[i]);            //变成大写
	}
	cout << p << endl;
	for (int i = 0; i < p.size(); ++i)
	{
		p[i] = tolower(p[i]);        //变成小写
	}
	cout << p << endl;
}
int main()
{
	test2();
	return 0;
}

