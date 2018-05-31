#include "global.h"

class Solution {
	/*Question 10 矩形覆盖
	*题目描述
	*	我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	动态规划，类似于斐波那契数列。
	*	规律：F(n) = F(n-2) + F(n-1);  特殊情况：F(0) = 0; F(1) = 1; F(2) = 2;
	*/
public:
	int rectCover(int number) {
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