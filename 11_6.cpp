//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string i;
//	string s;
//	vector<long long> vec;
//	long long res = 0;
//	long long a = 0;
//	long long count = 0;
//	getline(cin, i);
//	getline(cin, s);
//	long long  b = atoi(i.c_str());
//	for (long long i = 0; i < s.size(); ++i)
//	{
//		if (s[i] != ' ')
//		{
//			a = a * 10 + s[i] - '0';
//		}
//		else
//		{
//			vec.push_back(a);
//			a = 0;
//		}
//	}
//	cout << vec.size() << endl;
//	sort(vec.begin(), vec.end());
//	for (int i = vec.size() - 2; count < b; ++count, i = i - 2)
//	{
//		res += vec[i];
//	}
//	cout << res << endl;
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1;
//	string s2;
//	getline(cin,s1);
//	getline(cin,s2);
//	char a[300];
//	for (int i = 0; i < s2.size(); ++i)
//	{
//		if (s2[i] != ' ')
//		{
//			if (a[s2[i]] != 1)
//			{
//				a[s2[i]] = 1;
//			}
//		}
//	}
//	string s3;
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		if (a[s1[i]] != 1)
//			s3 += s1[i];
//	}
//	cout << s3 << endl;
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int order_count()
//{
//	int n;//数组大小
//	cin >> n;
//	vector<int> v;
//	v.resize(n);//数组大小为n
//
//	//录入数据
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//
//	//找波峰波谷(波峰+波谷+1==序列个数，因此ret初始化为1)
//	int ret = 0;
//	for (int i = 1; i < n - 1; i++)
//	{
//		//以中间元素和左右两个元素大小作比较，因此i取值最大是n-2
//		if ((v[i - 1] <= v[i] && v[i] >= v[i + 1]) || (v[i - 1] >= v[i] && v[i] <= v[i + 1]))
//		{
//			ret++;//每进来一次说明有一个波峰/波谷
//			//正常情况下，i-1,i,i+1位置都判断过来了，应该判断i+2位置了，
//			//此时是i的位置，则需要i加1一次，循环上去i再加一次，就是i+2了，
//			//但是由于i的最大取值是i-2,因此当i==n-3时，如果i加1一次是n-2,
//			//循环上去再加一次1就是n-1,越界了，因此当i==n-3时无需再加1
//			if (i != n - 3)
//			{
//				i++;
//			}
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int n;//数组大小
//	cin >> n;
//	vector<int> vec;
//	vec.resize(n);//数组大小为n
//
//	//录入数据
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vec[i];
//	}
//	//int count = 1;
//	//for (int k = 1; k< vec.size() - 1; k++)
//	//{
//	//	if (((vec[k] >= vec[k - 1]) && (vec[k] >= vec[k + 1])) || ((vec[k] <= vec[k - 1]) && (vec[k] <= vec[k + 1])))
//	//	{
//	//		count++;
//	//		if (k != vec.size() - 2)
//	//		{
//	//			++k;
//	//		}
//	//	}
//	//}
//	//cout << count << endl;
//	cout << order_count() << endl;
//	return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
///*最开始考虑使用波峰和波谷的特点，但是没有考虑到波峰和波谷的间距需要大于1
//*比如输入：
//*4
//*1 3 2 3
//*输出：2
//*应该输出2，但是实际输出的结果是3*/
//
///*为了避免a[i+1]越界，将数组定义为n+1个，a[n] = 0；
//*从0到n-1遍历数组，判断a[i]和a[i+1]：
//*如果是大于或小于，序列数+1，然后向后移动直到下一序列
//*如果是等于，只向后移动*/
//int main()
//{
//	int n;
//	int i = 0;
//	while (cin >> n)
//	{
//		vector<int> a;
//		a.resize(n);//设置数组长度为n+1来防止a[i+1]访问越界
//		long long num = 0;
//		for (i = 0; i < n; ++i)
//		{
//			cin >> a[i];
//		}
//		//a[n] = 0;
//		i = 1;
//		while (i<n)//遍历数组
//		{
//			if (a[i] < a[i - 1])
//			{
//				while (i < n && a[i] <= a[i - 1]) //移动到当前序列末尾
//					i++;
//				num++;//序列数+1
//				i++; //移动到下一序列
//			}
//			else if (a[i] == a[i - 1])
//			{
//				while (i < n && a[i] == a[i - 1])
//				{
//					i++;
//				}
//				num++;
//				i++;
//			}				
//			else
//			{
//				while (i < n && a[i] >= a[i - 1])
//					i++;
//				num++;
//				i++;
//			}
//		}
//		cout << num << endl;
//	}
//	return 0;
////}
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int main()
//{
//
//	char a[] = "123456";
//	a[0] = '9';
//	cout << a << endl;
//	string s1;	
//	vector<string> vec;
//	string s2;
//	getline(cin, s1);
//	for (int i = 0; i<s1.size(); ++i)
//	{
//	
//		while (s1[i] != ' ' && i < s1.size())
//		{
//			s2 += s1[i];
//			i++;
//		}
//		vec.push_back(s2);
//		s2.clear();
//	}
//	for (int i = vec.size() - 1; i >0; --i)
//	{
//		cout << vec[i];
//		cout << ' ';
//	}
//	cout << vec[0];
//	return 0;
//}回收
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int func()
{
	int i, j, k = 1;
	for (i = 0, j = -1; j = 1; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	cout << func() << endl;
	return 0;
}