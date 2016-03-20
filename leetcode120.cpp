// leetcode120.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		for (int i = triangle.size() - 2; i >= 0; --i) 
			for (int j = 0; j < triangle[i].size(); ++j)
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		return triangle[0][0];
	}
};
int main()
{
	vector<vector<int>> res{ {2},{3,4},{6,5,7},{4,1,8,3} };
	Solution sol;
	cout << sol.minimumTotal(res) << endl;
	system("pause");
    return 0;
}

