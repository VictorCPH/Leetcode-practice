// leetcode54.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int width = matrix.size();
		if (width == 0 ) return vector<int>();
		int length = matrix[0].size();
		if (length == 0) return vector<int>();
		vector<int> res;

		int i = 0;
		int j = 0;
		int k = 0;
		while (length > 2*k && width > 2*k) {
			i = k;
			for (j = k; j < length - k; ++j)
				res.push_back(matrix[i][j]);

			j = length - 1 - k;
			if (k + 1 >= width - k) break;
			for (i = k + 1; i < width - k; ++i)
				res.push_back(matrix[i][j]);

			i = width - 1 - k;
			if (length - 2 - k < k) break;
			for (j = length - 2 - k; j >= k; --j)
				res.push_back(matrix[i][j]);

			j = k;
			for (i = width - 2 - k; i > k; --i)
				res.push_back(matrix[i][j]);

			++k;
		}
		return res;
	}
};
int main()
{
	Solution sol;
	vector<vector<int>> matrix{ {1},{2},{3},{4 }};
	vector<int> res = sol.spiralOrder(matrix);

	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	system("pause");
    return 0;
}

