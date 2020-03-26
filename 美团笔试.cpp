//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//void func()
//{
//	string s;
//	cin >> s;
//	vector<int> vec;
//	for (int i = 0; i < 9; ++i)
//	{
//		int a;
//		cin >> a;
//		vec.push_back(a);
//	}
//	string s1;
//	if (s[0] == '-')
//	{
//		s1 += '-';
//		for (int i = 1; i < s.size(); ++i)
//		{
//			s1 += (vec[s[i] - '0' - 1] + '0');
//		}
//		cout << s1 << endl;
//	}
//	else
//	{
//		for (int i = 0; i < s.size(); ++i)
//		{
//			s1 += (vec[s[i] - '0' - 1] + '0');
//		}
//		cout << s1 << endl;
//	}
//}
//
//
//int main()
//{
//
//	func();
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void func()
//{
//	int count;
//	while (cin >> count)
//	{
//
//		vector<double> vec;
//		for (int i = 0; i < count; ++i)
//		{
//			double b;
//			cin >> b;
//			vec.push_back(b);
//		}
//		vector<double> vec2;
//		for (int i = vec.size() - 1; i >= 0; --i)
//		{
//			double sum = 3.14159265 * vec[i] * vec[i];
//			vec2.push_back(sum);
//		}
//		double sum = 0;
//		for (int i = 0; i < vec2.size(); ++i)
//		{
//			if (i % 2 == 0)
//			{
//				sum += vec2[i];
//			}
//			else
//			{
//				sum -= vec2[i];
//			}
//		}
//		string f = to_string(sum);
//		string w;
//		int i = 0;
//		while (i < f.size() && f[i] != '.')
//		{
//			w += f[i];
//			i++;
//		}
//		w += '.';
//		i++;
//		int j = i;
//		for (; j < i + 4; ++j)
//		{
//			w += f[j];
//		}
//		if (f[j + 1] >= '5')
//			w += f[j] + 1;
//		else
//			w += f[j];
//
//		int ret = w.find('.');
//		int x = w.size() - ret - 1;
//		while (x < 5)
//		{
//			w += '0';
//			x++;
//		}
//
//		cout << w << endl;
//	}
//}
//
//int main()
//{
//	func();
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;
void func()
{
	int count;
	vector<int> vec;
	while (cin >> count)
	{
		for (int i = 0; i <count; ++i)
		{
			int a;
			cin >> a;
			vec.push_back(a);
		}
		size_t size = vec.size();
		int count = 0;
		for (int i = 0; i < size; ++i)
		{
			if (vec[i] % 1 == 0)
				count++;
		}
		cout << count << endl;
	}

}



int main()
{
	func();
	return 0;
}















