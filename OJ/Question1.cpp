#include "global.h"

class Solution {
	/*Question 1
	*题目描述
	*	在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	*   请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	从右上角开始检查，如果小于目标，就放弃这一行；如果大于目标，就放弃这一列；然后对缩小后的矩阵进行遍历。
	*/
public:
	bool Find(int target, vector<vector<int> > array) {
		int col = array[0].size();
		for (int i = 0; i < array.size(); ++i) {
			for (int j = col - 1; j >= 0; --j) {
				if (array[i][j] == target)
					return true;
				else if (j == col - 1 && array[i][j] < target)
					break;
				else if (j == col - 1 && array[i][j] > target)
					j = (col -= 1);
			}
		}
		return false;
	}
};