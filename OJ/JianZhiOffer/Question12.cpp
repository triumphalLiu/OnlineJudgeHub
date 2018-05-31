#include "global.h"

class Solution {
	/*Question 12 数值的整数次方
	*题目描述
	*	给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	快速幂方法: 2^10 = 1*2^10 = 1*4^5 = 4*4^4 = 4*16^2 = ...
	*	需要的乘法运算次数等于exponent的二进制数的位数
	*	Hint:对于非负数，判断奇偶性的最佳办法是 (n & 1) true=奇数；false=偶数。
	*/
public:
	double Power(double base, int exponent) {
		if (!exponent) return 1;
		long long exp = (long long)(exponent < 0 ? -exponent : exponent);
		double result = 1;
		while (exp) {
			if (exp & 1) {
				result *= base;
			}
			base *= base; 
			exp >>= 1;
		}
		return exponent < 0 ? 1 / result : result;
	}
};