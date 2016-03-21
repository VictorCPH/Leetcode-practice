// leetcode56.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* Definition for an interval.
*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), compare);
		if (intervals.size())
			res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i].start <= res.back().end && intervals[i].end > res.back().end)
				res[res.size() - 1] = Interval(res.back().start, intervals[i].end);
			else if (intervals[i].start > res.back().end) {
				res.push_back(intervals[i]);
			}
		}
		return res;
	}

	static bool compare(const Interval inter1, const Interval inter2) {
		return inter1.start < inter2.start;
	}
};

int main()
{
	vector<Interval> inter{ Interval(1,3),Interval(2,6) ,Interval(8,10) ,Interval(15,18) };
	Solution sol;
	vector<Interval> res = sol.merge(inter);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i].start << "," << res[i].end << endl;
	system("pause");
    return 0;
}

