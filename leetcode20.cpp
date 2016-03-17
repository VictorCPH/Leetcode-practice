// leetcode20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> charStack;
		for (int i = 0; i < s.size(); ++i) {
			if (!charStack.empty() && 
				((charStack.top() == '(' && s[i] == ')')
			  || (charStack.top() == '[' && s[i] == ']')
			  || (charStack.top() == '{' && s[i] == '}')))
				charStack.pop();
			else
				charStack.push(s[i]);
		}
		return charStack.empty();
	}
};
int main()
{
	Solution sol;
	cout << sol.isValid("([)]");
	cout << sol.isValid("()[]");
	cout << sol.isValid("({[]})");
	cout << sol.isValid("((()))");
	system("pause");
    return 0;
}

