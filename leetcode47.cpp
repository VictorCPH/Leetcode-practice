// leetcode47.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		findPermute(0, nums, res);
		return res;
	}
private:
	void findPermute(int pos, vector<int> nums, vector<vector<int>>& res) {
		if (pos == nums.size() - 1) {
			res.push_back(nums);
		}
		else {
			for (int i = pos; i < nums.size(); ++i) {
				if (pos != i && nums[pos] == nums[i])
					continue;
				swap(nums[pos], nums[i]);
				findPermute(pos + 1, nums, res);
			}
		}
	}
};

int main()
{
	Solution sol;
	vector<int> nums{ 3,3,0,0,2,3,2 };
	vector<vector<int>> res = sol.permuteUnique(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}

