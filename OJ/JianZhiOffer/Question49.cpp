#include "global.h"

class Solution {
	/*Question 49 把字符串转换成整数
	*题目描述
	*	将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	对字符串的每一位进行遍历，如果是特殊符号，则判断是否是第一位且是否是加减号，否则不是合法数值；
	*	如果是数字，那么保存下来，并在下一次计算开始前乘10.
	*	最后将符号和数字相乘即可。
	*/
public:
	int StrToInt(string str) {
		if (str.length() == 0) return 0;
		int result = 0, sign = 1;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				result *= 10;
				result += (str[i] - '0');
			}
			else {
				if (i == 0 && str[i] == '-')
					sign = -1;
				else if (i == 0 && str[i] == '+')
					sign = 1;
				else return 0;
			}
		}
		return sign * result;
	}
};