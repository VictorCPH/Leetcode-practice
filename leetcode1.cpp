// leetcode1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); ++i) {
			if (map.find(target - nums[i]) == map.end()) {
				map[nums[i]] = i;
			}
			else {
				result.push_back(map[target - nums[i]]);
				result.push_back(i);
				return result;
			}	
		}
	}
};

int main()
{
	Solution solution;
	vector<int> nums ={ 217,231,523,52,547,243,648,509,415,149,689,710,265,187,370,56,977,182,400,329,471,
		805,955,989,255,766,38,566,79,843,295,229,988,108,781,619,704,542,
		335,307,359,907,727,959,161,699,123,650,147,459,657,188,304,268,405,685,620,721,
		351,570,899,60,388,771,24,659,425,440,508,373,32,645,409,272,356,175,533,740,370,
		152,34,510,745,251,227,494,258,527,817,773,178,194,860,387,627,851,449,736,15,212
		,529,950,316,28,65,484,968,63,4,643,795,669,203,677,139,636,289,555,430,849,
		150,493,301,377,240,873,965,441,230,349,447,470
		};
	int target = 718;
	nums = solution.twoSum(nums, target);
	
	for (int i = 0; i < 2; i++)
		cout << nums[i];
	system("pause");
    return 0;
	
}

