//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0x12345678;
//	char* b = (char*)&a;
//	printf("%x\n", *b);
//	printf("%x\n", *(b + 1));
//	
//
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<time.h>
//#include<stdlib.h>
//using namespace std;
//void sort1(vector<int>& a)
//{
//	int size = a.size();
//	for (int i = 0; i < size - 1; ++i)
//	{
//		for (int j = 0; j < size - i - 1; ++j)
//		{
//			if (a[j] >a[j + 1])
//				swap(a[j], a[j + 1]);
//		}
//	}
//}
//void sort2(vector<int>& a)
//{
//	int size = a.size();
//	for (int i = 0; i < size - 1; ++i)
//	{
//		int max = i;
//		for (int j = i + 1; j < size; ++j)
//		{
//			if (a[max] < a[j])
//				max = j;
//		}
//		swap(a[i], a[max]);
//	}
//}
//void sort3(vector<int>& a)
//{
//	int size = a.size();
//	for (int i = 0; i < size; ++i)
//	{
//		for (int j = i; j >0 && a[j] > a[j - 1]; --j)
//		{
//			swap(a[j], a[j - 1]);
//		}
//	}
//}
//void sort4(vector<int>& a)
//{
//	int size = a.size();
//	int gas = size / 2;
//	while (gas >= 1)
//	{
//		for (int i = gas; i < size; i+=gas)
//		{
//			for (int j = i; j > 0 && a[j] > a[j - gas]; j-=gas)
//			{
//				swap(a[j], a[j - gas]);
//			}
//		}
//		gas = gas >> 1;
//	}
//}
//void sort5(vector<int>& a)
//{
//	int size = a.size();
//	if (size <= 0)
//		return;
//	for (int i = 1; i < size; ++i)
//	{
//		int left = i;
//		while (left > 0)
//		{
//			if (a[left] > a[(left - 1) / 2])
//				swap(a[left], a[(left - 1) / 2]);
//			left = (left - 1) / 2;
//		}
//	}
//	while (size > 0)
//	{
//		swap(a[0], a[--size]);
//		int index = 0;
//		int left = index * 2 + 1;
//		while (left < size)
//		{
//			int length = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;
//			length = a[index] > a[length] ? index : length;
//			if (index == length)
//				break;
//			swap(a[index], a[length]);
//			index = length;
//			left = index * 2 + 1;
//		}
//	}
//}
//int* sort6(vector<int>& a,int L,int R)
//{
//	int less = L - 1;
//	int right = R;
//	while (L < right)
//	{
//		if (a[L] > a[R])
//		{
//			swap(a[L], a[--right]);
//		}
//		else if (a[L] < a[R])
//		{
//			swap(a[L++], a[++less]);
//		}
//		else
//			L++;
//	}
//	swap(a[R], a[right]);
//	return new int[]  { less, right + 1 };
//}
//void sort7(vector<int>& a,int L,int R)
//{
//	srand((unsigned int)time(NULL));
//	if (L < R)
//	{
//		swap(a[L + (rand() % (R - L) + 1)], a[R]);
//		int *b = sort6(a, L, R);
//		sort7(a, L, b[0]);
//		sort7(a, b[1], R);
//	}
//}
//int main()
//{
//	vector<int> a = { 5, 9, 1, 6, 7, 8, 4, 2, 3, 0 };
//	//sort1(a);
//	//sort2(a);
//	//sort3(a);
//	//sort4(a);
//	///sort5(a);
//	sort7(a,0,a.size() - 1);
//
//	for (int i = 0; i < a.size(); ++i)
//	{
//		cout << a[i] << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	map<int, string> mymap;
	mymap.insert(make_pair(1, "���ǵ�һ��"));
	mymap.insert(make_pair(5, "���ǵ����"));
	mymap.insert(make_pair(3, "���ǵ�����"));
	mymap.insert(make_pair(2, "���ǵڶ���"));
	mymap.insert(make_pair(4, "���ǵ��ĸ�"));
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
	{
		cout << (*it).first <<"======>>"<< (*it).second << endl; 
	}
	mymap[1] = "���ǵ�ʮ��";
	for (auto it = mymap.begin(); it != mymap.end(); ++it)
	{
		cout << (*it).first << "======>>" << (*it).second << endl;
	}
	return 0;
}
//proot->left = prev
//if (prev)
//prev->right = proot
//prev = proot
//
/*
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //1.[] 2.find insert 3.insert
        map<string,int> countmap; 
        //���ַ���������ĸ˳�����򣬲�ͳ�Ƴ��ַ������ֵĴ���                
        for(auto& e : words)
            countmap[e]++;
        
        multimap<int,string,greater<int>> sortmap;//���ִ���Ϊkey���ַ���Ϊvalue
        //���ճ��ִ����Ӵ�С��������
        for(const auto& kv:countmap)
        {
            sortmap.insert(make_pair(kv.second,kv.first));
        }
        
        vector<string> v;
        multimap<int,string>::iterator it = sortmap.begin();
        while(it != sortmap.end() && k--)
        //�����ź����mapȡ��ǰk������Ƶ����ߵ��ַ�������vector��
        {
            v.push_back(it->second);
            ++it;
        }        
        return v;  
    }
};

*/