// leetcode90.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res{vector<int>()};
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		subsets(res, nums, tmp, 0);
		return res;
	}
private:
	void subsets(vector<vector<int>>& res, vector<int>& nums,vector<int>& tmp, int pos) {
		if (pos == nums.size()) 
			return;
		
		for (int i = pos; i < nums.size(); ++i) {
			tmp.push_back(nums[i]);
			if (find(res.begin(), res.end(), tmp) == res.end())
				res.push_back(tmp);
			subsets(res, nums, tmp, i + 1);
			tmp.pop_back();
		}
			
	}
};
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res{ {} };
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int count = 0;
			while (i + count < nums.size() && nums[i] == nums[i + count])
				++count;
			int size = res.size();
			for (int j = 0; j < size; ++j) {
				vector<int> tmp(res[j]);
				for (int k = 0; k < count; ++k) {
					tmp.push_back(nums[i]);
					res.push_back(tmp);
				}
			}
			i = i + count - 1;
		}
		return res;
	}
};


int main()
{
	Solution sol;
	vector<int> nums{ 4,1,0 };
	vector<vector<int>> res = sol.subsetsWithDup(nums);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
    return 0;
}

