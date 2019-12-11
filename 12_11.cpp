#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

	void push(int value) {
		vec1.push_back(value);
		if (vec2.size() == 0)
		{
			vec2.push_back(value);
		}
		else
		{
			if (value < vec2[size - 1])
				vec2.push_back(value);
			else
				vec2.push_back(vec2[size - 1]);
		}
		size++;
	}

	void pop() {
		/*vec1.erase(vec1.begin() + size - 1);
		vec2.erase(vec2.begin() + size - 1);*/
		vec1.erase(vec1.end() - 1);
		vec2.erase(vec2.end() - 1);
		size--;
	}
	int top() {
		return vec1[size - 1];
	}
	int min() {
		return vec2[size - 1];
	}
	vector<int> vec1;
	vector<int> vec2;
	int size = 0;
};
int main()
{
	Solution s;
	s.push(1);
	s.push(5);
	s.push(3);
	s.push(0);
	s.push(2);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;

	return 0;
}