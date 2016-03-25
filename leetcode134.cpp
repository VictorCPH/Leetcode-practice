// leetcode134.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int i = 0;
		while (i < gas.size()) {
			int j = i;
			int sum = 0;
			bool isStart = true;
			while (j != i || isStart) {
				sum += gas[j] - cost[j];
				if (sum < 0) {
					break;
				}	
				j = (j + 1) % gas.size();
				isStart = false;
			}
			if (j == i && isStart == false)  return j;
			if (isStart)
				++i;
			else if (j > i)
				i = j;
			else
				return -1;
			
		}
		if (i == gas.size()) return -1;
	}
};

int main()
{
	vector<int> gas{ 2,4 };
	vector<int> cost{3,4 };
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	system("pause");
    return 0;
}

