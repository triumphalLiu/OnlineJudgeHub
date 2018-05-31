#include "global.h"

class Solution {
	/*Question 12 ��ֵ�������η�
	*��Ŀ����
	*	����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�����ݷ���: 2^10 = 1*2^10 = 1*4^5 = 4*4^4 = 4*16^2 = ...
	*	��Ҫ�ĳ˷������������exponent�Ķ���������λ��
	*	Hint:���ڷǸ������ж���ż�Ե���Ѱ취�� (n & 1) true=������false=ż����
	*/
public:
	double Power(double base, int exponent) {
		if (!exponent) return 1;
		long long exp = (long long)(exponent < 0 ? -exponent : exponent);
		double result = 1;
		while (exp) {
			if (exp & 1) {
				result *= base;
			}
			base *= base; 
			exp >>= 1;
		}
		return exponent < 0 ? 1 / result : result;
	}
};