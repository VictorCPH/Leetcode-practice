// leetcode18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {		
		vector<vector<int>> res;
		int size = nums.size();
		if (size < 4) return res;
		sort(nums.begin(), nums.end());
		for (int first = 0; first < size - 3; ++first) {
			if (first > 0 && nums[first] == nums[first - 1]) continue;
			if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) break;
			if (nums[size - 1] + nums[size - 2] + nums[size - 3] + nums[first] < target) continue;
			for (int second = first + 1; second < size - 2; ++second) {
				if (second > first + 1 && nums[second] == nums[second - 1]) continue;
				if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) break;
				if (nums[first] + nums[second] + nums[size - 1] + nums[size - 2] < target) continue;
				int third = second + 1;
				int fourth = size - 1;
				int sum = 0;
				while (third < fourth) {
					sum = nums[first] + nums[second] + nums[third] + nums[fourth];
					if (sum == target) {
						res.push_back(vector<int>{nums[first], nums[second], nums[third], nums[fourth]});
						++third;
						--fourth;
						while (third < fourth && nums[third] == nums[third - 1])  ++third;
						while (third < fourth && nums[fourth] == nums[fourth + 1])  --fourth;
					}
					else if (sum < target) {
						++third;
						while (third < fourth && nums[third] == nums[third - 1])  ++third;
					}
					else {
						--fourth;
						while (third < fourth && nums[fourth] == nums[fourth + 1])  --fourth;
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	vector<int> nums{ 1 ,0, -1, 0 ,-2, 2 };
	int target = 0;
	vector<vector<int>> res = sol.fourSum(nums, target);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

