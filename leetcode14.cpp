// leetcode14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0 || strs[0].size() == 0) 
			return "";
		for (int i = 0; i < strs[0].size(); ++i) {
			for (int j = 1; j < strs.size(); ++j) {
				if (strs[0][i] != strs[j][i]) {
					return i == 0 ? "" : strs[0].substr(0, i);
				}
			}
		}
		return  strs[0];
	}
};
*/

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string commonPrefix = strs[0];
		for (int i = 1; i < strs.size(); ++i) {
			while (strs[i].find(commonPrefix) != 0)
				commonPrefix = commonPrefix.substr(0, commonPrefix.size() - 1);
		}
		return commonPrefix;
	}
};

int main()
{
	Solution sol;
	vector<string> strs1 = { "aab", "aabd", "aabdd" };
	cout << sol.longestCommonPrefix(strs1) << endl;

	vector<string> strs2 = { "" };
	cout << sol.longestCommonPrefix(strs2) << endl;

	vector<string> strs3 = { "qwertyuioaaa", "qwertyuiob", "qwertyuiodd" };
	cout << sol.longestCommonPrefix(strs3) << endl;
	system("pause");
    return 0;
}

