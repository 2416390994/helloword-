//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1;
//	string str2;
//	while (cin >> str1 >> str2)
//	{
//		if (str1.size() < str2.size())
//			swap(str1, str2);
//		int count = 0;
//		int i = 0;
//		int j = 0;
//		while (i < str1.size())
//		{
//			if (str1[i] == str2[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				i++;
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	return  0;
//}
#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int calStringDistance(string a, string b){
	int n = a.size(), m = b.size();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
	for (int i = 1; i <= m; ++i) dp[0][i] = i;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
		}
	}
	return dp[n][m];
}
int main(){
	string a, b;
	while (cin >> a >> b)
		cout << calStringDistance(a, b) << endl;
	return 0;
}