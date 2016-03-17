// leetcode17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return vector<string>();
		unordered_map<char, vector<char> > table;
		table['2'] = vector<char>{ 'a','b','c' };
		table['3'] = vector<char>{ 'd','e','f' };
		table['4'] = vector<char>{ 'g','h','i' };
		table['5'] = vector<char>{ 'j','k','l' };
		table['6'] = vector<char>{ 'm','n','o' };
		table['7'] = vector<char>{ 'p','q','r','s' };
		table['8'] = vector<char>{ 't','u','v' };
		table['9'] = vector<char>{ 'w','x','y','z' };
		
		vector<string> strQueue;
		strQueue.push_back("");
		for (int i = 0; i < digits.size(); ++i) {
			int size = strQueue.size();
			for (int k = 0; k < size; ++k) {
				string tmp = strQueue.front();
				strQueue.erase(strQueue.begin());
				for (int j = 0; j < table[digits[i]].size(); ++j) 
					strQueue.push_back(tmp + table[digits[i]][j]);
			}
		}	
		return strQueue;
	}
};

int main()
{
	Solution sol;
	string digits("239");
	vector<string> res = sol.letterCombinations(digits);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	system("pause");
    return 0;
}

