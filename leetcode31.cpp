// leetcode31.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1)  return;

		int i = nums.size() - 2;
		for (; i >= 0; i--)
			if (nums[i] < nums[i + 1])
				break;

		if (i != -1) {
			int j = nums.size() - 1;
			for (; j > i; j--)
				if (nums[j] > nums[i])
					break;
			swap(nums[i], nums[j]);
			int k = i + 1;
			j = nums.size() - 1;
			while (k < j) {
				swap(nums[k], nums[j]);
				++k;
				--j;
			}
		}
		else {
			int k = 0, j = nums.size() - 1;
			while (k < j) {
				swap(nums[k], nums[j]);
				++k; 
				--j;
			}
		}
	}
};

int main()
{
	Solution sol;
	vector<int> nums{ 1,1,5 };
	sol.nextPermutation(nums);
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	system("pause");
    return 0;
}

