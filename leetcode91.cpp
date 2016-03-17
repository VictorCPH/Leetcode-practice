// leetcode91.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 1) return s[0] == '0' ? 0 : 1;
		int f0, f1;
		s[0] == '0' ? f0 = 0 : f0 = 1;
		s[0] == '0' ? f1 = 0 : f1 = 1;
		int f2 = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == '0') {
				if (s[i - 1] == '1' || s[i - 1] == '2') 
					f2 = f0;
				else
					f2 = 0;
			}
			else {
				if (s.substr(i - 1, 2) <= "26" && s.substr(i - 1, 2) >= "10")
					f2 = f1 + f0;
				else {
					f2 = f1;
				}
			}
			f0 = f1;
			f1 = f2;
		}
		return f2;
	}
};
int main()
{
	Solution sol;
	cout << sol.numDecodings("1") << endl;
	cout << sol.numDecodings("0") << endl;
	cout << sol.numDecodings("0012") << endl; 
	cout << sol.numDecodings("12") << endl;
	cout << sol.numDecodings("123") << endl;
	cout << sol.numDecodings("124") << endl;
	cout << sol.numDecodings("12044") << endl;
	cout << sol.numDecodings("10203040") << endl;
	system("pause");
    return 0;
}

