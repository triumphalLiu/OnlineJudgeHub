#include "global.h"

class Solution {
	/*Question 64 滑动窗口的最大值
	*题目描述
	*	给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
	*	那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
	*	{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	首先对于窗口长度大于整个数组的情况：直接找到最大值返回即可。
	*	正常情况，设置两个指针，一个指向窗口左侧，一个指向窗口右侧，先找到第一次的最大值。
	*	随后窗口滑动，检查滑动前最左侧的值是否等于最大值，如果是，重新选取最大值；然后将最大值和滑动后的右侧指针的值进行对比，取大的。
	*/
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)	{
		if (size == 0 || num.size() < size) return {};
		else if (num.size() == size) {
			int max = INT_MIN;
			for (int i = 0; i < num.size(); ++i)
				if (num[i] > max)
					max = num[i];
			return { max };
		}
		else {
			vector<int> result;
			int left = 0, right = size - 1, currMax = INT_MIN;
			/* 找到第一次的最大值 */
			for (int i = left; i <= right; ++i)
				if (num[i] > currMax)
					currMax = num[i];
			result.push_back(currMax);
			/* 窗口进行滑动 */
			while (true) {
				if (num[left] == currMax) {
					currMax = INT_MIN;
					for (int i = left + 1; i <= right; ++i)
						if (num[i] > currMax)
							currMax = num[i];
				}
				++left; ++right;
				if (right == num.size()) break;
				if (num[right] > currMax)
					currMax = num[right];
				result.push_back(currMax);
			}
			return result;
		}
	}
};