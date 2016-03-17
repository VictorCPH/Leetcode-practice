// leetcode35.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0 || target < nums[0])  return 0;
		if (target > nums[nums.size() - 1]) return nums.size();

		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return nums[mid] > target ? mid : mid + 1;
	}
};

int main()
{
	Solution sol;
	vector<int> nums{1,2,3,4};
	int target = 7;
	cout << sol.searchInsert(nums, target);
	system("pause");
    return 0;
}

