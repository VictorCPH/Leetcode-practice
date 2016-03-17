// leetcode258.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int addDigits(int num) {
		if (num == 0) return 0;
		return num % 9 ? num % 9 : 9;
	}
};

int main()
{
	Solution sol;
	cout << sol.addDigits(4) << endl;//4
	cout << sol.addDigits(0) << endl;//0
	cout << sol.addDigits(575) << endl;//8
	cout << sol.addDigits(8987) << endl;//5
	cout << sol.addDigits(344) << endl;//2
	cout << sol.addDigits(234) << endl;//9
	system("pause");
    return 0;
}

