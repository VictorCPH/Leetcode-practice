// leetcode119.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 1);
		for (int i = 2; i <= rowIndex; ++i) {
			int tmp = 1;
			int preVal = 1;
			for (int j = 1; j <= i - 1; ++j) {
				tmp = res[j];
				res[j] += preVal;
				preVal = tmp;				
			}
		}
		return res;
	}
};
int main()
{
	Solution sol;
	vector<int> res = sol.getRow(7);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	system("pause");
    return 0;
}

