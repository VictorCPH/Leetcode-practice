// leetcode21.cpp : 定义控制台应用程序的入口点。
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

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL) return NULL;

		ListNode* l3 = new ListNode(0);
		ListNode* head = NULL;
		bool flag = true;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				l3->next = l1;
				l1 = l1->next;
			}
			else {
				l3->next = l2;
				l2 = l2->next;
			}
			l3 = l3->next;
			if (flag) {
				head = l3;
				flag = false;
			}
		}
		if (l1 == NULL)
			l1 = l2;

		l3->next = l1;
		if (head == NULL) head = l3->next;
		return head;
	}
};

int main()
{
    return 0;
}

