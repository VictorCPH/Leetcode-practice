// leetcode117.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
/**  leetcode116 and leetcode117 use same method
* Definition for binary tree with next pointer.
*/
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		vector<TreeLinkNode*> TreeVec;
		TreeVec.push_back(root);
		int index = 0;
		while (index < TreeVec.size()) {
			int size = TreeVec.size();
			int i = index;
			for (; i < size; ++i) {
				if (TreeVec[i]->left)
					TreeVec.push_back(TreeVec[i]->left);
				if (TreeVec[i]->right)
					TreeVec.push_back(TreeVec[i]->right);
				if (i < size - 1)
					TreeVec[i]->next = TreeVec[i + 1];
			}
			index = i;
		}
	}
};
int main()
{
	system("pause");
	return 0;
}
