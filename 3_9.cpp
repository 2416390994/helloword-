////#include<iostream>
////#include<string>
////using namespace std;
////int main()
////{
////	string str;
////	while (getline(cin, str))
////	{
////		int i = 0;
////		for (int j = str.size() - 1; j >= 0; --j)
////		{
////			if (str[j] == ' ')
////			{
////				break;
////			}
////			i++;
////		}
////		cout << i << endl;
////		i = 0;
////		str.clear();
////	}
////
////
////}
//
//#include<string>
//#include<vector>
//#include<iostream>
//using namespace std;
//int main()
//{
//
//	string str;
//	while(getline(cin, str))
//	{
//		char a;
//		cin >> a;
//		int count = 0;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (str[i] == a)
//				count++;
//			else if ('a' <= str[i] && str[i] <= 'z')
//			{
//				if (str[i] - 32 == a &&  'A' <= a && a <= 'Z')
//					count++;
//			}
//			else if ('A' <= str[i] && str[i] <= 'Z')
//			{
//				if (str[i] + 32 == a && 'a' <= a && a <= 'z')
//					count++;
//			}
//		}
//		cout << count << endl;
//	}
//
//	return 0;
//}
//
////#include<iostream>  
////#include<cstring>  
////using namespace std;
////
////// 将小写字母转换为大写字母
////void change(char *str)
////{
////	int i;
////	for (i = 0; str[i] != '\0'; i++)
////	{
////		if (str[i] >= 'a'&&str[i] <= 'z')
////			str[i] = str[i] - 32;
////	}
////}
////
////int main()
////{
////	char str[512], ch;
////	int i, count = 0, length = 0;
////	cin.getline(str, 512);
////	cin.get(ch);
////	length = strlen(str);
////	change(str);
////	//要求统计的字符是字母，注意大小写  
////	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A' || ch <= 'Z'))
////	{
////		//待统计的字符为小写，转换成大写，后面可与字符串中的统一比较不再区分大小写  
////		if (ch >= 'a'&&ch <= 'z')
////			ch = ch - 32;
////		for (i = 0; i<length; i++)
////		{
////			if (str[i] == ch)
////				count++;
////		}
////	}
////	//其他字符直接判断即可  
////	else
////	{
////		for (i = 0; i<length; i++)
////		if (str[i] == ch)
////			count++;
////	}
////	cout << count << endl;
////	return 0;
////}
////
////
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s;
//	char c;
//	int num = 0;
//	while (cin >> s)
//	{
//		cin >> c;
//		if (s.size() == 0)
//			cout << 0 << endl;
//		for (int i = 0; i<s.size(); ++i)
//		{
//			if (s[i] == c || (s[i] + 32) == c)
//				num++;
//		}
//	}
//	cout << num << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	long long a;
//	int s;
//	while (cin >> a)
//	{
//		for (int i = 2; i <= a; ++i)
//		{
//			while (a % i == 0)
//			{
//				cout << i << " ";
//				a = a / i;
//			}
//		}
//	}
//
//
//	return 0;
//}

//#include<string>
//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//int main()
//{
//	/*string s;
//	cin >> s;
//	cout << s << endl;*/
//	//string a;
//	int w = 10;
//	string p = to_string(w);
//	cout << p << endl;
//	//int a = atoi(s.c_str());
//	/*int line;
//	cin >> line;
//
//	map<int, int> mmap;
//	for (int i = 0; i < line; ++i)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (mmap.find(a) != mmap.end())
//		{
//			int c = mmap.find(a)->second;
//			mmap.erase(a);
//			mmap.insert(make_pair(a, c + b));
//		}
//		else
//			mmap.insert(make_pair(a, b));
//	}
//	for (auto e : mmap)
//		cout << e.first << " " << e.second << endl;
//	return 0;*/
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	/*int array[10] = { 0 };*/
//	int a = 10;
//	cin >> a;
//	char str[10];
//	_itoa(a,str,2);
//	cout << str << endl;
//	//reverse(b.begin(),b.end());
//	//string count;
//	//for (int i = 0; i < b.size(); ++i)
//	//{
//	//	if (array[b[i] - 48] == 0)
//	//	{
//	//		count += b[i];
//	//		array[b[i] - 48] = 1;
//	//	}
//	//}
//	////reverse(count.begin(), count.end());
//	//cout << atoi(count.c_str()) << endl;
//
//
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string s;
//	getline(cin, s);
//	int count = 0;
//	for (int i = 0; i <s.size(); ++i)
//	{
//		if (0 <= s[i] && s[i] <= 127)
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//int main()
//{
//	string s;
//	stack<string> sta;
//	getline(cin, s);
//	string b;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (s[i] != ' ')
//			b += s[i];
//		else
//		{
//			sta.push(b);
//			b.clear();
//		}
//	}
//	sta.push(b);
//	while (sta.size() > 1)
//	{
//		cout << sta.top() << " ";
//		sta.pop();
//	}
//	cout << sta.top() << endl;
//	return 0;
//}




