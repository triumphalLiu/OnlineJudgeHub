#include "global.h"

class Solution {
	/*Question 47 ��1+2+3+...+n
	*��Ŀ����
	*	��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	�Զ���ʽһ������һ��bool���飨gcc���ã�����׼c++�����ã���Ϊ������̬���鲻��ʹ�ó�������ʹ��sizeof�ؼ���ʵ�ֳ˷����㡣
	*	������ʽ����ͨ���߼���/�߼���Ķ�·��ֵ����ʵ��if�Ĺ�����ֹ�ݹ�;
	*/
public:
	int Sum_Solution(int n) {
		int sum = n;
		sum && (sum += (Sum_Solution(n - 1)));
		return sum;
	}
};