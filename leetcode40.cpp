// leetcode40.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> tmp;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i) {
			if (candidates[i] > target)  break;
			int size = tmp.size();
			for (int j = 0; j < size; ++j) {
				int sum = 0;
				bool isContinue = true;
				for (int k = 0; k < tmp[j].size(); ++k) {
					sum += tmp[j][k];
					if (sum + candidates[i] > target) {
						isContinue = false;
						break;
					}			
				}
				if (!isContinue) continue;
				vector<int> copy(tmp[j]);
				copy.push_back(candidates[i]);
				if (find(tmp.begin(), tmp.end(), copy) == tmp.end()) 
					tmp.push_back(copy);
			}
			vector<int> single{ candidates[i] };
			if (find(tmp.begin(), tmp.end(), single) == tmp.end()) 
				tmp.push_back(single);
		}
		
		for (int i = 0; i < tmp.size(); ++i) {
			int sum = 0;
			for (int j = 0; j < tmp[i].size(); ++j)
				sum += tmp[i][j];
			if (sum == target)
				res.push_back(tmp[i]);
		}
		return res;
	}
};
*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> tmp;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		for (int i = 0; i < candidates.size(); ++i) {
			if (candidates[i] > target)  break;
			int size = tmp.size();
			for (int j = 0; j < size; ++j) {
				int sum = 0;
				bool isContinue = true;
				for (int k = 0; k < tmp[j].size(); ++k) {
					sum += tmp[j][k];
					if (sum + candidates[i] > target) {
						isContinue = false;
						break;
					}
				}
				if (!isContinue) continue;
				vector<int> copy(tmp[j]);
				copy.push_back(candidates[i]);
				tmp.push_back(copy);
			}
			vector<int> single{ candidates[i] };
			tmp.push_back(single);
			while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
				++i;
		}

		for (int i = 0; i < tmp.size(); ++i) {
			int sum = 0;
			for (int j = 0; j < tmp[i].size(); ++j)
				sum += tmp[i][j];
			if (sum == target)
				res.push_back(tmp[i]);
		}
		return res;
	}
};

int main()
{
	vector<int> candidates{3,4,7,8 };
	int target = 11;

	Solution sol;
	vector<vector<int>> res = sol.combinationSum2(candidates, target);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

