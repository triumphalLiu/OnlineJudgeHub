#include "global.h"

class Solution {
	/*Question 11 二进制中1的个数
	*题目描述
	*	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	非零数字n最右边的1，在和n-1进行按位与运算后，会变成0，因此能进行几次循环，就有几个1
	*/
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= n - 1;
			++count;
		}
		return count;
	}
};