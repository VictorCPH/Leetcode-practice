// leetcode89.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		if (n == 0) return vector<int>{0};
		vector<int> res{ 0,1 };
		if (n == 1) return res;

		for (int i = 1; i < n; ++i) {
			int size = res.size();
			for (int j = size - 1; j >= 0; --j) {
				res.push_back(res[j] + (1 << i));
			}
		}
		return res;
	}
};
int main()
{
	Solution sol;
	vector<int> res = sol.grayCode(3);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	system("pause");
    return 0;
}

