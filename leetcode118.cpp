// leetcode118.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		for (int i = 0; i < numRows; ++i) {
			res.push_back(vector<int>(i + 1, 1));
			int end = i - 1;
			for (int j = 1; j <= end; ++j) {
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}
		}
		return res;
	}
};
int main()
{
	Solution sol;
	vector<vector<int>> res = sol.generate(10);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

