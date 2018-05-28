#include "global.h"

class Solution {
	/*Question 13 调整数组顺序使奇数位于偶数前面
	*题目描述
	*	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
	*	使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	空间换时间，创建一个新vector容器，遍历array，如果是偶数，则放入新容器中并在array中删除；
	*	遍历完成后，将两个容器合并。复杂度O(n)，最好情况循环n次，最差情况需要2n次;
	*/
public:
	void reOrderArray(vector<int> &array) {
		vector<int> evenNums;
		while(array.empty() == false) {
			if (array[0] % 2 == 0) {
				evenNums.push_back(array[0]);
				array.erase(array.begin());
			}
		}
		for (int i = 0; i < evenNums.size(); ++i)
			array.push_back(evenNums[i]);
	}
};