// leetcode52.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<int> initial(n, 0);
		for (int i = 0; i < n; ++i)
			initial[i] = i;
		int count = 0;
		findSolution(initial, 0, count);
		return count;
	}
private:
	void findSolution(vector<int>& initial, int pos, int& count) {
		if (pos == initial.size()) {
			++count;
		}
		else {
			for (int i = pos; i < initial.size(); ++i) {
				swap(initial[i], initial[pos]);
				vector<int> tmp(initial.begin(), initial.begin() + pos + 1);
				if (diagonalNoConflict(tmp))
					findSolution(initial, pos + 1, count);
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
	cout << sol.totalNQueens(8) << endl;
	system("pause");
	return 0;
}


