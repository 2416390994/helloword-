#include<iostream>
#include<string>
using namespace std;
int main()
{
	//���캯��
	string a;     //string () �޲ι��캯��
	string b("���");   //string (const char *s);
	string c(b);    //string (const string & str)
	string d("abcdefg", 5);   //string (const char* s,size_t c) �൱���ַ����Ľضϣ���һ����������Ҫ�ضϵ��ַ������ڶ�������������Ҫ�س����ٸ��ַ�
	string e(10, 'c');  //string (size_t c, char s)  // ���ڶ����������Ƶ�һ��������
	string f(e, 2, 5);//string (const string& str, size_t pos, size_t len = npos);  ��һ������������ַ����ӵڶ���������ʼ����ȡ����������λ
	string g(10, 42);    //��ASCII��ʵ��e�����ã�42����*
	//=�������������
	string _1 = "abcdefg";
	string _2 = _1;
	//string _4 = 'x';   ��ʼ���Ͷ��岻����д��ͬһ�У���Ȼ�ͻ���Ϊ�ǹ��캯�������캯�������ڵ��ַ�����
	string _3;
	_3 = 'x';
	//������
	string _1_ = "hello world";    // string::begin,�Լ�string::end
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
	//����
	cout << _2_.max_size() << endl;
	cout << _2_.length() << endl;
	cout << _2_.size() << endl;
	cout << _2_.capacity() << endl;
	string _3_ = "hello world";
	_3_.resize(20,' ');
	_3_.reserve(48);   //reserve����Ԥ���ռ����˼����ֹ��д��Ĺ����з����Ŀ����ڴ棬�������˼���ȿ���48���ռ䣬���Ԥ���ĳ���С��ԭ�����򱣳ֲ���
	cout << _3_.capacity() << endl;
	_3_.clear();    //ֻ������ַ����ǲ����ͷſռ�
	cout << _3_.capacity() << endl;
	cout << _3_;
	cout << _3_.empty() << endl;   //�ж��ַ����ǲ���Ϊ�գ�Ϊ�յĻ��ͷ���1����Ϊ�շ���0
	//Ԫ�ط��ʲ�����
	string _a = "hello world";
	cout << _a[10] << endl;
	cout << _a.at(10) << endl;
	_a.back() = '!';  //��ĩβ���һ��Ԫ��
	cout<<_a<<endl;
	_a.front() = 'T';//���ײ�Ԫ�ؽ����滻
	cout<<_a<<endl;
	//���η�
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
	_f.append(_d, 7, 9);  //�ӵڼ�����ʼ��ȡ����
	_f.append(10,'.');
	_f.append(" good", 5);
	_f.append("С��");
	_f.append(_e.begin() + 6, _e.end()-6);
	cout << _f << endl;
	//push_back
	string _a_ = "hello world";
	_a_.push_back('c');   //׷�ӣ���.back()һ��
	cout << _a_ << endl;
	//��ֵ,�о�ûë��
	string _b_ = "hello world";
	string _c_;
	_c_.assign(_b_);
	//insert
	string _d_ = "hello world";
	_d_.insert(11, 10, 'x');  ///�й�insert�����к����ĵ�һ�����������±������ţ���ʾ�ӵڼ�����ʼ���룬������ָ��Ҳ���ԣ�����Ҫ�����λ�õ�ָ��
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
	string str1 = "���";
	string str2 = "����";
	string str4;
	str4 = 'w';
	string str5;
	str5 = 'c';
	string str3 = str1 + str2 + str4;
	cout << str3 << endl;
	string s = str4 + str5;
	s[0] = 'W';
	string ____a = "steing";
	string _a_a = "hello world �ҵ��۾�����";
	//---------------------------------------------------------------
	int ret = _a_a.find("world",0,5);   //��_a_a�ĵ�0���±꿪ʼ����"world"��ǰ�������
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