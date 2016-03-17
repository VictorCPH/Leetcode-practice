// leetcode79.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (word.size() == 0) return false;
		int width = board.size();
		if (width == 0) return false;
		int length = board[0].size();
		if (length == 0) return false;
		if (word.size() > length * width) return false;

		vector<vector<char>> copy(board);
		for (int i = 0; i < width; ++i)
			for (int j = 0; j < length; ++j) {
				if (board[i][j] == word[0])
					if (isExist(board, i, j, 0, word, length, width)) 
						return true;
				board = copy;
			}
							
		return false;
	}
private:
	bool isExist(vector<vector<char>>& board, int i, int j, int num, string& word, int length, int width) {
		if (board[i][j] == word[num] && num == word.size() - 1)
			return true;
		
		char save = board[i][j];
		if (board[i][j] == word[num]) {
			board[i][j] = '\0';
			if (j - 1 >= 0 && isExist(board, i, j - 1, num + 1, word, length, width)) {
				return true;
			}
			if (j + 1 <= length - 1 && isExist(board, i, j + 1, num + 1, word, length, width)) {
				return true;
			}
			if (i - 1 >= 0 && isExist(board, i - 1, j, num + 1, word, length, width)) {
				return true;
			}
			if (i + 1 <= width - 1 && isExist(board, i + 1, j, num + 1, word, length, width)) {
				return true;
			}
			else {
				board[i][j] = save;
				return false;
			}
		}
		else
			return false;
	}
};
*/
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int width = board.size();
		int length = board[0].size();

		vector<vector<char>> copy(board);
		for (int i = 0; i < width; ++i)
			for (int j = 0; j < length; ++j) {
				if (board[i][j] == word[0])
					if (isExist(board, i, j, 0, word, length, width))
						return true;
			}

		return false;
	}
private:
	bool isExist(vector<vector<char>>& board, int i, int j, int num, string& word, int length, int width) {
		if (board[i][j] == word[num] && num == word.size() - 1)
			return true;

		char save = board[i][j];
		if (board[i][j] == word[num]) {
			board[i][j] = '\0';
			if (j - 1 >= 0 && isExist(board, i, j - 1, num + 1, word, length, width)) {
				return true;
			}
			if (j + 1 <= length - 1 && isExist(board, i, j + 1, num + 1, word, length, width)) {
				return true;
			}
			if (i - 1 >= 0 && isExist(board, i - 1, j, num + 1, word, length, width)) {
				return true;
			}
			if (i + 1 <= width - 1 && isExist(board, i + 1, j, num + 1, word, length, width)) {
				return true;
			}
			else {
				board[i][j] = save;
				return false;
			}
		}
		else
			return false;
	}
};
int main()
{
	vector<vector<char>> board{ {'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'} };
	string word = "ABCESEEEFSB";
	Solution sol;
	cout << sol.exist(board, word) << endl;
	system("pause");
    return 0;
}

