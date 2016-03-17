// leetcode15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > res;
		int size = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 0; i < size; ++i) {
			while (i > 0 &&i < size && nums[i] == nums[i - 1])
				++i;

			int j = i + 1;
			int k = size - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					res.push_back(vector<int>{nums[i], nums[j], nums[k]});
					++j;  --k;
					while (j < k && nums[j] == nums[j - 1])  ++j;
					while (j < k && nums[k] == nums[k + 1])  --k;				
				}
				else if (nums[i] + nums[j] + nums[k] > 0) {
					--k;
					while (j < k && nums[k] == nums[k + 1])  --k;
				}
				else {
					++j;
					while (j < k && nums[j] == nums[j - 1])  ++j;
				}				
			}
		}
		return res;
	}
};

int main()
{
	//-1  -1  0  1  2  4
	Solution sol;
	vector<int> nums{-1, 0, 1, 2, -1, 4};
	vector<vector<int>> res = sol.threeSum(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

