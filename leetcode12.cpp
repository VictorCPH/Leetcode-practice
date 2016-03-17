// leetcode12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string M[4] = { "", "M", "MM", "MMM" };
		string C[10] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		string X[10] = { "", "X", "XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		string I[10] = { "", "I","II","III","IV","V","VI","VII","VIII","IX" };

		return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
	}
};

int main()
{
	Solution sol;
	cout << sol.intToRoman(1001) << endl;
	system("pause");
    return 0;
}

