#include "global.h"

class Solution {
	/*Question 47 求1+2+3+...+n
	*题目描述
	*	求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	脑洞方式一、创建一个bool数组（gcc可用，但标准c++不可用，因为创建静态数组不能使用常量），使用sizeof关键字实现乘法运算。
	*	正常方式二、通过逻辑与/逻辑或的短路求值特性实现if的功能终止递归;
	*/
public:
	int Sum_Solution(int n) {
		int sum = n;
		sum && (sum += (Sum_Solution(n - 1)));
		return sum;
	}
};