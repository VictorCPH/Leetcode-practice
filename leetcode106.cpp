// leetcode106.cpp : 定义控制台应用程序的入口点。
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTreeHelp(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
	}
private:
	TreeNode* buildTreeHelp(vector<int>& postorder, vector<int>& inorder, int postStart, int postEnd, int inStart, int inEnd) {
		if (postStart > postEnd || inStart > inEnd) return NULL;
		TreeNode* root = new TreeNode(postorder[postEnd]);
		int search = inStart;
		while (search <= inEnd && inorder[search] != postorder[postEnd])
			++search;
		int leftCount = search - inStart;
		TreeNode* leftTreeRoot = buildTreeHelp(postorder, inorder, postStart, postStart + leftCount - 1, inStart, inStart + leftCount - 1);
		TreeNode* rightTreeRoot = buildTreeHelp(postorder, inorder, postStart + leftCount, postEnd - 1, search + 1, inEnd);
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

