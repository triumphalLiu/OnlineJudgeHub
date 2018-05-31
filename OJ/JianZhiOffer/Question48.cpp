#include "global.h"

class Solution {
	/*Question 48 ���üӼ��˳����ӷ�
	*��Ŀ����
	*	дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�������У������λ�ļӷ�����a���b����λֵ����(a��b)<<1��
	*	�����λ����0����������������������������������ظ��������衣
	*/
public:
	int Add(int num1, int num2) {
		while (true) {
			int sum = num1 ^ num2;
			int carry = (num1 & num2) << 1;
			if (carry == 0)
				return sum;
			num1 = sum;
			num2 = carry;
		}
	}
};