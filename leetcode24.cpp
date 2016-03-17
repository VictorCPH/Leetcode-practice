// leetcode24.cpp : 定义控制台应用程序的入口点。
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
	ListNode* swapPairs(ListNode* head) {
		ListNode* curNode = head;
		ListNode* preNode = NULL;
		ListNode* nextNode = NULL;

		while (curNode && curNode->next) {
			if (preNode == NULL) {
				nextNode = curNode->next;
				curNode->next = nextNode->next;
				nextNode->next = curNode;
				head = nextNode;
				preNode = curNode;
				curNode = curNode->next;
			}
			else {
				nextNode = curNode->next;
				curNode->next = nextNode->next;
				nextNode->next = curNode;
				preNode->next = nextNode;
				preNode = curNode;
				curNode = curNode->next;
			}
		}
		return head;
	}
};

int main()
{
	ListNode* head = new ListNode(1);
  /*ListNode* node1 = new ListNode(2);
	head->next = node1;
	ListNode* node2 = new ListNode(3);
	node1->next = node2;
	ListNode* node3 = new ListNode(4);
	node2->next = node3;
	*/
	Solution sol;
	head = sol.swapPairs(head);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
		
	system("pause");
    return 0;
}

