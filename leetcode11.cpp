// leetcode11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int low = 0;
		int high = height.size() - 1;
		int maxArea = 0;
		while (low < high) {
			int Area = (high - low) * min(height[low], height[high]);
			if (Area > maxArea)
				maxArea = Area;
			if (height[low] < height[high])
				++low;
			else
				--high;
		}
		return maxArea;
	}
};

int main()
{
	Solution sol;
	vector<int> height = {1,2,3,4,5,6};
	cout << sol.maxArea(height) << endl;
	system("pause");
    return 0;
}

