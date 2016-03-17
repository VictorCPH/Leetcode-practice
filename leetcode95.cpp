// leetcode95.cpp : 定义控制台应用程序的入口点。
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
	vector<TreeNode*> generateTrees(int n) {
		return generateRoots(1, n);
	}
private:
	vector<TreeNode*> generateRoots(int start, int end) {
		vector<TreeNode*> res;	
		for (int i = start; i <= end; ++i) {
			vector<TreeNode*> leftRoots = generateRoots(start, i - 1);
			vector<TreeNode*> rightRoots = generateRoots(i + 1, end);
			if (leftRoots.size() != 0 && rightRoots.size() != 0) {
				for (int j = 0; j < leftRoots.size(); ++j) {
					TreeNode* left = leftRoots[j];
					for (int k = 0; k < rightRoots.size(); ++k) {
						TreeNode* right = rightRoots[k];
						TreeNode* root = new TreeNode(i);
						root->left = left;
						root->right = right;
						res.push_back(root);
					}
					
				}
			}
			else if (leftRoots.size() == 0 && rightRoots.size() != 0){
				for (int k = 0; k < rightRoots.size(); ++k) {
					TreeNode* right = rightRoots[k];
					TreeNode* root = new TreeNode(i);
					root->right = right;
					res.push_back(root);
				}
			}
			else if (rightRoots.size() == 0 && leftRoots.size() != 0) {
				for (int j = 0; j < leftRoots.size(); ++j) {
					TreeNode* left = leftRoots[j];
					TreeNode* root = new TreeNode(i);
					root->left = left;
					res.push_back(root);
				}
			}
			else {
				TreeNode* root = new TreeNode(i);
				res.push_back(root);
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	vector<TreeNode*> res = sol.generateTrees(3);
	for (int i = 0; i < res.size(); ++i) {
		TreeNode* search = res[i];
		cout << res[i]->val << endl;
	}
	system("pause");
    return 0;
}

