#include "global.h"

class Solution {
	/*Question 53 表示数值的字符串
	*题目描述
	*	请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
	*	例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	一个数字要满足以下条件：
	*	加减号：如果没有遇到e/E，那么只能出现一次且必须在第0位。如果遇到e/E，则必须出现在e/E之后1位。
	*	小数点：只能出现在e/E之前且最多只能有一位。
	*	E/e：只能出现一次且不能在第一位，且后面不能是字符串结尾。
	*	其他符号：如果不属于0-9，则不是数字。
	*/
public:
	bool isNumeric(char* str) {
		if (strlen(str) == 0 || str[0] == 'E' || str[0] == 'e') return false;
		bool isAfterE = false, pointExist = false, flagExist = false;
		for (int i = 0; i < strlen(str); ++i) {
			if (str[i] == '+' || str[i] == '-') {
				if (isAfterE) {
					if (str[i - 1] != 'E' && str[i - 1] != 'e')
						return false;
				}
				else if (flagExist)
					return false;
				else if (!flagExist && i > 0)
					return false;
				flagExist = true;
			}
			else if (str[i] == '.') {
				if (isAfterE || pointExist)
					return false;
				pointExist = true;
			}
			else if (str[i] == 'E' || str[i] == 'e') {
				if (isAfterE || i == strlen(str) - 1)	
					return false;
				isAfterE = true;
			}
			else if(str[i] < '0' || str[i] > '9') 
				return false;
		}
		return true;
	}

	/*Use For Debug*/
	int Debug() {
		Solution s;
		char arr[4] = "1e2";
		cout << s.isNumeric(arr) << endl;
		return 0;
	}
};