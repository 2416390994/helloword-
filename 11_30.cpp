//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int size = 0;
//	cin >> size;
//	vector<int> vec;
//	for (int i = 0; i < size; ++i)
//	{
//		int s1;
//		int s2;
//		vector<int> vec1;
//		vector<int> vec2;
//		vector<int> vec3;
//		cin >> s1 >> s2;
//		for (int j = 0; j < (2 * s1); ++j)
//		{
//			int num;
//			cin >> num;
//
//			if (j < s1)
//				vec1.push_back(num);
//			else
//				vec2.push_back(num);
//		}
//		while (s2--)
//		{
//			for (int k = 0; k < vec1.size(); ++k)
//			{
//				vec3.push_back(vec1[k]);
//				vec3.push_back(vec2[k]);
//			}
//			if (s2 > 0)
//			{
//				for (int t = 0; t < (vec3.size() / 2); ++t)
//					vec1[t] = vec3[t];
//				for (int t = (vec3.size() / 2), p = 0; t < vec3.size(); ++t, ++p)
//					vec2[p] = vec3[t];
//				vec3.clear();
//			}
//		}
//		for (int x = 0; x < vec3.size(); ++x)
//		{
//			vec.push_back(vec3[x]);
//		}
//		for (int i = 0; i < vec.size() - 1; ++i)
//		{
//			cout << vec[i] << " ";
//		}
//		cout << vec.back() << endl;
//		vec.clear();
//	}
//	return 0;
//}
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int music_size = 0;
	string mingling;
	vector<int> vec;
	cin >> music_size;
	cin >> mingling;
	for (int i = 1; i <= music_size; ++i)
		vec.push_back(i);
	int up = 0;
	int x = 0;
	int down = 3;
	for (int i = 0; i < mingling.size(); ++i)
	{
		if (mingling[i] == 'U')
		{
			if (x == 0)
			{
				x = music_size - 1;
				up = music_size - 1;
				down--;
			}
			else
			{
				if (x == up)
				{
					up--;
					down--;
				}
				if (down < 0)
				{
					down = music_size - 1;
				}
				x--;
			}
		}
		if (mingling[i] == 'D')
		{
			if (x == music_size - 1)
			{
				down = 0;
				up++;
				x = 0;
			}
			else
			{
				if (x == down)
				{
					down++;
					up++;
				}
				if (up == music_size - 1)
					up = 0;
				x++;
			}
		}
	}
	int k = up;
	for (int i = 0; i < 4; ++i)
	{
		if (k + 1 > music_size)
			k = 0;
		cout << vec[k] << " ";
		k++;
	}
	cout << endl;
	cout << vec[x] << endl;
	return 0;
}