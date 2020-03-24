#include<iostream>
#include<vector>
#include<string>
using namespace std;
void funv()
{
	string s1;
	while (cin>>s1)
	{
		string s2;
		cin >> s2;
		size_t size = s1.size();
		int i = 0, j = 0;
		int count = 0;
		//ATTTAA
		//TTAATT

		//ATATAA
		//TTAATT
		for (i; i < size,j < size; ++j)
		{
			if (i < size && j < size && s1[j] != s2[j] && s2[j] == s1[i])
			{
				swap(s1[i], s1[j]);
				count++;
				i = j + 1;
			}
		}
		for (int x = 0; x < size; ++x)
		{
			if (s1[x] != s2[x])
				count++;
		}
		cout << count << endl;
	}

}

int main()
{
	funv();

	return 0;
}