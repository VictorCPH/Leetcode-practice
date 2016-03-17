// leetcode7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int reverse = 0;
		int tail = 0;
		int newReverse = 0;
		while (x != 0) {
			tail = x % 10;
			newReverse = reverse * 10 + x % 10;
			if ((newReverse - tail) / 10 != reverse)
				return 0;
			reverse = newReverse;
			x = x / 10;
		}
		return reverse;
	}
};

int main()
{
	Solution sol;
	cout << sol.reverse(1000000003);
	system("pause");
    return 0;
}

//2147483648