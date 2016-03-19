// leetcode111.cpp : 定义控制台应用程序的入口点。
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
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left)
			return minDepth(root->right) + 1;
		if (!root->right)
			return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};

int main()
{
    return 0;
}

