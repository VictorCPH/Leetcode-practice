// leetcode53.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = INT_MIN;
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			if (sum > maxSum)
				maxSum = sum;
			if (sum < 0) {
				sum = 0;
			}
		}
		return maxSum;
	}
};
int main()
{
	vector<int> nums{ -2,-1,-3};
	Solution sol;
	cout << sol.maxSubArray(nums) << endl;
	system("pause");
    return 0;
}

