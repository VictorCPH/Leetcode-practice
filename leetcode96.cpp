// leetcode96.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
//卡特兰数
class Solution {
public:
	int numTrees(int n) {
		if (n <= 0) return 1;
		vector<int> res(n + 1, 0);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				res[i] += res[j] * res[i - j - 1];
			}
		}
		return res[n];
	}
};
int main()
{
	Solution sol;
	cout << sol.numTrees(0) << endl;
	cout << sol.numTrees(1) << endl;
	cout << sol.numTrees(2) << endl;
	cout << sol.numTrees(3) << endl;
	cout << sol.numTrees(4) << endl;
	cout << sol.numTrees(5) << endl;
	cout << sol.numTrees(6) << endl;
	cout << sol.numTrees(7) << endl;
	system("pause");
    return 0;
}

