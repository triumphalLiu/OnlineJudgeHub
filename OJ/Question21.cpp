#include "global.h"

class Solution {
	/*Question 21 ջ��ѹ�롢��������
	*��Ŀ����
	*	���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
	*	��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
	*	��ע�⣺���������еĳ�������ȵģ�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�½�һ��ջ�ṹ������popV��˳����ģ��������̡�
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