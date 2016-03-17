// leetcode34.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int low = 0;
		int high = nums.size() - 1;
		int res = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (nums[mid] == target) {
				res = mid;
				break;
			}
			else if (nums[mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}

		if (res == -1)  return vector<int>{-1, -1};

		int i = res - 1;
		int j = res + 1;
		while (i >= 0 && nums[i] == nums[res]) {
			--i;
		}
		while (j < nums.size() && nums[j] == nums[res]) {
			++j;
		}
			
		return vector<int>{i + 1, j - 1};
	}
}; 

int main()
{
	Solution sol;
	vector<int> nums{ 1 };
	int target = 1;
	vector<int> range = sol.searchRange(nums, target);
	for (int i = 0; i < range.size(); ++i)
		cout << range[i] << " ";
	system("pause");
    return 0;
}

