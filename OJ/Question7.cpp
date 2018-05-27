#include "global.h"

class Solution {
	/*Question 7 斐波那契数列
	*题目描述
	*	大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。(n<=39)
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	直接按顺序运算，并且仅保存当前和上一步的值，//递归会有大量重复计算。
	*	Note:牛客网的剑指offer里面，FibonacciArr[0] = 0, FibonacciArr[1] = FibonacciArr[2] = 1。
	*/
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		int before = 0, after = 1;
		while (--n) {
			after += before;
			before = after - before;
		}
		return after;
	}
};