#include "global.h"

class Solution {
	/*Question 37 数字在排序数组中出现的次数
	*题目描述
	*	统计一个数字在排序数组中出现的次数。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	二分查找，找出k+1和k应该插入的位置（若有相同数字，则插在相同数字的最前面），然后相减即可。
	*/
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() == 0) return 0;
		return binarySearch(data, k + 1) - binarySearch(data, k);
	}

	int binarySearch(vector<int> data, int num) {
		int min = 0, max = data.size() - 1;
		while (min <= max) {
			int mid = ((min + max) >> 1);
			if (data[mid] < num)
				min = mid + 1;
			else if (data[mid] >= num)
				max = mid - 1;
		}
		return min;
	}

	/*Use For Debug*/
	int Debug() {
		cout << GetNumberOfK({ 1,2,3,3,3,4 }, 0) << endl;
		return 0;
	}
};