#include "global.h"

class Solution {
	/*Question 30 连续子数组的最大和
	*题目描述
	*	在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
	*	但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
	*	例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	时间复杂度O(n)，如果加了一个数之后判断，总和变为负数，则认为上一个数对接下来的计算都没有帮助。
	*	则从当前数重新开始计算，并将总和置为0+当前数。
	*	每遍历一个数，都把当前的值和当前的最大值进行对比，取最大值保存。
	*/
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0) return 0;
		int returnNum = INT_MIN, currSum = 0;
		for (int i = 0; i < array.size(); ++i) {
			if (currSum >= 0)
				currSum += array[i];
			else
				currSum = array[i];
			if (currSum > returnNum) {
				returnNum = currSum;
			}
		}
		return returnNum;
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> arr = { 6,-3,-2,7,-15,1,2,2 };
		cout << FindGreatestSumOfSubArray(arr) << endl;
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}