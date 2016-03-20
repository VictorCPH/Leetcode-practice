// leetcode114.cpp : 定义控制台应用程序的入口点。
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
	void flatten(TreeNode* root) {
		flattenHelp(root);
	}
private:
	TreeNode* flattenHelp(TreeNode* root) {
		if (!root)  return NULL;
		TreeNode* tmp = root->right;
		root->right = root->left;
		TreeNode* leftEnd = flattenHelp(root->left);
		root->left = NULL;
		if (leftEnd)
			leftEnd->right = tmp;
		else
			root->right = tmp;
		TreeNode* rightEnd = flattenHelp(tmp);
		if (rightEnd)
			return rightEnd;
		else
			return leftEnd == NULL ? root : leftEnd;
	}
};
int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(9);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	root->left = node2;
	root->right = node5;
	node2->left = node3;
	node2->right = node4;
	node5->right = node6;
	Solution sol;
	sol.flatten(root);
	while (root) {
		cout << root->val << " ";
		root = root->right;
	}
	system("pause");
    return 0;
}

