#include "global.h"

class Solution {
	/*Question 11 ��������1�ĸ���
	*��Ŀ����
	*	����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	��������n���ұߵ�1���ں�n-1���а�λ������󣬻���0������ܽ��м���ѭ�������м���1
	*/
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n) {
			n &= n - 1;
			++count;
		}
		return count;
	}
};