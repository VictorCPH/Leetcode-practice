// leetcode109.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
	TreeNode* sortedListToBST(ListNode* head) {
		if (!head) return NULL;
		ListNode* preMid = NULL;
		ListNode* mid = head;
		ListNode* doubleMid = head;
		while (doubleMid->next && doubleMid->next->next) {
			preMid = mid;
			mid = mid->next;
			doubleMid = doubleMid->next->next;
		}
		
		TreeNode* root = new TreeNode(mid->val);
		TreeNode* left;
		if (preMid == NULL) 
			 left = NULL;
		else {
			preMid->next = NULL;
			left = sortedListToBST(head);
		}		
		TreeNode* right = sortedListToBST(mid->next);
		root->left = left;
		root->right = right;
		return root;
	}
};

int main()
{
	system("pause");
    return 0;
}

