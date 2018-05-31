#include "global.h"

class Solution {
	/*Question 5 ������ջʵ�ֶ���
	*��Ŀ����
	*	������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	������Ҫpushʱ��һ��ջ������˳��ѹջ���棻
	*	������Ҫpopʱ���ó�stack1�����������ʱ����stack1����ȫ����ջ����ѹջ��stack2����ʱstack2����ԭ����stack1������stack2.top��Ϊ����Ȼ���ʣ�µ����·Ż�stack1.
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