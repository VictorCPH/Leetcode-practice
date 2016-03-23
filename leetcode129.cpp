// leetcode129.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <istream>
#include <queue>

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
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		int sum = 0;
		queue<TreeNode*> searchQueue;
		searchQueue.push(root);
		while (!searchQueue.empty()) {
			TreeNode* tmp = searchQueue.front();
			searchQueue.pop();
			if (tmp->left) {
				tmp->left->val += tmp->val * 10;
				searchQueue.push(tmp->left);
			}
			if (tmp->right) {
				tmp->right->val += tmp->val * 10;
				searchQueue.push(tmp->right);
			}
			if (!tmp->left && !tmp->right)
				sum += tmp->val;
		}
		return sum;
	}
};

int main()
{
	system("pause");
    return 0;
}

