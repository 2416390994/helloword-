#include<iostream>
#include<string>
#include<vector>
using namespace std;
string change(string number) {
	size_t size = number.size();
	int i = 0;
	int j = size - 1;
	while (i < j)
	{
		while ((i < j) && (number[i] - '0') % 2 != 0)
		{
			i++;
		}
		while ((i < j) && (number[j] - '0') % 2 != 0)
		{
			j--;
		}
		swap(number[i], number[j]);
		i++;
		j--;
	}
	return number;
}
int func(int number)
{
	if (number < 2)
		return 1;

	int func1 = 1;
	int func2 = 1;
	int func3;
	for (int i = 2; i <= number; ++i)
	{
		func3 = func1 + func2;
		func1 = func2;
		func2 = func3;
	}
	return func3;
}

//int main()
//{
//	cout << change("1234") << endl;
//	return 0;
//}


int mianzhi[5] = { 50, 20, 10, 5, 1 };//ÃæÖµ
int count = 0;
//left_money Ê£ÓàµÄÇ®
void change_money(int left_money, int mianzhi_num)
{
	int i;
	int all = left_money / mianzhi[mianzhi_num];
	if (mianzhi[mianzhi_num] == 1 || all == 0)
	{
		::count++;
		return;
	}
	for (i = all; i >= 0; i--)
	{
		change_money(left_money - i*mianzhi[mianzhi_num], mianzhi_num + 1);
	}
}

void func2(vector<int>& vec)
{
	int L = 0;
	int R = vec.size() - 1;
	while (L < R)
	{
		if (vec[L] % 2 == 1)
		{
			L++;
		}
		else
		{
			swap(vec[L], vec[R]);
			R--;
		}
	}
}


int main()
{

	vector<int> vec = { 1, 2, 2, 1, 1, 3, 3, 2, 2, 1 };
	func2(vec);
	for (auto e : vec)
		cout << e << endl;
	/*int all_money;
	scanf_s("%d", &all_money);
	change_money(all_money, 0);
	printf("%d\n", ::count);*/
}







