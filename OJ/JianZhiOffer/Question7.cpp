#include "global.h"

class Solution {
	/*Question 7 쳲���������
	*��Ŀ����
	*	��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�(n<=39)
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ֱ�Ӱ�˳�����㣬���ҽ����浱ǰ����һ����ֵ��//�ݹ���д����ظ����㡣
	*	Note:ţ�����Ľ�ָoffer���棬FibonacciArr[0] = 0, FibonacciArr[1] = FibonacciArr[2] = 1��
	*/
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		int before = 0, after = 1;
		while (--n) {
			after += before;
			before = after - before;
		}
		return after;
	}
};