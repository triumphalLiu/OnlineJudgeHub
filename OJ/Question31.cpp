#include "global.h"

class Solution {
	/*Question 31 整数中1出现的次数（从1到n整数中1出现的次数）
	*题目描述
	*	算出1~1300的整数中1出现的次数？并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	从右到左分析各位数，位数从1开始，对于每一位，有如下规律： （对于12345，当前位为3来说，高位数=12，低位数＝45）
	*	1. 如果第i位上的数字为0，则第i位可能出现1的次数由更高位决定，count += 高位数 * 10^(i-1)。
	*	2. 如果第i位上的数字为1，则第i位上可能出现1的次数不仅受更高位决定，还受低位决定，count += 高位数 * 10(i-1) + (低位数+1)。
	*	3. 如果第i位上的数字大于1，则第i位上可能出现1的次数仅由更高位决定，count += (高位数+1) * 10^(i-1)。
	*/
public:
	int NumberOf1Between1AndN_Solution(int n) {
		if (n == 0) return 0;
		int count = 0, num = n, bit = 1;
		while (num) {
			if (num % 10 > 1)
				count += (num / 10 + 1) * pow(10, bit - 1);
			else if (num % 10 == 1)
				count += ((num / 10 * pow(10, bit - 1)) + (1 + n % (int)pow(10, bit - 1)));
			else
				count += num / 10 * pow(10, bit - 1);
			num /= 10;
			bit++;
		}
	}
};