// leetcode101.cpp : 定义控制台应用程序的入口点。
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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return isSymmetricSub(root->left, root->right);
	}
private:
	bool isSymmetricSub(TreeNode* left, TreeNode* right) {
		if (left == NULL && right != NULL) return false;
		if (left != NULL && right == NULL) return false;
		if (left == NULL && right == NULL) return true;
		if (left->val != right->val)  return false;
		return isSymmetricSub(left->left, right->right) && isSymmetricSub(left->right, right->left);
	}
};
int main()
{
	system("pause");
    return 0;
}

