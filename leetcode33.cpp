// leetcode33.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() < 1)
			return -1;
		if (nums.size() == 1 && nums[0] == target)
			return 0;
		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;
		if (nums[low] > nums[high]) {
			while (low <= high) {
				mid = (low + high) / 2;
				if (nums[mid] > nums[mid + 1]) {
					break;
				}
				else if (nums[mid] < nums[mid + 1] && nums[mid] >= nums[0])
					low = mid + 1;
				else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[0])
					high = mid - 1;
			}
			low = target >= nums[0] ? 0 : mid + 1;
			high = target >= nums[0] ? mid : nums.size() - 1;
		}

		while (low <= high) {
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return -1;
	}
};
int main()
{
	vector<int> nums{4,5,1,2,3};
	int target = 1;
	Solution sol;
	cout << sol.search(nums, target) << endl;
	system("pause");
    return 0;
}

