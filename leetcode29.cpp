// leetcode29.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
/*  超时cout << sol.divide(2147483647, 1) << endl;
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)  return INT_MAX;
		int res = 0;
		int tmp = 0;
		int dividendAbs = abs(dividend);
		int divisorAbs = abs(divisor);
		while (tmp < dividendAbs) {
			tmp += divisorAbs;
			++res;
		}
		if (tmp > dividendAbs) --res;
		return ((dividend ^ divisor) < 0) ? - res : res;
	}
};
*/
//35/3 = 11
//100011 / 011 = 1011

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))  
			return INT_MAX;

		int n = 0;
		int m = 0;
		int res = 0;
		long long divisorTmp = 0;
		long long dividendAbs = labs(dividend);//若值为INT_MIN   OJ上labs应该返回INT_MAX+1  
		long long divisorAbs = labs(divisor);//                  在本机上返回INT_MIN
		
		while (dividendAbs >= divisorAbs) {
			divisorTmp = divisorAbs;
			n = 0;
			while (divisorTmp <= dividendAbs) {
				divisorTmp <<= 1;
				++n;
			}
			divisorTmp >>= 1;
			res += 1 << (n - 1);
			dividendAbs -= divisorTmp;
		}

		return ((dividend ^ divisor) < 0) ? -res : res;
	}
};

int main()
{
	Solution sol;
	cout << sol.divide(35, 3) << endl;
	cout << sol.divide(0, 0) << endl;
	cout << sol.divide(0, 145) << endl;
	cout << sol.divide(2, 3) << endl;
	cout << sol.divide(12312, 1) << endl;
	cout << sol.divide(1, -1) << endl;
	cout << sol.divide(-9, -1) << endl;
	cout << sol.divide(-13, 3) << endl;
	system("pause"); 
    return 0;
}

