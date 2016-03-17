// leetcode49.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.size() == 0)  return vector<vector<string>>();

		unordered_map < string, vector<string>> table;
		for (int i = 0; i < strs.size(); ++i) {
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			if (table.find(tmp) == table.end())
				table[tmp] = vector<string>();
			table[tmp].push_back(strs[i]);
		}
		
		vector<vector<string>> res;
		for (unordered_map < string, vector<string>>::iterator iter = table.begin();
			iter != table.end(); ++iter) {
			sort(iter->second.begin(), iter->second.end());
			res.push_back(iter->second);
		}
		return res;
	}
};

int main()
{

	system("pause");
    return 0;
}

