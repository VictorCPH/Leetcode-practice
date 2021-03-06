// leetcode82.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL)  return head;
		ListNode* preNode = NULL;
		ListNode* curNode = head;
		ListNode* nextNode = curNode->next;

		while (nextNode != NULL) {
			if (curNode->val == nextNode->val) {
				while (nextNode != NULL && curNode->val == nextNode->val) {
					curNode->next = nextNode->next;
					delete nextNode;
					nextNode = curNode->next;
				}
				if (preNode != NULL) {
					preNode->next = nextNode;
					delete curNode;
					curNode = nextNode;
					if (nextNode != NULL)
						nextNode = nextNode->next;
				}
				else {
					head = nextNode;
					delete curNode;
					curNode = nextNode;
					if (nextNode != NULL)
						nextNode = nextNode->next;
				}
			}
			else {
				preNode = curNode;
				curNode = curNode->next;
				nextNode = nextNode->next;
			}
		}
		return head;
	}
};

int main()
{
	system("pause");
    return 0;
}

