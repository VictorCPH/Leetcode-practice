// leetcode133.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
* Definition for undirected graph.
*/
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> haveNodes;
		return cloneGraphHelp(node, haveNodes);
	}
private:
	UndirectedGraphNode *cloneGraphHelp(UndirectedGraphNode *node, 
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>& haveNodes) {
		if (!node)  return NULL;
		if (haveNodes.find(node) == haveNodes.end()) {
			haveNodes[node] = new UndirectedGraphNode(node->label);;
			for (int i = 0; i < node->neighbors.size(); ++i) {
				haveNodes[node]->neighbors.push_back(cloneGraphHelp(node->neighbors[i], haveNodes));
			}
		}
		return haveNodes[node];
	}
};

int main()
{
	system("pause");
    return 0;
}

