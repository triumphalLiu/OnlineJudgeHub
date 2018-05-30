#include "global.h"

class Solution {
	/*Question 33 ����
	*��Ŀ����
	*	��ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7�� 
	*	ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
	*	ʱ�����ƣ�1�� �ռ����ƣ�32768K
	*˼·����
	*	ʹ��set�����ݽṹ�������������ֱ���ź����ҿ��Է�ֹ���ظ�������
	*	�ӵ�һ������ʼ��ÿһ��ѭ��������ǰ����x��2*x,3*x,5*x����set��Ȼ��ȡ��һ����Ϊ��һ���������Դ�����ֱ����n������ʱ�临�Ӷ�O(n)��
	*/
public:
	int GetUglyNumber_Solution(int index) {
		if (index == 0) return 0;
		long long uglyNumber = 1;
		set<long long> uglyNumbers;
		for (int i = 1; i < index; ++i) {
			uglyNumbers.insert(uglyNumber * 2);
			uglyNumbers.insert(uglyNumber * 3);
			uglyNumbers.insert(uglyNumber * 5);
			uglyNumber = *(uglyNumbers.begin());
			uglyNumbers.erase(uglyNumbers.begin());
		}
		return (int)uglyNumber;
	}

	/*Use For Debug*/
	int Debug() {
		cout << GetUglyNumber_Solution(2000) << endl;
		return 0;
	}
};