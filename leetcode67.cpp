// leetcode67.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int carry = 0;
		int sum = 0;
		if (max(a.size(), b.size()) == a.size())
			b = string(a.size() - b.size(), '0') + b;
		else 
			a = string(b.size() - a.size(), '0') + a;
		string res(a.size() + 1, '0');

		for (int i = a.size() - 1; i >= 0; --i) {
			sum = a[i] + b[i] - '0' - '0' + carry;
			res[i + 1] = sum % 2 + '0';
			carry = sum / 2;
		}
		if (carry == 0)
			res.erase(res.begin());
		else
			res[0] = carry + '0';
		
		return res;
	}
};
int main()
{
	Solution sol;
	cout << sol.addBinary("1", "1") << endl;
	system("pause");
    return 0;
}

