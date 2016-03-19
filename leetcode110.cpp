// leetcode110.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

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
	bool isBalanced(TreeNode* root) {
		int high;
		return isBalanced(root, high);
	}
private:
	bool isBalanced(TreeNode* root, int& high) {
		if (!root) {
			high = 0;
			return true;
		}
		int leftHigh = 0;
		int rightHigh = 0;
		if (isBalanced(root->left, leftHigh) && isBalanced(root->right, rightHigh))
			if (abs(leftHigh - rightHigh) <= 1) {
				high = max(leftHigh, rightHigh) + 1;
				return true;
			}
		high = max(leftHigh, rightHigh) + 1;
		return false;
	}
};
int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(4);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	root->left = node2;
	root->right = node6;
	node2->left = node1;
	node2->right = node3;
	node6->left = node5;
	node6->right = node7;
	cout << sol.isBalanced(root) << endl;
	system("pause");
    return 0;
}

