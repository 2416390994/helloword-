#include<iostream>
#include<string>
using namespace std;
int main()
{
	//构造函数
	string a;     //string () 无参构造函数
	string b("你好");   //string (const char *s);
	string c(b);    //string (const string & str)
	string d("abcdefg", 5);   //string (const char* s,size_t c) 相当于字符串的截断，第一个参数代表要截断的字符串，第二个参数代表需要截除多少个字符
	string e(10, 'c');  //string (size_t c, char s)  // 将第二个参数复制第一个参数次
	string f(e, 2, 5);//string (const string& str, size_t pos, size_t len = npos);  第一个参数对象的字符串从第二个参数开始向后截取第三个参数位
	string g(10, 42);    //用ASCII来实现e的作用，42就是*
	//=号运算符的重载
	string _1 = "abcdefg";
	string _2 = _1;
	//string _4 = 'x';   初始化和定义不可以写在同一行，不然就会以为是构造函数，构造函数不存在单字符构造
	string _3;
	_3 = 'x';
	//迭代器
	string _1_ = "hello world";    // string::begin,以及string::end
	for (auto it = _1_.begin(); it != _1_.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	string _2_ = "hello world";   //string::rbegin,string::rend
	for (auto it = _2_.rbegin(); it != _2_.rend(); ++it)
	{
		cout << *it;
	}
	cout << endl;
	//容量
	cout << _2_.max_size() << endl;
	cout << _2_.length() << endl;
	cout << _2_.size() << endl;
	cout << _2_.capacity() << endl;
	string _3_ = "hello world";
	_3_.resize(20,' ');
	_3_.reserve(48);   //reserve就是预留空间的意思，防止在写入的过程中反复的开辟内存，这里的意思是先开辟48个空间，如果预留的长度小于原长度则保持不变
	cout << _3_.capacity() << endl;
	_3_.clear();    //只会清空字符但是不会释放空间
	cout << _3_.capacity() << endl;
	cout << _3_;
	cout << _3_.empty() << endl;   //判断字符串是不是为空，为空的话就返回1，不为空返回0
	//元素访问操作符
	string _a = "hello world";
	cout << _a[10] << endl;
	cout << _a.at(10) << endl;
	_a.back() = '!';  //给末尾添加一个元素
	cout<<_a<<endl;
	_a.front() = 'T';//将首部元素进行替换
	cout<<_a<<endl;
	//修饰符
	string _b = "hello world";
	string _c = " red small";
	_b += " shell";
	_b += _c;
	_b += 'w';
	cout<<_b<<endl;
	//append
	string _d = "windows is next globle";
	string _e = "doeat list cow pow";
	string _f;
	_f.append(_d);
	_f.append(_d, 7, 9);  //从第几个开始截取几个
	_f.append(10,'.');
	_f.append(" good", 5);
	_f.append("小花");
	_f.append(_e.begin() + 6, _e.end()-6);
	cout << _f << endl;
	//push_back
	string _a_ = "hello world";
	_a_.push_back('c');   //追加，和.back()一样
	cout << _a_ << endl;
	//赋值,感觉没毛用
	string _b_ = "hello world";
	string _c_;
	_c_.assign(_b_);
	//insert
	string _d_ = "hello world";
	_d_.insert(11, 10, 'x');  ///有关insert的所有函数的第一个参数都是下标索引号，表示从第几个开始插入，迭代器指针也可以，代表要插入的位置的指针
	cout << _d_ << endl;
	//erase
	//swap
	string __1 = "hiauhciu";
	string __2 = "dhaeuihcuiaeh";
	__1.swap(__2);
	cout << __1 << endl << __2 << endl;
	//pop_back
	//getline
	string _str;
	getline(cin, _str);
	cout << _str << endl;
	string str1 = "你好";
	string str2 = "世界";
	string str4;
	str4 = 'w';
	string str5;
	str5 = 'c';
	string str3 = str1 + str2 + str4;
	cout << str3 << endl;
	string s = str4 + str5;
	s[0] = 'W';
	string ____a = "steing";
	string _a_a = "hello world 我的眼睛好涨";
	//---------------------------------------------------------------
	int ret = _a_a.find("world",0,5);   //从_a_a的第0个下标开始，找"world"的前五个单词
	cout << ret << endl;
	//----------------------------------------------------------------------
	cout << s << endl;
	return 0;
}

# if 0
#include <iostream>
#include <string>

int main()
{
	std::string str1, str2, str3;
	str1 = "Test string: ";   // c-string
	str2 = 'x';               // single character
	str3 = str1 + str2;       // string

	std::cout << str3 << '\n';
	return 0;
}
#endif