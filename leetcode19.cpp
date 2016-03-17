// leetcode19.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

/*
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* tempNode = head;
		ListNode* delNode = head;
		ListNode* preDelNode = NULL;
		ListNode* resNode = head;
		for (int i = 1; i < n; ++i)
			tempNode = tempNode->next;

		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
			preDelNode = delNode;
			delNode = delNode->next;
		}

		if (preDelNode == NULL) {
			resNode = delNode->next;
			delete delNode;
		}		
		else {
			preDelNode->next = delNode->next;
			delete delNode;
		}
		return resNode;
	}
};

int main()
{
    return 0;
}

