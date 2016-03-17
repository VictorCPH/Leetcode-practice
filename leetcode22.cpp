// leetcode22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		unordered_map<string, int> hashMap;
		vector<string> parenthesis;
		parenthesis.push_back("");
		hashMap[""] = 0;

		for (int i = 0; i < n; ++i) {
			int size = parenthesis.size();
			for (int k = 0; k < size; ++k) {
				string tmp = parenthesis.front();
				parenthesis.erase(parenthesis.begin());

				if (hashMap.find("()" + tmp) == hashMap.end()) {
					parenthesis.push_back("()" + tmp);
					hashMap["()" + tmp] = 0;
				}
				for (int i = 0; i < tmp.size(); ++i) {
					if (hashMap.find(tmp.substr(0, i + 1) + "()" + tmp.substr(i + 1, tmp.size())) == hashMap.end()) {
						parenthesis.push_back(tmp.substr(0, i + 1) + "()" + tmp.substr(i + 1, tmp.size()));
						hashMap[tmp.substr(0, i + 1) + "()" + tmp.substr(i + 1, tmp.size())] = 0;
					}
				}
			}
		}
		return parenthesis;
	}
};
*/

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		addStr(res, "", n, n);
		return res;

	}

	void addStr(vector<string>& res, string str, int left, int right) {
		if (left == 0 && right == 0) {
			res.push_back(str);
			return;
		}
		else if (left <= right) {
			if (left > 0)
				addStr(res, str + "(", left - 1, right);
			if (right > 0)
				addStr(res, str + ")", left, right - 1);
		}
	}
};

int main()
{
	Solution sol;
	vector<string> result = sol.generateParenthesis(4);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
	system("pause");
    return 0;
}

