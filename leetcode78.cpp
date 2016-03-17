// leetcode78.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.size() == 0) return vector<vector<int>>{vector<int>()};
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> tmp;
		produceSubsets(res, tmp, nums, 0);
		res.push_back(vector<int>());
		return res;
	}

private:
	void produceSubsets(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int pos) {
		if (pos == nums.size())
			return;

		for (int i = pos; i < nums.size(); ++i) {
			tmp.push_back(nums[i]);
			res.push_back(tmp);
			produceSubsets(res, tmp, nums, i + 1);
			tmp.pop_back();
		}
	}
};

int main()
{
	vector<int> nums{  2,3,7,1 };
	Solution sol;
	vector<vector<int>> res = sol.subsets(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl; 
	}
	
	system("pause");
    return 0;
}

