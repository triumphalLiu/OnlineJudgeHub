#include "global.h"

class Solution {
	/*Question 45 翻转单词顺序列
	*题目描述
	*	有一副扑克牌，多出两个大小王，大小王(0)可以看成任何数字,并且A看作1,J为11,Q为12,K为13，判断五张牌是不是顺子。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	先对这五个数进行排序，统计0的个数，将非零数和下一个数字进行对比：
	*	如果相等，一定不是顺子；如果0的个数减去两数之顺子差（11和13的顺子差为1，11和12顺子差为0）是负数，（即所有王都变完了还是不能组成顺子），那么一定不是顺子。
	*	否则就是顺子。
	*/
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0) return false;
		sort(numbers.begin(), numbers.end());
		int zeroCount = 0, lastNum = -1;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == 0)
				++zeroCount;
			else if (lastNum == -1)
				lastNum = numbers[i];
			else {
				if (lastNum == numbers[i])
					return false;
				zeroCount -= (numbers[i] - lastNum - 1);
				lastNum = numbers[i];
				if (zeroCount < 0)
					return false;
			}
		}
		return true;
	}

	/*Use For Debug*/
	int Debug() {
		cout << IsContinuous({ 0,3,5,7,0 }) << endl;
		return 0;
	}
};

int main() {
	Solution s;
	return s.Debug();
}