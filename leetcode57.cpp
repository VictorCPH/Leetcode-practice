// leetcode57.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.size() == 0) return vector<Interval>{newInterval};
		vector<Interval> res;
		int pushFlag = 1;

		if (intervals[0].start > newInterval.start && intervals[0].start > newInterval.end)
			res.push_back(newInterval);
		else if (intervals[0].start > newInterval.start)
			pushFlag = 0;

		for (int i = 0; i < intervals.size(); ++i) {
			if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start) {
				newInterval.start = intervals[i].start;
				pushFlag = 0;
			}
			else if (i + 1 < intervals.size() && intervals[i].end < newInterval.start && intervals[i + 1].start > newInterval.start) {
				pushFlag = 0;
				res.push_back(intervals[i]);
			}
			if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.end) {
				newInterval.end = intervals[i].end;
				res.push_back(newInterval);
				pushFlag = 1;
				continue;
			}
			else if (i + 1 < intervals.size() && intervals[i].end < newInterval.end && intervals[i + 1].start > newInterval.end) {
				pushFlag = 1;
				res.push_back(newInterval);
				continue;
			}
			if (pushFlag)
				res.push_back(intervals[i]);
		}
		if (intervals.back().end < newInterval.end)
			res.push_back(newInterval);
		return res;
	}
};
int main()
{
	vector<Interval> inter{ Interval(1,2),Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16) };
	Interval newInterval(7, 11);
	Solution sol;
	vector<Interval> res = sol.insert(inter, newInterval);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i].start << "," << res[i].end << endl;
	system("pause");
    return 0;
}

