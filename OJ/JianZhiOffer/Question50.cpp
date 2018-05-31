#include "global.h"

class Solution {
	/*Question 50 数组中重复的数字
	*题目描述
	*	在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
	*	例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	使用一个bool数组，先全部置为false，然后遍历数组，如果：
	*	1、不属于0到n-1的范围内，则返回false；
	*	2、没有访问过，则把上述bool数组该位设为true；
	*	3、访问过了，则保存这个重复数字并返回true。
	*	4、遍历完成了，则表示没有重复数，返回false；
	*/
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0 || numbers == NULL)
			return false;
		bool *visited = new bool[length];
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < length; ++i) {
			if (numbers[i] < 0 || numbers[i] >= length)
				return false;
			if (visited[numbers[i]] == false)
				visited[numbers[i]] = true;
			else {
				duplication[0] = numbers[i];
				delete[]visited;
				return true;
			}
		}
		delete[]visited;
		return false;
	}
};