// leetcode80.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int count = 1;
		int pos = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1]) 
				++count;	
			else 
				count = 1;
			
			nums[pos] = nums[i];
			if (count < 3)
				++pos;
		}
		return pos;
	}
};
int main()
{
	vector<int> nums{ 0,0,0,0,0,0,1,1,1,1,1,2,2,3,3,3,4 };
	Solution sol;
	int size = sol.removeDuplicates(nums);
	for (int i = 0; i < size; ++i)
		cout << nums[i] << " ";
	system("pause");
    return 0;
}

