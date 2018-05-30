#include "global.h"

class Solution {
	/*Question 41 和为S的连续正数序列
	*题目描述
	*	输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序排列。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	解法1：直接解方程，i从0到sum/2，求n：((i+1)+(i+n))*n/2=s，然后判断n是否是整数，如果是，则把i+1到i+n都加进结果数组中。由于有大量浮点数运算，所以不是很好的办法。
	*	解法2：双指针解法，一个指针指向左侧，一个指针指向右侧，求和，如果小于sum，则右侧指针加一，否则左侧指针加一,如果等于sum，则保存left到right这些数。
	*/
public:
	vector<vector<int> > FindContinuousSequence_Way1(int sum) {
		vector<vector<int> > result;
		for (int i = 0; i < sum/2; ++i) {
			double n = ((sqrt(4 * i*(i + 1) + 1 + 8 * sum) - (2 * i + 1)) / 2);
			if (n - (int)n < 0.000001) {
				vector<int> temp;
				for (int j = i + 1; j < i + 1 + (int)n; ++j)
					temp.push_back(j);
				result.push_back(temp);
			}
		}
		return result;
	}

	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > result;
		int left = 1, right = 2;
		while (right < sum) {
			int size = right - left + 1;
			int total = (left + right) * size / 2;
			if (total < sum)
				right += 1;
			else if (total > sum)
				left += 1;
			else {
				vector<int> temp;
				for (int i = left; i <= right; ++i)
					temp.push_back(i);
				result.push_back(temp);
				left += 1;
			}
		}
		return result;
	}

	/*Use For Debug*/
	int Debug() {
		vector<vector<int> > result = FindContinuousSequence(100);
		for (int i = 0; i < result.size(); ++i) {
			for (int j = 0; j < result[i].size(); ++j) {
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}