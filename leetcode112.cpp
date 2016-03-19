// leetcode112.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)  return false;
		if (!root->left && root->right)
			return hasPathSum(root->right, sum - root->val);
		if (!root->right && root->left)
			return hasPathSum(root->left, sum - root->val);
		if (!root->right && !root->left)
			return root->val == sum;
		return hasPathSum(root->right, sum - root->val)|| hasPathSum(root->left, sum - root->val);
	}
};

int main()
{
	system("pause");
    return 0;
}

