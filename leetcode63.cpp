// leetcode63.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> pathsNum(m + 1, vector<int>(n + 1, 0));
		pathsNum[0][1] = 1;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (!obstacleGrid[i - 1][j - 1])
					pathsNum[i][j] = pathsNum[i - 1][j] + pathsNum[i][j - 1];
		return pathsNum[m][n];
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > res{ {0,0,0},{0,1,0},{0,0,0} };
	cout << sol.uniquePathsWithObstacles(res);
	system("pause");
    return 0;
}

