#include<iostream>
#include<vector>
using namespace std;
//////√∞≈›≈≈–Ú
////void sort_1(int *a,int length)
////{
////	for (int i = 0; i < length - 1; ++i)
////	{
////		for (int j = 0; j < length - 1 - i; ++j)
////		{
////			if (a[j+1]>a[j])
////			{
////				swap(a[j+1], a[j]);
////			}
////		}
////	}
////}
//////—°‘Ò≈≈–Ú
////void sort_2(int *a, int length)
////{
////	for (int i = 0; i < length - 1; ++i)
////	{
////		int max = i;
////		for (int j = i + 1; j < length; ++j)
////		{
////			if (a[max] < a[j])
////				max = j;
////		}
////		swap(a[i], a[max]);
////	}
////}
//////√∞≈›≈≈–Ú
////void sort_1(int *a, int length)
////{
////	for (int i = 0; i < length - 1; ++i)
////	{
////		for (int j = 0; j < length - 1 - i; ++j)
////		{
////			if (a[j] < a[j + 1])
////				swap(a[j], a[j + 1]);
////		}
////	}
////
////}
//////—°‘Ò≈≈–Ú
////void sort_2(int *a, int length)
////{
////	for (int i = 0; i < length - 1; ++i)
////	{
////		int max = i;
////		for (int j = i + 1; j < length; ++j)
////		{
////			if (a[max] < a[j])
////				max = j;
////		}
////		swap(a[max], a[i]);
////	}
////}
////≤Â»Î≈≈–Ú
////void sort_3(int *a,int length)
////{
////	for (int i = 1; i < length; ++i)
////	{
////		for (int j = i; j>0&&a[j]>a[j-1]; --j)
////		{
////			swap(a[j], a[j - 1]);
////		}
////	}
////}
////œ£∂˚≈≈–Ú
//void sort_4(int *a, int length)
//{
//	int ges = length;
//	while (ges > 1)
//	{
//		ges = ges / 3 + 1;
//		for (int i = ges; i < length; i +=ges )
//		{
//			for (int j = i; j>0 && a[j] > a[j - ges]; j -=ges)
//			{
//				swap(a[j], a[j - ges]);
//			}
//		}
//	}
//}
////∂—≈≈–Ú
////≈≈–Ú
////void heapsort(int *a,int index, int length)
////{
////	int left = index * 2 + 1;
////	while (left < length)
////	{
////		int larger = left + 1 && a[left+1]<a[left] ? left+1 : left;
////		larger = a[index] > a[larger] ? larger : index;
////		if (index == larger)
////			break;
////		swap(a[larger], a[index]);
////		index = larger;
////		left = index * 2 + 1;
////	}
////}
////void heapsort(int *a, int index, int length)
////{
////	int left = index * 2 + 1;
////	while (left < length)
////	{
////		int larger = left + 1< length && a[left + 1] < a[left] ? left + 1 : left;
////		larger = a[index] > a[larger] ? larger : index;
////		if (index == larger)
////			break;
////		swap(a[larger], a[index]);
////		index = larger;
////		left = index * 2 + 1;
////	}
////}
//////Ω®∂—
////void sort_5(int *a, int length)
////{
////	int size = length;
////	if (a == nullptr || length < 2)
////		return;
////	for (int i = 0; i < size; ++i)
////	{
////		while (a[i]<a[(i - 1) / 2])
////		{
////			swap(a[i], a[(i - 1) / 2]);
////			i = (i - 1) / 2;
////		}
////	}
////	while (size > 0)
////	{
////		swap(a[0], a[--size]);
////		heapsort(a, 0,size);
////
////	}
////}
//void flagquestion(int *a,int L,int R)
//{
//	int less = L - 1;
//	int right = R;
//	while (L < right)
//	{
//		if (a[L]>a[R])
//			swap(a[L], a[--right]);
//		else if (a[L] < a[R])
//			swap(a[++less], a[L++]);
//		else
//			L++;
//	}
//	swap(a[R], a[right]);
//}
//struct a_b
//{
//	int a;
//	int b;
//};
//a_b  flagquestion(int *a, int L, int R)
//{
//	int less = L - 1;
//	int right = R;
//	while (L < right)
//	{
//		if (a[L] < a[R])
//			swap(a[L++], a[++less]);
//		else if (a[L]>a[R])
//		{
//			swap(a[L], a[--right]);
//		}
//		else
//			L++;
//	}
//	//swap(a[R], a[L]);
//	swap(a[R], a[right]);
//	a_b c;
//	c.a = less;
//	c.b = right+1;
//	return c;
//}
//void sort_6(int *a,int L,int R)
//{
//	if (L < R)
//	{
//		swap(a[L + rand() % (R - L) + 1], a[R]);
//		a_b c = flagquestion(a, L, R);
//		sort_6(a, L, c.a); 
//		sort_6(a, c.b , R);
//	}
//}
////#include<time.h>
////int main()
////{
////	srand((unsigned int)time(NULL));
////	int a[] = { 8, 6, 4, 7, 9, 2, 3, 5, 1, 0 };
////	int length1 = sizeof(a) / sizeof(a[0]);
////	//sort_1(a, length);
////	//sort_2(a, length);
////	//sort_3(a, length);
////	//sort_4(a, length);
////	//sort_5(a, length);
////	sort_6(a, 0,length1-1);
////	//int b[] = { 5, 5, 4, 8, 9, 9, 6, 3, 2, 5, 4 ,9};
////	//int length2 = sizeof(b) / sizeof(b[0]);
////	//flagquestion(b, 0, length2 - 1);
////	for (auto e : a)
////		cout << e;
////	cout << endl;
////	return 0;
////}

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		string p;
		int len = data.size();
		for (int i = 0; i < len; ++i)
		{
			p.push_back(data[i]);
		}
		int  s1 = p.find('k');
		int s2 = p.rfind('k');
		return s2 - s1 + 1;
	}
	};

int main()
{
	Solution s;
	vector<int> data{ 1, 2, 3, 3, 3, 3 };
	int ret = s.GetNumberOfK(data, 3);
	cout << ret << endl;
	return 0;
}