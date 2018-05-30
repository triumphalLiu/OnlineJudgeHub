#include "global.h"

class Solution {
	/*Question 33 丑数
	*题目描述
	*	把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
	*	习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	使用set的数据结构，插入数后可以直接排好序并且可以防止有重复的数。
	*	从第一个数开始，每一次循环都将当前丑数x的2*x,3*x,5*x插入set，然后取第一个数为下一个丑数，以此类推直到第n个数，时间复杂度O(n)。
	*/
public:
	int GetUglyNumber_Solution(int index) {
		if (index == 0) return 0;
		long long uglyNumber = 1;
		set<long long> uglyNumbers;
		for (int i = 1; i < index; ++i) {
			uglyNumbers.insert(uglyNumber * 2);
			uglyNumbers.insert(uglyNumber * 3);
			uglyNumbers.insert(uglyNumber * 5);
			uglyNumber = *(uglyNumbers.begin());
			uglyNumbers.erase(uglyNumbers.begin());
		}
		return (int)uglyNumber;
	}

	/*Use For Debug*/
	int Debug() {
		cout << GetUglyNumber_Solution(2000) << endl;
		return 0;
	}
};