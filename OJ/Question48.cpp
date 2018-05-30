#include "global.h"

class Solution {
	/*Question 48 不用加减乘除做加法
	*题目描述
	*	写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	二进制中：不算进位的加法等于a异或b，进位值等于(a与b)<<1，
	*	如果进位等于0，则结束；否则将上两个数当作两个加数重复上述步骤。
	*/
public:
	int Add(int num1, int num2) {
		while (true) {
			int sum = num1 ^ num2;
			int carry = (num1 & num2) << 1;
			if (carry == 0)
				return sum;
			num1 = sum;
			num2 = carry;
		}
	}
};