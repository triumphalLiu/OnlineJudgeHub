#include "global.h"

class Solution {
	/*Question 8
	*题目描述
	*	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	动态规划，类似于斐波那契数列。
	*	规律：F(n) = F(n-2) + F(n-1);  特殊情况：F(0) = 0; F(1) = 1; F(2) = 2;
	*/
public:    
	int jumpFloor(int number) {
		if (number <= 2)
			return number;
		int before = 1, after = 2;
		number -= 1;
		while (--number) {
			after += before;
			before = after - before;
		}
		return after;
	}
};