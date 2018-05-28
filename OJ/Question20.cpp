#include "global.h"

class Solution {
	/*Question 20 ����min������ջ
	*��Ŀ����
	*	����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��������ջ��һ�������������ݣ�һ������������С��ֵ��
	*	���磺��������Ϊ2,3,1,4,0������ջΪ2,3,1,4,0����СջΪ2,2,1,1,0
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