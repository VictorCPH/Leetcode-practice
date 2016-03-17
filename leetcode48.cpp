// leetcode48.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int size = matrix.size();
		for (int i = 0; i < size / 2; ++i)
			for (int j = 0; j < size; ++j)
				swap(matrix[i][j], matrix[size - i - 1][j]);

		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				swap(matrix[i][j], matrix[j][i]);
	}
};
int main()
{
	Solution sol;
	vector<vector<int>> matrix{ };

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	sol.rotate(matrix);

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size(); ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

