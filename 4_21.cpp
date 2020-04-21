#include<iostream>
#include<string>
#include<vector>
using namespace std;
class FUNC
{
public:
	void func(int sum, int n)
	{
		if (sum <= 0 || n <= 0)
			return;
		if (sum == n)
		{
			for (auto e : vec)
			{
				cout << e<<" ";
			}
			cout << n << endl;
		}
		vec.push_back(n);
		func(sum - n, n - 1);
		vec.pop_back();
		func(sum, n - 1);
	}
private:
	vector<int> vec;
};
int main()
{
	FUNC().func(1235, 10000);
	return 0;
}