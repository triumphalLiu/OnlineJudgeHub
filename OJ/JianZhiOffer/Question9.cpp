#include "global.h"

class Solution {
	/*Question 9 ��̬��̨��
	*��Ŀ����
	*	һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��̬�滮��������쳲��������С�
	*	���ɣ�F(n) = F(n-1) + F(n-2) + ... + F(1) + 1;  ���������F(1) = 1; F(2) = 2;
	*	���׷�������һ���ȱ����У���2Ϊ���ȡ�
	*/
public:
	int jumpFloorII(int number) {
		if (number <= 2)
			return number;
		int sum = 1;
		while (--number)
			sum *= 2;
		return sum;
	}
};