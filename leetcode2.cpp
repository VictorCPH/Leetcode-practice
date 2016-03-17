// leetcode2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {	
		int flag = 1;
		int label = 1;
		ListNode *l3 = NULL;
		ListNode *preNode = NULL;
		ListNode *node = NULL;
		while (l1 != NULL && l2 != NULL) {
			if (label == 1)
				node = new ListNode(0);
			else
				node = new ListNode(1);
			if (flag == 0)
				preNode->next = node;
			if (flag == 1) {
				l3 = node;
				flag = 0;
			}
			int tmp = l1->val + l2->val + node->val;
			if (tmp < 10) {
				node->val = tmp;	
				label = 1;
			}
			else {
				node->val = tmp % 10;
				label = 0;
			}
			preNode = node;
			l1 = l1->next;
			l2 = l2->next;
		}

		if (l1 == NULL)
			l1 = l2;

		preNode->next = l1;
		while (label == 0 && l1 != NULL) {
			if (l1->val != 9) {
				l1->val++;
				label = 1;
			}
			else {
				l1->val = 0;
				preNode = l1;
				l1 = l1->next;
			}
		}

		if (label == 0) {
			node = new ListNode(1);
			preNode->next = node;
		}
		return l3;
	}
};

int main()
{
	ListNode *l1;
	ListNode *node;
	node = new ListNode(2);
	l1 = node;
	node = new ListNode(4);
	l1->next = node;


	ListNode *l2;
	node = new ListNode(5);
	l2 = node;
	node = new ListNode(6);
	l2->next = node;
	node = new ListNode(9);
	l2->next->next = node;

	Solution solution;
	ListNode *l3 = solution.addTwoNumbers(l1, l2);
	while (l3 != NULL) {
		cout << l3->val << " ";
		l3 = l3->next;
	}
	system("pause");
    return 0;
}

