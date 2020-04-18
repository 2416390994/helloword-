#include<iostream>
#include<string>
#include<vector>
using namespace std;
//void func1(string s)
//{
//	size_t size = s.size();
//	int i;
//	for (i = 0; i < size; ++i)
//	{
//		int a = s.find(' ',i);
//		int w = a - 1;
//		while (i < w)
//		{
//			swap(s[i], s[w]);
//			i++;
//			w--;
//		}
//		if (a == -1)
//			break;
//		i = a;
//	}
//	--i;
//	while (i < size)
//	{
//		swap(s[i], s[size]);
//		i++;
//		size--;
//	}
//	reverse(s.begin(), s.end());
//	cout << s << endl;
//}
//
//int main()
//{
//	func1("i am a students.");
//	return 0;
//}