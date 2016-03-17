// leetcode50.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
using namespace std;
/* 递归  数据太大超时
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)  return 1.0;
		
		if (n % 2 == 0)
			return myPow(x, n / 2)*myPow(x, n / 2);
		else
			return myPow(x, n / 2)*myPow(x, n / 2) * x;
	}
};
*/

class Solution {
public:
	double myPow(double x, int n) {
		unordered_map<int, double> record;
		if (n >= 0)
			return savePow(x, n, record);
		else
			return 1 / savePow(x, n, record);
	}

	double savePow(double x, int n, unordered_map<int, double> record) {
		if (n == 0)  return 1.0;

		if (record.find(n / 2) != record.end()) {
			if (n % 2 == 0)
				return record[n / 2] * record[n / 2];
			else
				return  record[n / 2] * record[n / 2] * x;
		}
		else {
			double tmp = savePow(x, n / 2, record);
			if (n % 2 == 0)
				return tmp * tmp;
			else
				return tmp * tmp * x;
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.myPow(3,-9) << endl;
	system("pause");
    return 0;
}

