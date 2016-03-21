// leetcode93.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		restoreIpAddressesHelp(s, res, 0, 0);
		return res;
	}
private:
	void restoreIpAddressesHelp(string& s, vector<string>& res, int pos, int depth) {
		if (depth == 3) {
			if (s.size() - pos == 1 || (s.size() - pos == 2 && s[pos] != '0'))
				res.push_back(s);
			else if (s.size() - pos == 3 && s.substr(pos, 3) <= "255" &&  s.substr(pos, 3) >= "100")
				res.push_back(s);
			return;
		}
		for (int i = 1; i <= 3; ++i) {
			if (pos + i <= s.size()) {
				string tmp(s);
				if (i == 1 || (i == 2 && s[pos] != '0') || 
					(i == 3 && s.substr(pos, 3) <= "255" &&  s.substr(pos, 3) >= "100")) 
					s = s.substr(0, pos + i) + '.' + s.substr(pos + i, s.size() - i);
				else 
					continue;	
				restoreIpAddressesHelp(s, res, pos + i + 1, depth + 1);
				s = tmp;
			}
			else
				return;
		}
	}
};
int main()
{
	Solution sol;
	vector<string> res = sol.restoreIpAddresses("010010");
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	system("pause");
    return 0;
}

