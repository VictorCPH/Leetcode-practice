// leetcode73.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = 1, column = 1;
		int rowsCount = matrix.size();
		int columnsCount = matrix[0].size();

		for (int i = 0; i < rowsCount; ++i)
			if (matrix[i][0] == 0) {
				row = 0;
				break;
			}

		for (int j = 0; j < columnsCount; ++j)
			if (matrix[0][j] == 0) {
				column = 0;
				break;
			}

		for (int i = 1; i < rowsCount; ++i)
			for (int j = 1; j < columnsCount; ++j)
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}

		for (int i = 1; i < rowsCount; ++i)
			for (int j = 1; j < columnsCount; ++j) 
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			
		if (row == 0)
			for (int i = 0; i < rowsCount; ++i)
				matrix[i][0] = 0;
		if (column == 0)
			for (int j = 0; j < columnsCount; ++j)
				matrix[0][j] = 0;
	}
};

int main()
{
	system("pause");
    return 0;
}

