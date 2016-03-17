// leetcode75.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() <= 1)  return;
		int next0Index = 0;
		int next2Index = nums.size() - 1;
		for (int i = 0; i <= next2Index;) {
			if (nums[i] == 0) {
				while (next0Index < next2Index && nums[next0Index] == 0)
					++next0Index;
				if (next0Index == next2Index) break;
				if (next0Index >= i) {
					i = next0Index;
					continue;
				}
				swap(nums[i], nums[next0Index]);
				++next0Index;				
			}
			else if (nums[i] == 2) {
				while (next0Index < next2Index && nums[next2Index] == 2)
					--next2Index;
				if (next0Index == next2Index) break;
				if (next2Index <= i) {
					continue;
				}
				swap(nums[i], nums[next2Index]);
				--next2Index;
			}
			else
				++i;
		}
	}
};
int main()
{
	vector<int> nums{ 2,2,2};
	Solution sol;
	sol.sortColors(nums);
	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";
	cout << endl;
	system("pause");
    return 0;
}

