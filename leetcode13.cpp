// leetcode13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
/*
class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> table;
		table['M'] = 1000;
		table['D'] = 500;
		table['C'] = 100;
		table['L'] = 50;
		table['X'] = 10;
		table['V'] = 5;
		table['I'] = 1;
		int result = table[s[s.size() - 1]];
		for (int i = 0; i < s.size() - 1; ++i) {
			if (table[s[i]] < table[s[i + 1]])
				result -= table[s[i]];
			else
				result += table[s[i]];
		}
		return result;
	}
};
*/

class Solution {
public:
	int romanToInt(string s) {
		int table[256] = { 0 };
		table['M'] = 1000;
		table['D'] = 500;
		table['C'] = 100;
		table['L'] = 50;
		table['X'] = 10;
		table['V'] = 5;
		table['I'] = 1;
		int result = table[s[s.size() - 1]];
		for (int i = 0; i < s.size() - 1; ++i) {
			if (table[s[i]] < table[s[i + 1]])
				result -= table[s[i]];
			else
				result += table[s[i]];
		}
		return result;
	}
};

int main()
{
	Solution sol;
	cout << sol.romanToInt("CMXCIX") << endl;
	cout << sol.romanToInt("MMMCMXCIX") << endl;
	cout << sol.romanToInt("MCMLXXVI") << endl;
	cout << sol.romanToInt("XXXIX") << endl;
	system("pause");
    return 0;
}

