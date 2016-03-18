// leetcode102.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)  return vector<vector<int>>();
		vector<vector<int>> res;
		queue<TreeNode*> accessQueue;
		accessQueue.push(root);
		int level = 0;
		while (accessQueue.size() != 0) {
			int size = accessQueue.size();
			res.push_back(vector<int>());
			for (int i = 0; i < size; ++i) {
				TreeNode* tmp = accessQueue.front();
				res[level].push_back(tmp->val);
				accessQueue.pop();
				if (tmp->left)
					accessQueue.push(tmp->left);
				if (tmp->right)
					accessQueue.push(tmp->right);
			}
			++level;
		}
		return res;
	}
};
int main()
{
	TreeNode* node1 = new TreeNode(3);
	TreeNode* node2 = new TreeNode(9);
	TreeNode* node3 = new TreeNode(20);
	TreeNode* node4 = new TreeNode(15);
	TreeNode* node5 = new TreeNode(7);
	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;
	Solution sol;
	vector<vector<int>> res = sol.levelOrder(node1);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

