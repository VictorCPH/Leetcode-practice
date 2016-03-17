// leetcode8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int result = 0;
		int index = 0;
		int sysbol = 1;
		while (index < str.size() && str[index] == ' ')
			++index;

		if (isdigit(str[index]) || str[index] == '+' || str[index] == '-') {
			if (str[index] == '+' || str[index] == '-') {
				if (str[index] == '-')
					sysbol = -1;
				++index;
			}
			while (isdigit(str[index])) {			
				if (result > INT_FAST32_MAX / 10 || (result == INT_FAST32_MAX / 10 && str[index] - '0' > 7))
					return sysbol == 1 ? INT_FAST32_MAX : INT_FAST32_MIN;
				result = result * 10 + str[index++] - '0';
			}
			return result * sysbol;
		}
		else
			return 0;
	}
};

//OJ上 要使用 INT_MAX   INT_MIN 否则不对
int main()
{
	Solution sol;
	cout << sol.myAtoi("-2147483649")<<endl;
	system("pause");
    return 0;
}

