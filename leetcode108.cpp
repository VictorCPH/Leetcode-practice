// leetcode108.cpp : 定义控制台应用程序的入口点。
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}
private:
	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
		if (end - start < 0)  return NULL;
		int mid = (end + start) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		TreeNode* left = sortedArrayToBST(nums, start, mid - 1);
		TreeNode* right = sortedArrayToBST(nums, mid + 1, end);
		root->left = left;
		root->right = right;
		return root;
	}
};

void PrintNode(TreeNode* root) 
{
	if (!root) return;
	PrintNode(root->left);
	cout << root->val << " ";
	PrintNode(root->right);
}
int main()
{
	vector<int> nums{ 1,2,3,4,5,6,7 };
	Solution sol;
	TreeNode* root = sol.sortedArrayToBST(nums);
	PrintNode(root);
	system("pause");
    return 0;
}

