// leetcode46.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 递归16ms
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0) return vector<vector<int>>();
		vector<vector<int>> res;
		findPermute(0, nums, res);
		return res;
	}
private:
	void findPermute(int pos, vector<int>& nums, vector<vector<int>>& res) {
		if (pos == nums.size())
			res.push_back(nums);
		else {
			for (int i = pos; i < nums.size(); ++i) {
				swap(nums[pos], nums[i]);
				findPermute(pos + 1, nums, res);
				swap(nums[pos], nums[i]);
			}
		}
	}
};
*/

//非递归，循环12ms
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0) return vector<vector<int>>();
		vector<vector<int>> res;
		res.push_back(nums);

		for (int i = 0; i < nums.size() - 1; ++i) {
			int size = res.size();
			for (int k = 0; k < size; ++k) {
				for (int j = i + 1; j < nums.size(); ++j) {
					vector<int> tmp(res[k]);
					swap(tmp[i], tmp[j]);
					res.push_back(tmp);
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	vector<int> nums{1,2,3,4,5,6};
	vector<vector<int>> res = sol.permute(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

