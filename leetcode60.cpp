// leetcode60.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		if (k <= 0 || n <= 0 || k > factorial(n)) return "";
		string str(n, '0');
		string res;
		for (int i = 0; i < str.size(); ++i)
			str[i] = i + 1 + '0';
		
		for (int i = n - 1; i >= 1; --i) {
			int fac = factorial(i);
			int num = (k - 1) / fac;
			res.push_back(str[num]);
			str.erase(num, 1);
			k = k - fac * num;
		}
		res.push_back(str[0]);
		return res;
	}
private:
	int factorial(int m) {
		int factorial = 1;
		for (int i = 1; i <= m; ++i)
			factorial *= i;
		return factorial;
	}
};
int main()
{
	Solution sol;
	cout << sol.getPermutation(4, 6) << endl;
	system("pause");
    return 0;
}

