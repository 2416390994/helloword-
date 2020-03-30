//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
////void replaceSpace(char *str, int length) {
////	
////}
////
////
////int main()
////{
////	char* str = "how are";
////	replaceSpace(str, 11);
////	return 0;
////}
//
//
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//		if (pre.size() == 0 || vin.size() == 0)
//			return nullptr;
//		int x = pre[0];
//		TreeNode* p = new TreeNode(pre[0]);
//		vector<int> vec1;
//		vector<int> vec2;
//		vector<int> vec3;
//		vector<int> vec4;
//		int i;
//		for (i = 0; i < vin.size(); ++i)
//		{
//			if (vin[i] != x)
//			{
//				vec1.push_back(vin[i]);
//			}
//			else
//			{
//				++i;
//				break;
//			}
//		}
//		for (int j = i; j < vin.size(); ++j)
//		{
//			vec2.push_back(vin[j]);
//		}
//		int k;
//		int count = 0;
//		for (k = 1; k < pre.size() && count < vec1.size(); ++k)
//		{
//			vec3.push_back(pre[k]);
//			count++;
//		}
//		for (int z = k; z < pre.size(); ++z)
//		{
//			vec4.push_back(pre[z]);
//		}
//		TreeNode* L = reConstructBinaryTree(vec3, vec1);
//		TreeNode* R = reConstructBinaryTree(vec4, vec2);
//		p->left = L;
//		p->right = R;
//		return p;
//	}
//
//
//	int main()
//	{
//		vector<int> vec1 = { 1, 2, 4, 7, 3, 5, 6, 8 };
//		vector<int> vec2 = { 4, 7, 2, 1, 5, 3, 8, 6 };
//
//
//		TreeNode* p = reConstructBinaryTree(vec1, vec2);
//
//		return 0;
//	}




















