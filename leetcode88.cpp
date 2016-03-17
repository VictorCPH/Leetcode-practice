// leetcode88.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m - 1; i >= 0; --i)
			swap(nums1[i], nums1[i + n]);

		int i = n;
		int j = 0;
		int k = 0;
		while (i < m + n && j < n) {
			if (nums1[i] < nums2[j]) {
				nums1[k] = nums1[i];
				++i;
			}
			else {
				nums1[k] = nums2[j];
				++j;
			}
			++k;
		}
		if (i == m + n)
			for (int p = j; p < n; ++p, ++k)
				nums1[k] = nums2[p];
	}
};
int main()
{
	vector<int> nums1{ 1,4,5,6,9,0,0,0,0,0 };
	vector<int> nums2{ 1,2,3,10,11 };
	Solution sol;
	sol.merge(nums1, 5, nums2, 5);
	for (int i = 0; i < 10; ++i)
		cout << nums1[i] << " ";
	system("pause");
    return 0;
}

