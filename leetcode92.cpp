// leetcode92.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

/*
* definition for singly-linked list.
*/
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* firstNode = NULL;
		ListNode* curNode = head;
		ListNode* preNode = NULL;
		ListNode* tmpNode = NULL;

		for (int i = 1; i < m; ++i) {
			preNode = curNode;
			curNode = curNode->next;
		}
		m == 1 ? firstNode = head : firstNode = preNode;
		m == 1 ? preNode = head : preNode = preNode->next;
		curNode = curNode->next;
		for (int i = 0; i < n - m; ++i) {	
			if (m != 1) {
				tmpNode = firstNode->next;
				firstNode->next = curNode;
			}
			else {
				tmpNode = head;
				head = curNode;
			}
			preNode->next = curNode->next;
			curNode->next = tmpNode;
			curNode = preNode->next;
		}
		return head;
	}
};
*/
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		stack<ListNode*> pStack;
		ListNode* firstNode = head;
		ListNode* curNode = head;
		ListNode* tmpNode = NULL;
		for (int i = 1; i < m; ++i) {
			firstNode = curNode;
			curNode = curNode->next;
		}
		for (int i = 0; i <= n - m; ++i) {
			pStack.push(curNode);
			curNode = curNode->next;
		}
		while (!pStack.empty()) {
			tmpNode = pStack.top();
			if (m == 1) {
				head = tmpNode;
				pStack.pop();
				firstNode = tmpNode;
				m = 0;
			}
			else {
				firstNode->next = tmpNode;
				pStack.pop();
				firstNode = firstNode->next;
			}
		}
		firstNode->next = curNode;
		return head;
	}
};

int main()
{
	system("pause");
    return 0;
}

