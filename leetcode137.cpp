// leetcode137.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int state1 = 0, state2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			state1 = (state1^nums[i]) & ~state2;
			state2 = (state2^nums[i]) & ~state1;
		}
		return state1;
	}
};
int main()
{
	vector<int> nums = {1,1,1,3,3,3,4};
	Solution sol;
	cout << sol.singleNumber(nums);
	system("pause");
    return 0;
}

