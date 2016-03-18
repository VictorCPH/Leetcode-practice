// leetcode103.cpp : 定义控制台应用程序的入口点。
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector <vector<int>> res;
		if (!root) return res;
		vector<TreeNode*> access;
		access.push_back(root);
		int level = 0;
		int start = 0;
		while (access.size() > start) {
			int size = access.size();
			res.push_back(vector<int>());
	
			for (int i = start; i < size; ++i) {
				res[level].push_back(access[i]->val);
			}
			if (level % 2 == 1) {
				for (int i = size - 1; i >= start; --i) {
					if (access[i]->left)
						access.push_back(access[i]->left);
					if (access[i]->right)
						access.push_back(access[i]->right);
				}
			}
			else {
				for (int i = size - 1; i >= start; --i) {
					if (access[i]->right)
						access.push_back(access[i]->right);
					if (access[i]->left)
						access.push_back(access[i]->left);				
				}
			}
			start = size;
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
	vector<vector<int>> res = sol.zigzagLevelOrder(node1);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	system("pause");
    return 0;
}

