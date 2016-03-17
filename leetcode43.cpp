// leetcode43.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.size() == 0 || num2.size() == 0)  return "";
		vector<string> tmp;
		for (int i = 0; i < num2.size(); i++) 
			tmp.push_back(multiplyOneNum(num1, num2[i]) + string(num2.size() - i - 1,'0'));

		string sum(tmp[0]);
		for (int i = 1; i < tmp.size(); ++i) 
			sum = addTwoNumbers(sum, tmp[i]);
		
		int i = 0;
		for (; i < sum.size(); ++i)
			if (sum[i] != '0')
				break;
		return i == sum.size() ? "0" : sum.substr(i, sum.size() - i);
	}
private:
	string multiplyOneNum(string num, char ch) {
		int carry = 0;
		for (int i = num.size() - 1; i >= 0; --i) {
			int product = (num[i] - '0') * (ch - '0') + carry;
			int base = product % 10;
			carry = product / 10;
			num[i] = base + '0';
		}
		return carry == 0 ? num : char(carry + '0') + num;
	}

	string addTwoNumbers(string num1, string num2) {
		int num1Len = num1.size();
		int num2Len = num2.size();

		if (num1Len < num2Len)
			num1 = string(num2Len - num1Len, '0') + num1;
		else
			num2 = string(num1Len - num2Len, '0') + num2;

		string res(num1.size(), '0');
		int carry = 0;
		for (int i = num1.size() - 1; i >= 0; i--) {		
			int sum = num1[i] - '0' + num2[i] - '0' + carry;
			res[i] = sum % 10 + '0';
			carry = sum / 10;
		}

		return carry == 0 ? res : char(carry + '0') + res;
	}
};
int main()
{
	Solution sol;
	cout << sol.multiply("9","123423") << endl;
	system("pause");
    return 0;
}

