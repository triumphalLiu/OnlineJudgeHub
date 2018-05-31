#include "global.h"

class Solution {
	/*Question 5 用两个栈实现队列
	*题目描述
	*	用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
	*	时间限制：1秒 空间限制：32768K
	*思路描述
	*	当队列要push时，一个栈用来按顺序压栈保存；
	*	当队列要pop时（拿出stack1最里面的数字时），stack1的数全部出栈并都压栈进stack2，此时stack2就是原来的stack1的逆序，stack2.top即为所求，然后把剩下的重新放回stack1.
	*/
public:
	void push(int node) {
		stack1.push(node);
	}
	int pop() {
		while (stack1.empty() == false) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int result = stack2.top();
		stack2.pop();
		while (stack2.empty() == false) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return result;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};