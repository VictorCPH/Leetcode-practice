// leetcode70.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 2)  return n;
		int add1 = 1;
		int add2 = 2;
		for (int i = 1; i <= n - 2; ++i) {
			add1 = add1 + add2;
			swap(add1, add2);
		}
		return add2;
	}
};

int main()
{
	Solution sol;
	cout << sol.climbStairs(1) << endl;
	cout << sol.climbStairs(2) << endl;
	cout << sol.climbStairs(3) << endl;
	cout << sol.climbStairs(4) << endl;
	cout << sol.climbStairs(5) << endl;
	cout << sol.climbStairs(6) << endl;
	system("pause");
    return 0;
}

