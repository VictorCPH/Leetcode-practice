// leetcode41.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 1; i < nums.size(); ++i) {
			while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
					swap(nums[i], nums[nums[i] - 1]);			
			}
		}
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				return i + 1;
		return nums.size() + 1;
	}
};
int main()
{
	Solution sol;
	vector<int> nums{ 3,4,2,-1,-6,0,7,2,1 };
	cout << sol.firstMissingPositive(nums) << endl;
	system("pause");
    return 0;
}

