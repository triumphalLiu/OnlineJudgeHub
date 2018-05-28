#include "global.h"

class Solution {
	/*Question 20 包含min函数的栈
	*题目描述
	*	定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	定义两个栈，一个用来储存数据，一个用来储存最小的值。
	*	例如：输入数据为2,3,1,4,0；数据栈为2,3,1,4,0；最小栈为2,2,1,1,0
	*/
public:
	stack<int> dataStack;
	stack<int> minStack;
	void push(int value) {
		dataStack.push(value);
		if (minStack.empty() || value <= minStack.top())
			minStack.push(value);
		else
			minStack.push(minStack.top());
	}
	void pop() {
		dataStack.pop();
		minStack.pop();
	}
	int top() {
		return dataStack.top();
	}
	int min() {
		return minStack.top();
	}
};