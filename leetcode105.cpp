// leetcode105.cpp : 定义控制台应用程序的入口点。
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTreeHelp(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}
private:
	TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
		if (preStart > preEnd || inStart > inEnd) return NULL;
		TreeNode* root = new TreeNode(preorder[preStart]);
		int search = inStart;
		while (search <= inEnd && inorder[search] != preorder[preStart])
			++search;
		int leftCount = search - inStart;
		TreeNode* leftTreeRoot = buildTreeHelp(preorder, inorder, preStart + 1, preStart + leftCount, inStart, inStart + leftCount - 1);
		TreeNode* rightTreeRoot = buildTreeHelp(preorder, inorder, preStart + leftCount + 1, preEnd, search + 1, inEnd);
		root->left = leftTreeRoot;
		root->right = rightTreeRoot;
		return root;
	}
};

int main()
{
	system("pause");
    return 0;
}

