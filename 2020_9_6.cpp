#include<iostream>
#include<vector>
using namespace std;
void func()
{
	int Alen;
	cin >> Alen;
	vector<int> vec1;
	vec1.resize(Alen);
	for (int i = 0; i < Alen; ++i)
	{
		int val;
		cin >> val;
		vec1[i] = val;
	}

	int Blen;
	cin >> Blen;
	vector<int> vec2;
	vec2.resize(Blen);
	for (int i = 0; i < Blen; ++i)
	{
		int val;
		cin >> val;
		vec2[i] = val;
	}
	int i = 0;
	int j = 0;
	while (i < Alen && j < Blen)
	{
		while (i < Alen && vec1[i] > vec2[j])
		{
			i++;
		}
		while (j < Blen && vec2[j] > vec1[i])
		{
			j++;
		}

		if (vec1[i] == vec2[j])
		{
			cout << vec1[i] << " ";
			i++;
			j++;
		}
	}
}


int main()
{
	func();

	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void func()
{
	int size;
	cin >> size;
	vector<int> vec1;
	vec1.resize(size);
	for (int i = 0; i < size; ++i)
	{
		int c;
		cin >> c;
		vec1[i] = c;
	}
	vector<int> vec2;
	vec2 = vec1;
	sort(vec1.begin(), vec1.end());

	for (int i = 0; i < vec2.size(); ++i)
	{
		if (vec2[i] < vec1[(size / 2) - 1] && vec2[i] < vec1[size / 2])
		{
			cout << vec1[size / 2] << endl;
		}
		else if (vec2[i] > vec1[(size / 2) - 1] && vec2[i] > vec1[size / 2])
		{
			cout << vec1[(size / 2) - 1] << endl;
		}
		else if (vec2[i] == vec1[(size / 2) - 1])
		{
			cout << vec1[size / 2] << endl;
		}
		else if (vec2[i] == vec1[size / 2])
		{
			cout << vec1[(size / 2) - 1] << endl;
		}
	}

}


int main()
{
	func();

	return 0;
}