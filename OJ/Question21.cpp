#include "global.h"

class Solution {
	/*Question 21 栈的压入、弹出序列
	*题目描述
	*	输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
	*	例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
	*	（注意：这两个序列的长度是相等的）
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	新建一个栈结构，按照popV的顺序来模拟这个过程。
	*/
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int len = pushV.size();
		stack<int> simStack;
		int indexPopV = 0, indexPushV = 0;
		simStack.push(pushV[0]);
		for (int i = 0; i < len; ++i) {
			int currentPopNum = popV[indexPopV];
			if (currentPopNum == simStack.top()) {
				simStack.pop();
				++indexPopV;
			}
			else{
				if()
			}
		}
		return true;
	}
};