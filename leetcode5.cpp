// leetcode5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		pair<string, int> longestSubString("", 0);

		for (int i = 0; i < s.size(); ++i) {
			int k = 0;
			int j = 1;
			while (i - j >= 0 && i + k < s.size()) {
				if (s[i - j] == s[i + k]) {
					if (2 * j > longestSubString.second) {
						longestSubString.first = string(s, i - j, 2 * j);
						longestSubString.second = 2 * j;
					}
					++j;
					++k;
				}
				else
					break;
			}
		}

		for (int i = 0; i < s.size(); ++i) {
			int j = 0;
			while (i - j >= 0 && i + j < s.size()) {
				if (s[i - j] == s[i + j]) {
					if (2 * j + 1 > longestSubString.second) {
						longestSubString.first = string(s, i - j, 2 * j + 1);
						longestSubString.second = 2 * j + 1;
					}
					++j;
				}
				else
					break;
			}
		}
		return longestSubString.first;
	}
};

int main()
{
	string s("abccba");
	Solution sol;
	cout << sol.longestPalindrome(s);
	system("pause");
    return 0;
}

