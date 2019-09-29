//#include<iostream>
//#include<vector>
//using namespace std;
////int GetNumberOfK(vector<int> data, int k) {
////	int L = 0;
////	int R = data.size() - 1;
////	int count = 0;
////	int middle;
////	int middle2;
////	int middle3;
////	while (L < R)
////	{
////		middle = (L + R) / 2;
////		if (data[middle]>k)
////			R = middle - 1;
////		else if (data[middle] < k)
////			L = middle + 1;
////		else
////		{
////			middle2 = middle3 = middle;
////			count++;
////			while (data[--middle2] == k)
////				count++;
////			while (data[++middle3] == k)
////				count++;
////			return count;
////		}
////
////	}
////	return 0;
////}
//
//
////vector<int> printMatrix(vector<vector<int> > matrix) {
////	int row = matrix.size();
////	int col = matrix[0].size();
////	vector<int> result;
////	// 输入的二维数组非法，返回空的数组
////	if (row == 0 || col == 0)  return result;
////	int top = 0, left = 0, right = col-1, bottom = row-1;
////	while(top <= bottom && left<= right)
////	{ 
////		//left to right
////		for(int i = left; i <= right; ++i)
////			result.push_back(matrix[top][i]);
////		//top tp bottom
////		for(int i = top+1; i <= bottom; ++i)
////			result.push_back(matrix[i][right]);
////		//right to left
////		for(int i = right-1; i >= left && top < bottom; --i)
////			result.push_back(matrix[bottom][i]);
////		//bottom to top
////		for(int i = bottom-1; i > top && right > left; --i)
////			result.push_back(matrix[i][left]);
////		++top; ++left; --right; --bottom;
////	}
////	return result;
////}
//vector<int> printMatrix(vector<vector<int> > matrix)
//{
//	vector<int> vec;
//	int row = matrix.size();
//	int col = matrix[0].size();
//	int top = 0, left = 0, bottom = row - 1, right = col - 1;
//	while (left <= right && top <=bottom )
//	{
//		for (int i = left; i <= right; ++i)
//			vec.push_back(matrix[top][i]);
//		for (int i = top + 1; i <= bottom; ++i)
//			vec.push_back(matrix[i][right]);
//		for (int i = right - 1; i >= left&&top < bottom; ++i)
//			vec.push_back(matrix[bottom][i]);
//		for (int i = bottom + 1; i < top&&left < right; ++i)
//			vec.push_back(matrix[i][left]);
//		top++; left++; bottom++; right++;
//	}
//	return vec;
//}
//int main()
//{
//	
//	vector<vector<int> >f(4, vector<int>(4));
//	int c = 1;
//	for (int j = 0; j < 4; ++j)
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			f[j][i] = c++;
//		}
//	}
//	
//	vector<int>  w;
//	w = printMatrix(f);
//	for (auto e : w)
//		cout << e << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> data{ 2, 4, 3, 6, 3, 2, 5, 5 };
	int length = data.size();
	int ges  = length;
	while (ges > 1){
		ges = ges / 3 + 1;
		for (int i = 1; i < length; ++i){
			for (int j = i; j > 0 && data[j] > data[j - 1]; --j){
				swap(data[j], data[j - 1]);
			}
		}
	}



	for (auto e : data)
		cout << e << endl;
	return 0;
	
}