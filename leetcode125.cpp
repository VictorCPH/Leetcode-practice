// leetcode125.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			while (i < j && !isdigit(s[i]) && !isalpha(s[i])) ++i;
			while (i < j && !isdigit(s[j]) && !isalpha(s[j])) --j;
			if (tolower(s[i]) != tolower(s[j]))
				return false;
			++i;
			--j;
		}
		return true;
	}
};
int main()
{	
	Solution sol;
	cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << sol.isPalindrome("race a car") << endl;
	system("pause");
    return 0;
}

