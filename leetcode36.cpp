// leetcode36.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		const int length = 9;
		int hasAppear[10] = { 0 };
		for (int i = 0; i < length; i++) {
			memset(hasAppear, 0, 10 * sizeof(int));
			for (int j = 0; j < length; ++j) {
				if (board[i][j] != '.') {
					if (hasAppear[board[i][j] - '0'] == 0)
						hasAppear[board[i][j] - '0'] = 1;
					else {
						cout << 'a' << " " <<  i << " " << j << " " << board[i][j] - '0' << " " << hasAppear[board[i][j] - '0'] << endl;
						return false;
					}
				}
			}
		}

		for (int j = 0; j < length; j++) {
			memset(hasAppear, 0, 10 * sizeof(int));
			for (int i = 0; i < length; ++i) {
				if (board[i][j] != '.') {
					if (hasAppear[board[i][j] - '0'] == 0)
						hasAppear[board[i][j] - '0'] = 1;
					else {
						cout << 'b' << " " << i << " " << j << " " << endl;
						return false;
					}
				}
			}
		}

		for (int m = 0; m < 9; m += 3) {
			for (int n = 0; n < 9; n += 3) {
				memset(hasAppear, 0, 10 * sizeof(int));
				for (int i = m; i < m + 3; i++) {
					for (int j = n; j < n + 3; ++j) {
						if (board[i][j] != '.') {
							if (hasAppear[board[i][j] - '0'] == 0)
								hasAppear[board[i][j] - '0'] = 1;
							else {
								cout << 'c' << " " << i << " " << j << " " << endl;
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
};
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rows[9][9] = { 0 }, columns[9][9] = { 0 }, subBoxs[9][9] = { 0 };

		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0' - 1;
					int k = i / 3 * 3 + j / 3;
					if (rows[i][num] || columns[j][num] || subBoxs[k][num])
						return false;
					rows[i][num] = columns[j][num] = subBoxs[k][num] = 1;
				}
			}
		return true;
	}
};

int main()
{
	Solution sol;
	vector<string> board{ ".87654321","2........","3........","4........","5........","6........","7........","8........","9........" };
	//cout << sol.isValidSudoku(board) << endl;
	system("pause");
    return 0;
}

