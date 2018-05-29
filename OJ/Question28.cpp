#include "global.h"

class Solution {
	/*Question 28 数组中出现次数超过一半的数字
	*题目描述
	*	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	*	例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	既然有数字出现的次数超过一半，那么可以删除任意两个不同的数字，直到最后全部删完(不存在)或者全部剩余一些相同的数字即为所求。
	*	Note:当只有一个数字或者数组为空的时候应该做出特殊处理。当数组为奇数且最后只有最后一位非0的时候也应特殊处理。
	*/
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0) return 0;
		if (numbers.size() == 1) return numbers[0];
		for (int i = 1; i < numbers.size(); ++i) {
			if (numbers[i] == 0)
				continue;
			if (numbers[i] != numbers[i - 1] && numbers[i - 1] != 0) {
				numbers[i] = numbers[i - 1] = 0;
			}
		}
		for (int i = 0; i < numbers.size(); ++i) {
			if ((numbers.size() & 1) && i == numbers.size() - 1)
				return 0;
			if (numbers[i] != 0)
				return numbers[i];
		}
		return 0;
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> nums = { 1,2,3,2,2,2,5,4,2 };
		vector<int> nums2 = { 2,2,2,2,2,2,2,2,2 };
		vector<int> nums3 = { 1,2,3,2,4,2,5,2,3 };
		cout << MoreThanHalfNum_Solution(nums3) << endl;
		return 0;
	}
};