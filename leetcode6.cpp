// leetcode6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string subString;
		if (numRows == 1)
			return s;

		for (int j = 0; j < s.size(); j += 2 * (numRows - 1)) {
			subString.push_back(s[j]);
		}

		for (int i = 1; i < numRows - 1; ++i) {
			int j = i;
			int flag = 1;
			while (j < s.size()) {
				subString.push_back(s[j]);
				flag = (flag + 1) % 2;
				if (flag == 0)
					j += 2 * (numRows - 1 - i);
				else
					j += 2 * i;
			}
		}

		for (int j = numRows - 1; j < s.size(); j += 2 * (numRows - 1)) {
			subString.push_back(s[j]);
		}
		return subString;
	}
};

int main()
{
	string s("PAYPALISHIRING");
	int numRows = 1;
	Solution solution;

	cout << solution.convert(s, numRows);
	system("pause");
    return 0;
}

/*

"PAYPALISHIRING"
P     I     N
A   L S   I G
Y A   H R 
P     I

PINALSIGYAHRPI
PINALIGYAIHRNPI
*/