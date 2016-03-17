// leetcode28.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)	 return 0;
		bool success = false;
		int j = 0;
		int i = 0;
		while (i < haystack.size()) {
			if (haystack[i] == needle[j]) {
				++i;
				++j;
				if (j == needle.size()) {
					success = true;
					break;
				}
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}
		
		return success ? i - j : -1;
	}
};

int main()
{
	Solution sol;
	cout << sol.strStr("sissippi", "issip");
	system("pause");
    return 0;
}

