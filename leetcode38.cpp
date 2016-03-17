// leetcode38.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)  return "";
		if (n == 1)  return "1";

		string str("1");
		for (int i = 1; i < n; ++i) {
			int count = 1;
			string strTmp = "";
			ostringstream ss;
			int j = 0;
			for (; j < str.size(); ++j) {
				if (j == 0) continue;
				if (j > 0 && str[j] == str[j - 1]) {
					++count;
					continue;
				}				
				ss << count;
				strTmp += ss.str() + str[j - 1];
				ss.str("");
				count = 1;
			}
			ss << count;
			strTmp += ss.str() + str[j - 1];
			str = strTmp;
		}
		return str;
	}
};

int main()
{

	Solution sol;
	cout << sol.countAndSay(5) << endl;
	
	system("pause");
    return 0;
}

