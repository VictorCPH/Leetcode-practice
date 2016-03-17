// leetcode16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int sum = 0;
		pair<int, int> dis = make_pair(INT_MAX, 0);
		for (int i = 0; i < size; ++i) {
			while (i > 0 && i < size && nums[i] == nums[i - 1])
				++i;

			int low = i + 1;
			int high = size - 1;
			while (low < high) {
				sum = nums[i] + nums[low] + nums[high];
				if (sum == target) 
					return sum;
				else if (sum > target) {
					if (abs(sum - target) < dis.first) {
						dis.first = abs(sum - target);
						dis.second = sum;
					}
					--high;
					while (low < high && nums[high] == nums[high + 1])
						--high;
				}
				else {
					if (abs(sum - target) < dis.first) {
						dis.first = abs(sum - target);
						dis.second = sum;
					}
					++low;
					while (low < high && nums[low] == nums[low - 1])
						++low;
				}
			}
		}
		return dis.second;
	}
};
//-4 -1 1 2
int main()
{
	Solution sol;
	vector<int> nums = { -1, 2, 1, -4 };
	int target = 1;
	cout << sol.threeSumClosest(nums, target)<< endl;
	system("pause");
    return 0;
}

