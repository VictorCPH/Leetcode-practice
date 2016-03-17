// leetcode136.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
			res ^= nums[i];
		return res;
	}
};
int main()
{
	Solution sol;
	vector<int> nums{ 1,2,2,4,5,6,7,8,1,4,5,8,7 };
	cout << sol.singleNumber(nums) << endl;
	system("pause");
    return 0;
}

