// leetcode59.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (n <= 0) return vector<vector<int>>();
		
		vector<vector<int>> res(n, vector<int>(n, 0));
		int i = 0;
		int j = 0;
		int k = 0;
		int count = 0;
		while (n > 2 * k) {
			i = k;
			for (j = k; j < n - k; ++j)
				res[i][j] = ++count;

			j = n - 1 - k;
			if (k + 1 >= n - k) break;
			for (i = k + 1; i < n - k; ++i)
				res[i][j] = ++count;

			i = n - 1 - k;
			for (j = n - 2 - k; j >= k; --j)
				res[i][j] = ++count;

			j = k;
			for (i = n - 2 - k; i > k; --i)
				res[i][j] = ++count;
			++k;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> res = sol.generateMatrix(10);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

