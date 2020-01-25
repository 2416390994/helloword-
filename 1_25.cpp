#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
	k = k %nums.size();
	if (nums.size() == 0)
		return;
	if (k == 0)
		return;
	size_t size = nums.size();
	reverse(nums.begin(), nums.begin() + size - k);
	reverse(nums.begin() + size - k, nums.end());
	reverse(nums.begin(), nums.end());
}

int main()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	rotate(vec, 3);
	for (auto e : vec)
		cout << e << endl;





	/*int num;
	int sum;
	sum = num = 7;
	sum = num++, sum++, ++num;
	cout << sum;*/
	//int i = 10, j = 10,k = 3;
	////k *= i + j;
	//k = k*(i + j);
	//cout << k << endl;

	return 0;
}