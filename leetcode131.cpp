// leetcode131.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> aRes;
		partitionHelp(s, 0, res, aRes);
		return res;
	}
private:
	void partitionHelp(string& s, int pos, vector<vector<string>>& res, vector<string>& aRes) {
		if (pos == s.size()) {
			res.push_back(aRes);
			return;
		}
		for (int i = pos; i < s.size(); ++i) {
			if (isPalindrome(s, pos, i)) {
				aRes.push_back(s.substr(pos, i - pos + 1));
				partitionHelp(s, i + 1, res, aRes);
				aRes.pop_back();
			}
		}
	}
	bool isPalindrome(const string& s, int start, int end) {
		while (start < end) {
			if (s[start] != s[end]) 
				return false;
			++start;  --end;
		}
		return true;
	}
};
int main()
{
	Solution sol;
	string s("abcbacacab");
	vector<vector<string>> res = sol.partition(s);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

