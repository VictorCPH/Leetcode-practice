// leetcode64.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int M = grid.size();
		int N = grid[0].size();
		vector<vector<int>> res(M, vector<int>(N, 0));

		res[0][0] = grid[0][0];
		for (int j = 1; j < N; ++j)
			res[0][j] = res[0][j - 1] + grid[0][j];
		for (int i = 1; i < M; ++i)
			res[i][0] = res[i - 1][0] + grid[i][0];
		for (int i = 1; i < M; ++i) 
			for (int j = 1; j < N; ++j)
				res[i][j] = min(res[i - 1][j], res[i][j - 1]) + grid[i][j];
		return res[M - 1][N - 1];
	}
};
int main()
{
	system("pause");
    return 0;
}

