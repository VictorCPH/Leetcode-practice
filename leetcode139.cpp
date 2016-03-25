// leetcode139.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> isOK(s.size() + 1, false);
		isOK[0] = true;
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (isOK[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
					isOK[i] = true;
					break;
				}
			}
		}
		return isOK[s.size()];
	}
};
int main()
{
	Solution sol;
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	cout << sol.wordBreak(s, wordDict) << endl;
	system("pause");
    return 0;
}

