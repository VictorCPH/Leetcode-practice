// leetcode66.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int sum = 0;
		int carry = 1;
		vector<int> res(digits.size() + 1, 0);
		for (int i = digits.size() - 1; i >= 0; --i) {
			sum = digits[i] + carry;
			res[i + 1] = sum % 10;
			carry = sum / 10;
		}
		if (carry == 0)
			res.erase(res.begin());
		else
			res[0] = carry;
		return res;
	}
};
int main()
{
	Solution sol;
	vector<int> digits{ 9,9,9 };
	vector<int> res = sol.plusOne(digits);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	system("pause");
	return 0;
}


