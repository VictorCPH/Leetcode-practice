// leetcode98.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/**
*Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* preNode = NULL;
		return depthFirstSearch(root, preNode);	
	}
private:
	bool depthFirstSearch(TreeNode* root, TreeNode*& preNode) {
		if (!root)  return true;
		if (!depthFirstSearch(root->left, preNode))  return false;
		if (preNode != NULL && (preNode)->val >= root->val)  return false;
		preNode = root;
		return depthFirstSearch(root->right, preNode);		
	}
};
int main()
{
    return 0;
}

