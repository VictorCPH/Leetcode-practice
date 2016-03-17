// leetcode3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLength = 0;
		bool charArray[256] = { false };
		int i = 0;
		int j = 0;

		while (j < s.size()) {
			if (charArray[s[j]]) {
				if (j - i > maxLength)
					maxLength = j - i;
				while (s[i] != s[j]) {
					charArray[s[i]] = false;
					i++;
				}
				++i;
				++j;
			}
			else {
				charArray[s[j]] = true;
				++j;
			}
		}

		if (j - i > maxLength)
			maxLength = j - i;
		return maxLength;		
	}
};

int main()
{
	Solution solution;
	string str("pwwewk");
	cout << solution.lengthOfLongestSubstring(str);
	system("pause");
    return 0;
}

