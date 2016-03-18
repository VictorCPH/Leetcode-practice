// leetcode107.cpp : 定义控制台应用程序的入口点。
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		depthFirstSearch(root, res, 0);
		return vector<vector<int>>(res.rbegin(), res.rend());
	}
private:
	void depthFirstSearch(TreeNode* root, vector<vector<int>>& res, int level) {
		if (!root) return;
		if (level == res.size())
			res.push_back(vector<int>());
		res[level].push_back(root->val);
		depthFirstSearch(root->left, res, level + 1);	
		depthFirstSearch(root->right, res, level + 1);	
	}
};
int main()
{
	system("pause");
    return 0;
}

