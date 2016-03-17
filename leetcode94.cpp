// leetcode94.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*递归
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		traveral(root, res);
		return res;
	}
private:
	void traveral(TreeNode* root, vector<int>& res) {
		if (root == NULL)  return;
		traveral(root->left, res);
		res.push_back(root->val);
		traveral(root->right, res);
	}
};
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root)  return vector<int>();
		vector<int> res;
		stack<TreeNode*> TreeStack;
		TreeNode* curNode = root;
		while (!TreeStack.empty() || curNode) {
			if (curNode) {
				TreeStack.push(curNode);
				curNode = curNode->left;
			}
			else {
				curNode = TreeStack.top();
				res.push_back(curNode->val);
				TreeStack.pop();
				curNode = curNode->right;
			}
		}
		return res;
	}
};

int main()
{
	system("pause");
    return 0;
}

