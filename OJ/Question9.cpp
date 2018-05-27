#include "global.h"

class Solution {
	/*Question 9 变态跳台阶
	*题目描述
	*	一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	动态规划，类似于斐波那契数列。
	*	规律：F(n) = F(n-1) + F(n-2) + ... + F(1) + 1;  特殊情况：F(1) = 1; F(2) = 2;
	*	容易发现这是一个等比数列，以2为公比。
	*/
public:
	int jumpFloorII(int number) {
		if (number <= 2)
			return number;
		int sum = 1;
		while (--number)
			sum *= 2;
		return sum;
	}
};