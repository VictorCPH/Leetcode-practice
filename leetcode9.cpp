// leetcode9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int num = 0;
		int xTmp = x;
		int y = 0, z = 0;
		while (xTmp) {
			xTmp /= 10;
			++num;
		}

		for (int i = 1; i <= num / 2; ++i) {
			y = x % int(pow(10, i)) / int(pow(10, i - 1));
			z = x / int(pow(10, num - i)) % 10;
			if (y != z)
				return false;
		}
		return true;
	}
};
*/
/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int res = 0;
		int tmp = x;
		while (tmp) {
			res = res * 10 + tmp % 10;
			tmp /= 10;
		}
		return res == x;
	}
};
*/

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0)) return false;
		int res = 0;
		while (x > res) {
			res = res * 10 + x % 10;
			x /= 10;
		}
		return (res == x || x == res / 10);
	}
};

int main()
{
	Solution sol;
	cout << sol.isPalindrome(10);
	system("pause");
    return 0;
}

