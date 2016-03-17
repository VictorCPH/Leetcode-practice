// leetcode4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() + nums2.size() == 0) return 0;
		if ((nums1.size() + nums2.size()) % 2 == 1)
			return findKNumber(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1);
		else
			return (findKNumber(nums1, nums2, (nums1.size() + nums2.size()) / 2)
				+ findKNumber(nums1, nums2, (nums1.size() + nums2.size()) / 2 + 1)) / 2;		
	}
private:
	double findKNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int index1 = 0;
		int index2 = 0;
		int m = nums1.size();
		int n = nums2.size();

		while (1) {
			if (m < k / 2) {
				if (m > 0) {
					index2 += k / 2;
					n -= k / 2;
					k -= k / 2;
				}
				else
					return nums2[index2 + k - 1];
			}
			else if (n < k / 2) {
				if (n > 0) {
					index1 += k / 2;
					m -= k / 2;
					k -= k / 2;
				}
				else
					return nums1[index1 + k - 1];
			}
			else if (k == 1) {
				if (m > 0 && n > 0)
					return nums1[index1] < nums2[index2] ? nums1[index1] : nums2[index2];
				else if (m > 0)
					return nums1[index1];
				else
					return nums2[index2];
			}

			while (m >= k / 2 && n >= k / 2 && k > 1) {
				if (nums1[index1 + k / 2 - 1] < nums2[index2 + k / 2 - 1]) {
					index1 += k / 2;
					m -= k / 2;
					k -= k / 2;
				}
				else if (nums1[index1 + k / 2 - 1] > nums2[index2 + k / 2 - 1]) {
					index2 += k / 2;
					n -= k / 2;
					k -= k / 2;
				}
				else {
					if (k % 2 == 0)
						return nums1[index1 + k / 2 - 1];
					else {
						index1 += k / 2;
						m -= k / 2;
						index2 += k / 2;
						n -= k / 2;
						k -= k / 2 * 2;
					}
				}
			}
		}
	}
		
};

int main()
{
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {3,4,5};

	Solution sol;
	cout << sol.findMedianSortedArrays(nums1, nums2);
	system("pause");
    return 0;
}

