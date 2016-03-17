// leetcode27.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int size = nums.size();
		if (size == 0) return 0;

		for (int i = 0; i < size; ++i) {
			if (nums[i] == val) {
				while (size - 1 > i && nums[size - 1] == val)
					--size;
				if (size - 1 > i) 
					swap(nums[i], nums[size - 1]);
				--size;
			}
		}
		return size;
	}
};
//1,2,3,4,5,6     4
//4,4,4,4,4,4     4
//4,4,5,6         4
int main()
{
	vector<int> nums{ 4,4,5,6 };
	int val = 4;
	Solution sol;
	int length = sol.removeElement(nums, val);
	for (int i = 0; i < length; ++i)
		cout << nums[i] << " ";
	system("pause");
    return 0;
}

