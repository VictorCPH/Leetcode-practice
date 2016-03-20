// leetcode121.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxProfit = 0;
		int minVal = INT_MAX;
		for (int i = 0; i < prices.size(); ++i) {
			maxProfit = max(maxProfit, prices[i] - minVal);
			minVal = min(minVal, prices[i]);
		}
		return maxProfit;
	}
};

int main()
{
	system("pause");
    return 0;
}

