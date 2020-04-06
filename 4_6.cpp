#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        size_t size = matrix.size();
        int row = size;
        int col = matrix[0].size();
        int top = 0,left = 0,bottom = row - 1,right = col - 1;
        vector<int> vec;
        while(top <= bottom && left <= right)
        {
            for(int i = left;i <= right; ++i)
                vec.push_back(matrix[top][i]);
            for(int i = top + 1;i <= bottom;++i)
                vec.push_back(matrix[i][right]);
            for(int i = right - 1; i >= left && top < bottom; --i)
                vec.push_back(matrix[bottom][i]);
            for(int i = bottom - 1;i > top &&  left < right; --i)
                vec.push_back(matrix[i][left]);
            
            top++;left++;bottom--;right--;
             
                
        }
        
    }
};

*/

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		vector<int> vec;
		int row = matrix.size();
		int col = matrix[0].size();
		int top = 0, left = 0, bottom = row - 1, right = col - 1;
		while (left <= right && top <= bottom)
		{
			for (int i = left; i <= right; ++i)
				vec.push_back(matrix[top][i]);
			for (int i = top + 1; i <= bottom; ++i)
				vec.push_back(matrix[i][right]);
			for (int i = right - 1; i >= left&&top < bottom; --i)
				vec.push_back(matrix[bottom][i]);
			for (int i = bottom - 1; i > top&&left < right; --i)
				vec.push_back(matrix[i][left]);
			top++; left++; bottom--; right--;
		}
		return vec;
	}
};

int main()
{

	return 0;
}