// leetcode71.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		string res, tmp;
		vector<string> stk;
		stringstream ss(path);
		while (getline(ss, tmp, '/')) {
			if (tmp == "" || tmp == ".") continue;
			if (tmp == ".." && !stk.empty()) stk.pop_back();
			else if (tmp != "..") stk.push_back(tmp);
		}
		for (auto str : stk) res += "/" + str;
		return res.empty() ? "/" : res;
	}
};

int main()
{
	Solution sol;
	cout << sol.simplifyPath("/") << endl;
	cout << sol.simplifyPath("/home/") << endl;
	cout << sol.simplifyPath("/a/./b/../../c/") << endl;
	cout << sol.simplifyPath("/../") << endl;
	cout << sol.simplifyPath("/.../////..../../") << endl;
	cout << sol.simplifyPath("/home/////foo/") << endl;
	cout << sol.simplifyPath("/......./") << endl;
	cout << sol.simplifyPath("/.") << endl;
	cout << sol.simplifyPath("/..") << endl;
	cout << sol.simplifyPath("/...") << endl;
	cout << sol.simplifyPath("/....") << endl;
	cout << sol.simplifyPath("/.....") << endl;
	cout << sol.simplifyPath("/.........") << endl;
	cout << sol.simplifyPath("/./") << endl;
	cout << sol.simplifyPath("/.../") << endl;
	cout << sol.simplifyPath("/home/of/foo/../../bar/../../is/./here/.") << endl;
	cout << sol.simplifyPath("/.hidden") << endl;
	system("pause");
    return 0;
}

