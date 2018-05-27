#include "global.h"

class Solution {
	/*Question 8
	*��Ŀ����
	*	һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��̬�滮��������쳲��������С�
	*	���ɣ�F(n) = F(n-2) + F(n-1);  ���������F(0) = 0; F(1) = 1; F(2) = 2;
	*/
public:    
	int jumpFloor(int number) {
		if (number <= 2)
			return number;
		int before = 1, after = 2;
		number -= 1;
		while (--number) {
			after += before;
			before = after - before;
		}
		return after;
	}
};