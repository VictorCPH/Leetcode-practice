// leetcode26.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		for (vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); ) {
			if (*iter == *(iter - 1))
				iter = nums.erase(iter);
			else
				++iter;
		}
		return nums.size();
	}
};
*/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int count = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] != nums[i - 1]) {
				nums[count] = nums[i];
				++count;
			}
		}
		return count;
	}
};

int main()
{
	Solution sol;
	vector<int> nums{1,3,3,4,4,5,6,7};
	int length = sol.removeDuplicates(nums);
	cout << length << endl;
	for (int i = 0; i < length; ++i) {
		cout << nums[i] << " ";
	}
	system("pause");
    return 0;
}

