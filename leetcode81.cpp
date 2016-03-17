// leetcode81.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int low = 0;
		int high = nums.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (nums[mid] == target)
				return true;
			
			if (nums[mid] > nums[high]) {
				if (target >= nums[low] && target < nums[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			else if (nums[mid] < nums[high]) {
				if (target > nums[mid] && target <= nums[high])
					low = mid + 1;
				else
					high = mid - 1;
			}
			else
				--high;		
		}
		return false;
	}
};
int main()
{
	Solution sol;
	vector<int> nums{ 4,5,6,7,7,7,7,7,7,0,0,2,2,2,3,4 };
	int target = 8;
	cout << sol.search(nums, target);
	system("pause");
    return 0;
}

