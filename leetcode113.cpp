// leetcode113.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root) return vector<vector<int>>();
		if (!root->left && !root->right && root->val == sum)
			return vector<vector<int>>{vector<int>{root->val}};
		vector<vector<int>> res;
		vector<vector<int>> leftPath = pathSum(root->left, sum - root->val);
		vector<vector<int>> rightPath = pathSum(root->right, sum - root->val);

		for (int i = 0; i < leftPath.size(); ++i) {
			leftPath[i].insert(leftPath[i].begin(), root->val);
			res.push_back(leftPath[i]);
		}
		for (int i = 0; i < rightPath.size(); ++i) {
			rightPath[i].insert(rightPath[i].begin(), root->val);
			res.push_back(rightPath[i]);
		}
		return res;
	}
};

int main()
{
	system("pause");
    return 0;
}

