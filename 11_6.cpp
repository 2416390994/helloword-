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
//	int n;//�����С
//	cin >> n;
//	vector<int> v;
//	v.resize(n);//�����СΪn
//
//	//¼������
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//
//	//�Ҳ��岨��(����+����+1==���и��������ret��ʼ��Ϊ1)
//	int ret = 0;
//	for (int i = 1; i < n - 1; i++)
//	{
//		//���м�Ԫ�غ���������Ԫ�ش�С���Ƚϣ����iȡֵ�����n-2
//		if ((v[i - 1] <= v[i] && v[i] >= v[i + 1]) || (v[i - 1] >= v[i] && v[i] <= v[i + 1]))
//		{
//			ret++;//ÿ����һ��˵����һ������/����
//			//��������£�i-1,i,i+1λ�ö��жϹ����ˣ�Ӧ���ж�i+2λ���ˣ�
//			//��ʱ��i��λ�ã�����Ҫi��1һ�Σ�ѭ����ȥi�ټ�һ�Σ�����i+2�ˣ�
//			//��������i�����ȡֵ��i-2,��˵�i==n-3ʱ�����i��1һ����n-2,
//			//ѭ����ȥ�ټ�һ��1����n-1,Խ���ˣ���˵�i==n-3ʱ�����ټ�1
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
//	int n;//�����С
//	cin >> n;
//	vector<int> vec;
//	vec.resize(n);//�����СΪn
//
//	//¼������
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
///*�ʼ����ʹ�ò���Ͳ��ȵ��ص㣬����û�п��ǵ�����Ͳ��ȵļ����Ҫ����1
//*�������룺
//*4
//*1 3 2 3
//*�����2
//*Ӧ�����2������ʵ������Ľ����3*/
//
///*Ϊ�˱���a[i+1]Խ�磬�����鶨��Ϊn+1����a[n] = 0��
//*��0��n-1�������飬�ж�a[i]��a[i+1]��
//*����Ǵ��ڻ�С�ڣ�������+1��Ȼ������ƶ�ֱ����һ����
//*����ǵ��ڣ�ֻ����ƶ�*/
//int main()
//{
//	int n;
//	int i = 0;
//	while (cin >> n)
//	{
//		vector<int> a;
//		a.resize(n);//�������鳤��Ϊn+1����ֹa[i+1]����Խ��
//		long long num = 0;
//		for (i = 0; i < n; ++i)
//		{
//			cin >> a[i];
//		}
//		//a[n] = 0;
//		i = 1;
//		while (i<n)//��������
//		{
//			if (a[i] < a[i - 1])
//			{
//				while (i < n && a[i] <= a[i - 1]) //�ƶ�����ǰ����ĩβ
//					i++;
//				num++;//������+1
//				i++; //�ƶ�����һ����
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
//}����
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