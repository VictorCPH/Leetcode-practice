// leetcode61.cpp : 定义控制台应用程序的入口点。
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)  return NULL;
		if (k == 0)  return head;

		ListNode* searchLen = head;
		int len = 1;
		while (searchLen->next != 0) {
			searchLen = searchLen->next;
			++len;
		}

		k % len == 0 ? k = len : k = k % len;
		ListNode* tmpNode = head;
		ListNode* curNode = head;
		ListNode* lastNode = NULL;
		ListNode* newHeadNode = NULL;
		while (tmpNode->next != NULL && k > 0) {
			tmpNode = tmpNode->next;
			--k;
		}
		if (k != 0)  return head;

		while (tmpNode->next != NULL) {
			tmpNode = tmpNode->next;
			curNode = curNode->next;
		}
		lastNode = curNode;
		newHeadNode = curNode->next;
		lastNode->next = NULL;
		tmpNode->next = head;

		return newHeadNode;
	}
};

int main()
{
	system("pause");
    return 0;
}

