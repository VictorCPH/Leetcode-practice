// leetcode74.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int low = 0;
		int high = m * n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int val = matrix[mid / n][mid % n];
			if (val == target)
				return true;
			else if (val > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return false;
	}
};
int main()
{
	vector<vector<int> > matrix{ {1,3,5,7}, {10,11,16,20},{23,20,34,50} };
	Solution sol;
	int target = 20;
	cout << sol.searchMatrix(matrix, target);
	system("pause");
    return 0;
}

