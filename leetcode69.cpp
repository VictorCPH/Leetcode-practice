// leetcode69.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)  return 0;
		int res = 2;
		while (abs(x / res - res) > 1) {
			res = (x / res + res) / 2;
			cout << res << endl;
		}
		return res < x / res ? res : x / res;
	}
};
int main()
{
	Solution sol;
	cout << sol.mySqrt(1579205274);
	system("pause");
    return 0;
}

