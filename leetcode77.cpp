// leetcode77.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (n <= 0 || k <= 0 || n < k)
			return vector<vector<int>>();
		if (n == 1) vector<vector<int>>{vector<int>{1}};
		vector<vector<int>> res;
		vector<vector<int>> allcombine;

		for (int i = 1; i <= n; ++i) {
			int size = allcombine.size();
			for (int j = 0; j < size; ++j) {
				vector<int> tmp(allcombine[j]);
				tmp.push_back(i);
				allcombine.push_back(tmp);
				if (tmp.size() == k)
					res.push_back(tmp);
			}
			allcombine.push_back(vector<int>{i});
			if (k == 1)
				res.push_back(vector<int>{i});
		}
		return res;
	}
};
*/
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		if (n <= 0 || k <= 0 || n < k)
			return vector<vector<int>>();
		vector<vector<int>> res;
		vector<int> tmp;
		productCombine(0, 0, res, tmp, n, k);
		return res;
	}
	void productCombine(int pos, int num, vector<vector<int>>& res, vector<int>& tmp, int n, int k) {
		if (num == k) {
			res.push_back(tmp);
			return;
		}
		for (int i = pos; i < n; ++i) {
			tmp.push_back(i + 1);
			productCombine(i + 1, num + 1,res, tmp, n, k);
			tmp.pop_back();
		}
	}
};
int main()
{
	Solution sol;
	vector<vector<int> > res = sol.combine(6,3);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

