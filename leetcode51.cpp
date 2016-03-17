// leetcode51.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> initial(n, 0);
		for (int i = 0; i < n; ++i)
			initial[i] = i;
		vector<vector<int>> resTmp;
		findSolution(initial, 0, resTmp);
		
		vector<vector<string>> res;
		for (int i = 0; i < resTmp.size(); ++i) {
			vector<string> oneSolution;
			for (int j = 0; j < resTmp[i].size(); ++j) {
				string str(n, '.');
				str[resTmp[i][j]] = 'Q';
				oneSolution.push_back(str);
			}
			res.push_back(oneSolution);
		}
		return res;
	}
private:
	void findSolution(vector<int>& initial, int pos, vector<vector<int>>& resTmp) {
		if (pos == initial.size() - 1) {
			if (diagonalNoConflict(initial))
				resTmp.push_back(initial);
		}
		else {
			for (int i = pos; i < initial.size(); ++i) {
				swap(initial[i], initial[pos]);
				vector<int> tmp(initial.begin(), initial.begin() + pos + 1);
				if (diagonalNoConflict(tmp))
					findSolution(initial, pos + 1, resTmp);
				swap(initial[i], initial[pos]);
			}
		}
	}

	bool diagonalNoConflict(const vector<int>& initial) {
		for (int i = 0; i < initial.size() - 1; ++i) {
			int j = initial.size() - 1;
			if (i - j == initial[i] - initial[j] ||
				i - j == initial[j] - initial[i])
				return false;
		}
		return true;
	}
};




int main()
{
	Solution sol;
	vector<vector<string>> res = sol.solveNQueens(8);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << endl;
		cout << endl;
	}
	cout << res.size();
	system("pause");
    return 0;
}

