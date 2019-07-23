#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
void test01()
{
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 2);
	}
	vector<int>v1;
	v1.resize(v2.size());
	copy(v2.begin(), v2.end(), v1.begin());
	for_each(v1.begin(), v1.end(), [](int val){cout << val << " "; });
}

bool func1(int a)
{
	return a > 9;
}
class func:public binary_function<int ,int,bool>
{
public:
	bool operator()(int a,int num) const
	{
		return a > num;
	}

};
void test02()
{
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 2);
	}
	//�������е�3�滻��300
	replace(v2.begin(), v2.end(), 3,300);
	for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
	cout << endl;
	//�����������д���9�����滻��100
	replace_if(v2.begin(), v2.end(), func1,100);
	for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
	cout << endl;
	//�����������д���9�����滻��100(�û��ֶ�����)
	int num;
	cin >> num;
	replace_if(v2.begin(), v2.end(), bind2nd(func(),num), 100);
	for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
}
void test03()
{
	vector<int>v1;
	for (int i = 0; i < 5; ++i)
	{
		v1.push_back(i + 2);
	}
	cout << "v1��size:" << v1.size() << endl;
	cout << "v1��capacity:" << v1.capacity() << endl;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v2.push_back(i + 2);
	}
	cout << "v2��size:" << v2.size() << endl;
	cout << "v2��capacity:" << v2.capacity() << endl;
	swap(v1, v2);
	cout << "������" << endl;
	cout << "v1��size:" << v1.size() << endl;
	cout << "v1��capacity:" << v1.capacity() << endl;
	cout << "v2��size:" << v2.size() << endl;
	cout << "v2��capacity:" << v2.capacity() << endl;
}
int main()
{
	test03();
	return 0;
}