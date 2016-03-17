// leetcode62.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		double maxMN = max(m, n);
		double minMN = min(m, n);

		double res = 1;
		for (double i = 1.0; i <= minMN - 1 + 0.5; ++i) {
			res *= (maxMN - 1 + i) / i;
			cout << res << endl;
		}
		return floor(res + 0.1);
	}
};
int main()
{
	Solution sol;
	cout << sol.uniquePaths(10, 10);
	system("pause");
    return 0;
}

