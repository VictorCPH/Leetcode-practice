// leetcode86.cpp : 定义控制台应用程序的入口点。
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
	ListNode* partition(ListNode* head, int x) {
		ListNode* preNode1 = NULL;
		ListNode* curNode1 = head;
		ListNode* preNode2 = NULL;
		ListNode* curNode2 = head;
		ListNode* tmp = NULL;

		while (curNode1 != NULL && curNode2 != NULL) {
			if (curNode1->val >= x) {
				if (curNode1->next == NULL) break;
				preNode2 = curNode1;
				curNode2 = curNode1->next;
				while (curNode2 != NULL && curNode2->val >= x) {
					preNode2 = preNode2->next;
					curNode2 = curNode2->next;
				}
				if (curNode2 == NULL) break;
				if (preNode1 != NULL) {
					preNode1->next = curNode2;
					preNode1 = preNode1->next;
				}
				else {
					head = curNode2;
					preNode1 = head;		
				}
				preNode2->next = curNode2->next;
				curNode2->next = curNode1;
				curNode2 = preNode2->next;		
			}
			else {
				preNode1 = curNode1;
				curNode1 = curNode1->next;
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

