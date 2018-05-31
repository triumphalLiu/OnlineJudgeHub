#include "global.h"

class Solution {
	/*Question 43 左旋转字符串
	*题目描述
	*	汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
	*	对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	XY=(X^T Y^T)^T  A^T表示A的转置，A="ABC" A^T="CBA"
	*/
public:
	void reverseString(string &str, int begin, int end) {
		for (int i = 0; i < (end - begin + 1) / 2; ++i) {
			int temp = str[begin + i];
			str[begin + i] = str[end - i];
			str[end - i] = temp;
		}
	}

	string LeftRotateString(string str, int n) {
		if (str.length() <= 1) return str;
		n %= str.length();
		if (n == 0) return str;
		reverseString(str, 0, n-1);
		reverseString(str, n, str.length()-1);
		reverseString(str, 0, str.length()-1);
		return str;
	}

	/*Use For Debug*/
	int Debug() {
		cout << LeftRotateString("abcXYZdef", 3) << endl;
		return 0;
	}
};