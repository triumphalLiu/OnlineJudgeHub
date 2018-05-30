#include "global.h"

class Solution {
	/*Question 42 和为S的两个数字
	*题目描述
	*	输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	双指针法的变式，左指针指向左侧，右指针指向右侧；如果和相等，则直接返回（因为一定是最小的乘积）；如果大于sum，则右指针左移；如果小于sum，则左指针右移；直到两指针交汇，返回<空>。
	*/
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.size() < 2) return {};
		int left = 0, right = array.size() - 1;
		vector<int> result;
		while (left != right) {
			int value = array[left] + array[right];
			if (value == sum) {
				result.push_back(array[left]);
				result.push_back(array[right]);
				break;
			}
			else if (value > sum) {
				right--;
			}
			else if (value < sum) {
				left++;
			}
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		vector<int> temp = FindNumbersWithSum({1,2,3,4,5,6,7,8}, 8);
		cout << temp[0] << " " << temp[1] << endl;
		return 0;
	}
};