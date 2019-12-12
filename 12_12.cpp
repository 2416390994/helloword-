#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//bool VerifySquenceOfBST(vector<int> sequence) {
//	int a = sequence[0];
//	sort(sequence.begin(), sequence.end());
//	int c = sequence[0];
//	if (a == c)
//		return true;
//	else
//		return false;
//}
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	RandomListNode* cur = pHead;
	while (cur != nullptr)
	{
		RandomListNode* p = cur->next;
		cur->next = new RandomListNode(cur->label);
		cur = cur->next;
		cur->next = p;
		cur = p;
	}

	cur = pHead;
	while (cur != nullptr)
	{
		if (cur->random == nullptr)
			cur->next->random = nullptr;
		else
			cur->next->random = cur->random->next;
		cur = cur->next->next;
	}
	cur = pHead;
	RandomListNode* cur1 = pHead->next;
	RandomListNode* cur2 = pHead->next;

	while (cur != nullptr)
	{
		cur->next = cur1->next;
		cur = cur->next;
		if (cur != nullptr)
		{
			cur1->next = cur->next;
			cur1 = cur1->next;
		}
	}

	return cur2;
}
void Permutation1(vector<string> &array, string str, int begin)//遍历第begin位的所有可能性
{
	if (begin == str.size() - 1)
		array.push_back(str);
	for (int i = begin; i <= str.size() - 1; i++)
	{
		if (i != begin && str[i] == str[begin])//有重复字符时，跳过
			continue;
		swap(str[i], str[begin]);//当i==begin时，也要遍历其后面的所有字符；
		Permutation1(array, str, begin + 1);//遍历其后面的所有字符；
		//swap(str[i], str[begin]);//为了防止重复的情况，还需要将begin处的元素重新换回来
	}
}
vector<string> Permutation(string str) {
	//可以用递归来做
	vector<string> array;
	if (str.size() == 0)
		return array;
	Permutation1(array, str, 0);
	sort(array.begin(), array.end());
	return array;
}

	
int main()
{
	/*RandomListNode p1(10);
	RandomListNode p2(20);
	RandomListNode p3(30);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = nullptr;
	p1.random = nullptr;
	p2.random = &p1;
	p3.random = &p2;
	Clone(&p1);*/
	Permutation("abbb");
	//vector<int> vec{ 7, 4, 2, 5 };
	//cout<<VerifySquenceOfBST(vec);
	return 0;
}
