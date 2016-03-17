// leetcode58.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0) return 0;
		int count = 0;
		bool isContinue = true;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] != ' ') {
				count++;
				isContinue = false;
			}
			else if (!isContinue) break;
		}
		return count;
	}
};

int main()
{
	Solution sol;
	cout << sol.lengthOfLastWord("");
	cout << sol.lengthOfLastWord("  ");
	cout << sol.lengthOfLastWord(" asd");
	cout << sol.lengthOfLastWord("asdas asdsa a ");
	cout << sol.lengthOfLastWord("ads  ");
	cout << sol.lengthOfLastWord("ads sad asds");
	system("pause");
	return 0;
}


